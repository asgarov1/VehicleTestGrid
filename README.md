# Vehicle-Test-Grid
 by Javid Asgarov
  & Aaron Nietgen

This is a little game where there is a server, display service and up to 26 clients that can connect to the server.
Each client chooses a letter with which he will be identified. Following this he can move around the map that will be shown in display service until he hits something. Then he disconnects.

<h4>Usage:</h4> 
first run <b>cmake ./</b> and then <b>make all</b> <br>
after that you can run <br>
<ul>
<li>1 server: 	       <b>./gridserver -x NUM -y NUM</b></li>
<li>1 display service: <b>./griddisplay</b></li>
<li>up to 26 clients:  <b>./vehicleclient CHAR</b></li>
</ul>
<br>

By default SERVER will run on PORT 5000, you can change PORT NUMBER in SERVER_SETTINGS.h

<br>
I have used socket programming because I find it to be a better solution for this task (server - multiple clients communicaiton), 
display service is getting the information from server via a pipe. 
