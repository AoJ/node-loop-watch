# Node loop watch

### Experiment, don't use it!


## Usage

	npm install nodelo
	npm install express
	node node_modules/nodelo/example.js &
	ab -c 20 -n 20 localhost:11111/slow


example output

	This is ApacheBench, Version 2.3 <$Revision: 1604373 $>
	Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/
	Licensed to The Apache Software Foundation, http://www.apache.org/

	Benchmarking localhost (be patient)...request time 17188
	request time 17554
	handlers: 29, start: 390761, freezing for 505 ms due to JS
	handlers: 29, start: 390761, freezing for 1010 ms due to JS
	handlers: 29, start: 390761, freezing for 1515 ms due to JS
	handlers: 29, start: 390761, freezing for 2020 ms due to JS
	handlers: 29, start: 390761, freezing for 2525 ms due to JS
	handlers: 29, start: 390761, freezing for 3030 ms due to JS
	handlers: 29, start: 390761, freezing for 3535 ms due to JS
	handlers: 29, start: 390761, freezing for 4040 ms due to JS
	handlers: 29, start: 390761, freezing for 4545 ms due to JS
	handlers: 29, start: 390761, freezing for 5050 ms due to JS
	handlers: 29, start: 390761, freezing for 5555 ms due to JS
	handlers: 29, start: 390761, freezing for 6060 ms due to JS
	handlers: 29, start: 390761, freezing for 6565 ms due to JS
	handlers: 29, start: 390761, freezing for 7070 ms due to JS
	handlers: 29, start: 390761, freezing for 7575 ms due to JS
	handlers: 29, start: 390761, freezing for 8080 ms due to JS
	handlers: 29, start: 390761, freezing for 8585 ms due to JS
	handlers: 29, start: 390761, freezing for 9090 ms due to JS
	handlers: 29, start: 390761, freezing for 9595 ms due to JS
	handlers: 29, start: 390761, freezing for 10100 ms due to JS
	handlers: 29, start: 390761, freezing for 10605 ms due to JS
	handlers: 29, start: 390761, freezing for 11110 ms due to JS
	handlers: 29, start: 390761, freezing for 11615 ms due to JS
	handlers: 29, start: 390761, freezing for 12120 ms due to JS
	handlers: 29, start: 390761, freezing for 12625 ms due to JS
	handlers: 29, start: 390761, freezing for 13130 ms due to JS
	handlers: 29, start: 390761, freezing for 13635 ms due to JS
	handlers: 29, start: 390761, freezing for 14140 ms due to JS
	request time 16825
	handlers: 29, start: 390761, freezed  for 14615 ms due to JS
	handlers: 29, start: 390778, freezing for 505 ms due to JS
	handlers: 29, start: 390778, freezing for 1010 ms due to JS
	handlers: 29, start: 390778, freezing for 1515 ms due to JS
	handlers: 29, start: 390778, freezing for 2020 ms due to JS
	handlers: 29, start: 390778, freezing for 2525 ms due to JS
	handlers: 29, start: 390778, freezing for 3030 ms due to JS
	handlers: 29, start: 390778, freezing for 3535 ms due to JS
	handlers: 29, start: 390778, freezing for 4040 ms due to JS
	handlers: 29, start: 390778, freezing for 4545 ms due to JS
	handlers: 29, start: 390778, freezing for 5050 ms due to JS
	handlers: 29, start: 390778, freezing for 5555 ms due to JS
	handlers: 29, start: 390778, freezing for 6060 ms due to JS
	handlers: 29, start: 390778, freezing for 6565 ms due to JS
	...
