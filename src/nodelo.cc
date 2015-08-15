
#include <node.h>

#define _WIN32 1
#define _USING_UV_SHARED 1
#ifdef BUILDING_UV_SHARED
#undef BUILDING_UV_SHARED
#endif

#include <uv.h>

#include <sstream>
#include <iostream>
#include <unistd.h> //sleep, usleep, TODO win32 with CreateWaitableTimer hack

#include "nan.h"

using namespace std;
using namespace v8;


namespace nodelo {
//TODO uv_timer
//TODO formatted result
//TODO own uv_loop
//TODO histogram
//TODO merge again with nodepa


static unsigned int loop_interval_ms = 5;
static uint delay_treshold_ms = 40;


struct delay_t {
  uint64_t start_time;
  uint64_t end_time;
  string reason;
  uint duration;
  uint handlers;
} gc_delay, loop_delay;


void handlerWalker(uv_handle_t* handle, void* delay) {
    ((delay_t*)delay)->handlers++;
}


void logPause(delay_t delay) {
	if (delay.duration >= delay_treshold_ms) {

		//calculate handlers
		delay.handlers = 0;
	  uv_walk(uv_default_loop(), handlerWalker, &delay);

    //print result
		cout << "handlers: " << delay.handlers <<  \
		", start: " << delay.start_time/1000 << ", ";
		if(delay.end_time > 0) {
		  cout << "freezed  for";
		} else {
		  cout << "freezing for";
		}
		cout << " " << delay.duration << " ms due to " \
		<< delay.reason << endl;
  }
}


void watchEventLoop(void *n) {
    unsigned int usec = *(unsigned int *)n * 1000;
    loop_delay.reason = "JS";
    uint64_t loop_timeout;
    uint64_t loop_time;
    uint last_logged;

    while (true) {

        //check if GC not running
        if(gc_delay.start_time == 0) {
          loop_time = uv_now(uv_default_loop());
          loop_timeout = uv_backend_timeout(uv_default_loop());

          //end of freeze, log it and reset counters
          if(loop_delay.duration > 0
            && loop_time != loop_delay.start_time
            ) {
              loop_delay.end_time = loop_time;
              logPause(loop_delay);

              loop_delay.duration = 0;
              loop_delay.end_time = 0;
              last_logged = 0;
          }

          //still freeze
          if(
            (loop_delay.duration - last_logged) > 500
            && loop_delay.duration > 0
            && loop_time == loop_delay.start_time
            ) {
              logPause(loop_delay);
              last_logged = loop_delay.duration;
          }

          //there is no timer and still running last frame
          if(loop_timeout == 0
            && loop_time == loop_delay.start_time
            ) {
              loop_delay.duration += usec / 1000;
          }

          //new frame, update start time
          if(loop_time != loop_delay.start_time) {
            loop_delay.start_time = loop_time;
            loop_delay.duration = 0;
            loop_delay.end_time = 0;
            last_logged = 0;
          }

          }
        usleep(usec);
    }
}

static NAN_GC_CALLBACK(startGC) { //v8::GCType type, v8::GCCallbackFlags flags
    gc_delay.start_time = uv_hrtime();
    gc_delay.end_time = 0;
    gc_delay.duration = 0;
    gc_delay.reason = "";
}


static NAN_GC_CALLBACK(stopGC) { //v8::GCType type, v8::GCCallbackFlags flags
    gc_delay.end_time = uv_hrtime();
    gc_delay.duration = (gc_delay.end_time - gc_delay.start_time) / 1000000;
    if(type == 1) {
      gc_delay.reason = "Scavenge";
    } else {
      gc_delay.reason = "Mark-sweep";
    }
    logPause(gc_delay);
    gc_delay.start_time = 0;
}


static NAN_METHOD(StartWatch) {
    uv_thread_t async;
    NanScope();

    NanAddGCPrologueCallback(startGC);
    NanAddGCEpilogueCallback(stopGC);

    assert(0 == uv_thread_create(&async, watchEventLoop, &loop_interval_ms));

    NanReturnValue(NanUndefined());
}


#ifdef __cplusplus
extern "C" void
#endif
init(Handle<Object> exports) {

    exports->Set(NanNew("watch"),
      NanNew<FunctionTemplate>(StartWatch)->GetFunction());


}
NODE_MODULE(nodelo, init)
} //namespace nodelo