var express = require('express');
var bodyParser = require('body-parser');
var fs = require('fs');

var app = express();

app.use(bodyParser.json());

app.use(bodyParser.urlencoded({extend: false}));

var routes = require('./routes.js')(app, fs);

var port = process.env.PORT || 3000;
app.listen(port);
console.log('Serving running on port ' + port);

app.get('/', function(request, respond) {
    respond.send('Hello, world!');
})