# Tank_Water_Level_Indicator

The final version of this project aims to create a level indicator system for water in the overhead tank and start/stop the motor as per set level. Also messaging system will be implemented to send the status to central server which will also send command to start/stop the motor remotely. 

Some more features will be:
1. led indicator for different functions.
2. fail safe mechanism for stopping the motor to prevent water overflow in case of sensor faiilure.
3. distributing tasks among the cores so that the sensor readings are not interrupted.

![Alt text](Circuit_Diagram.jpg?raw=true "Title")

##Components needed:
1. ESP32 Dev board
2. JSN SR04T module