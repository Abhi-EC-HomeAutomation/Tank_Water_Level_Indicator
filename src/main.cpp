#include <Arduino.h>
#include <NewPing.h>

//Defining pin
//JSN-SR04T-2.0
#define TRIGGER_PIN 32    // Arduino pin tied to trigger pin on the ultrasonic sensor. --Orange
#define ECHO_PIN 33       // Arduino pin tied to echo pin on the ultrasonic sensor.  --Yellow

//defining constants
//JSN-SR04T-2.0
const int MAX_DISTANCE = 200; // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


//JSN-SR04T-2.0
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


//Variables
int sonarValue = 0; // for storing calculated readings from the sensor
int sonarValLast = 0;
int sonarValCurr = 0;
int changeLimit = 30; // original is 5
const int indexLimit = 10;
int readings[indexLimit];
int prevIndexReading = 0;
int totalVal = 0;
int avgVal = 0;
int indexNum = 0;
const int tankReadingAvg = 10;


//defining empty functions
int getWaterLevel();


void setup() {
  Serial.begin(9600);
  Serial.println();
}

void loop() {

  // fetching sonar value into variable
  sonarValue = getWaterLevel();
  Serial.println(sonarValue);

  // This line is optional
  delay(1000);
}

int getWaterLevel()
{
  sonarValLast = sonarValCurr;
  sonarValCurr = sonar.ping_cm(); //Get range in cm

  if (sonarValCurr <= 0) 
  {
    sonarValCurr = sonarValLast;
  }
  else if (abs(sonarValCurr - sonarValLast) > changeLimit)
  {
    if (sonarValCurr < sonarValLast)
    {
      sonarValCurr = sonarValLast - changeLimit;
    }
    else
    {
      sonarValCurr = sonarValLast + changeLimit;
    }
  }

  prevIndexReading = readings[indexNum];
  readings[indexNum] = sonarValCurr;

  totalVal = totalVal + (readings[indexNum] - prevIndexReading);
  return totalVal / tankReadingAvg;
}

