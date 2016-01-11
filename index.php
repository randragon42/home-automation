<!DOCTYPE html>
<html>

<head>
<title>Raspberry Pi Home Automation</title>
</head>

<body>
<h1>Raspberry Pi Home Automation</h1>
<p>Turn lights on and off</p><br>
<p id="READY">Not yet connected.<p>

<br>

<h4>Outlet 1</h4>
<button type="button" onclick="outlet1_on()"><img src="images/on_button.png" height="142"width="142"></button>
<button type="button" onclick="outlet1_off()"><img src="images/off_button.jpg" height="142"width="142"></button>

<h4>Outlet 5</h4>
<button type="button" onclick="outlet5_on()"><img src="images/on_button.png" height="142"width="142"></button>
<button type="button" onclick="outlet5_off()"><img src="images/off_button.jpg" height="142"width="142"></button>
<br>

<?php
function outlet5_on(){
	exec("./code/remote 5 ON");
}
function outlet5_off(){
	exec("./code/remote 5 OFF");
}

?>

<script>
//function WebSocket(){
//These functions don't work...
//Will need to do something with nodeJS probably...
/*function outlet1_on(){
	//var child_process = require('child_process');
	//child_process.exec("sudo ./code/remote 5 ON");
}

function outlet1_off(){
	//var child_process = require('child_process');
	//child_process.exec("sudo ./code/remote 5 OFF");
}*/

//WebSocket();
</script>


</body>


</html>
