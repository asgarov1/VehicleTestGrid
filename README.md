# Vehicle-Test-Grid
 by Javid Asgarov
  & Aaron Nietgen

<h4>Usage:</h4> 
first run "make all" <br>
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
