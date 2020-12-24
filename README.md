# Tank Water Level Indicator

The final version of this project aims to create a level indicator system for water in the overhead tank and start/stop the motor as per set level. Also messaging system(MQTT) will be implemented to send the status to central server which will also send command to start/stop the motor remotely. 

Some more features will be:
1. led indicator for different functions.
2. fail safe mechanism for stopping the motor to prevent water overflow in case of sensor faiilure.
3. distributing tasks among the cores so that the sensor readings are not interrupted.

![Alt text](Circuit_Diagram.jpg?raw=true "Circuit diagram")

##Libraries used
1. [NewPing](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home) by Tim Eckel. For JSN SR04T.

##Components needed:
1. ESP32 Dev board
2. JSN SR04T module (i have used v2, no idea if v1 will work or not)

##Current Version functionality:
(branch:- "smoothening_sonar_reading")
In addition to previous version, here the code is changed to smooth out the spike in the reading by aggregating the readings and also dampen the changes in the reading. 
For example: if Ist aggregated value comes to 100 and the second comes to 60. Then the reading will not step down directly to 60 instead it will go downward step by step as per the parameter. This means if the parameter is set to 5 then instead of 60 the reading will go down to 95 then 90 then 85 and so on. This will help to minimise frequent starting and shutting the motor due to big changes in the reading. I have noticed that sometime abruptly sensor give reading as 0, so code if this happens then the previous calculated value will be used.


(previous version)
(branch:- "add_sonar")
This version will just recieve the signal from sonar module and display it on serial monitor.
