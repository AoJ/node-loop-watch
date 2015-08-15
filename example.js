var nodelo = require('./');
var express = require('express');
var app = express();

nodelo.watch();


function xxx() {
  var i = 0;
  for (var x = 0; x < 1e10; x++) {
    i += x;
  }
  return i;
}


app.get("/slow", function(req, res){
  var start = Date.now();
  data = "" + xxx();
  console.log("request time " + (Date.now() - start));
  res.status(200).send(data);
});


app.get("*", function(req, res){
  res.status(200).send("hello");
});

app.listen(11111);