var express = require("express");
var app = express();
var bodyParser = require('body-parser');
var errorHandler = require('errorhandler');
var methodOverride = require('method-override');
var hostname = process.env.HOSTNAME || 'localhost';
var port = 8080;

//adds nodemailer
var nodemailer = require('nodemailer'); 	

//transport service to authenticate
var transporter = nodemailer.createTransport({
 service: 'gmail',
 auth: {
        user: 'alexiadummyacct@gmail.com',
        pass: 'ame394ame394'
    }
});

//configuring details
const mailOptions = {
  from: 'alexiadummyacct@gmail.com', // sender address
  to: 'alexiadummyacct@gmail.com', // list of receivers
  subject: 'hello!!', // Subject line
  html: '<p>xoxo, gossip girl</p>'// plain text body
};

//sending mail
transporter.sendMail(mailOptions, function (err, info) {
   if(err)
     console.log(err)
   else
     console.log(info);
});



app.get("/", function (req, res) {
	//sending mail
	transporter.sendMail(mailOptions, function (err, info) {
	   if(err)
	     console.log(err)
	   else
	     console.log(info);
	});
	
    console.log("GET req arrived")
        res.send("hello world")
});

app.use(methodOverride());
app.use(bodyParser());
//app.use(express.static(__dirname + '/public'));
app.use(errorHandler());

console.log("Simple static server listening at http://" + hostname + ":" + port);
app.listen(port);