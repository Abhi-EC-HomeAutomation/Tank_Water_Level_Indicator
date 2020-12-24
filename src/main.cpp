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
int sonarValue = 0; // for storing raw readings from the sensor


//defining empty functions
int getWaterLevel();


void setup() {
  Serial.begin(9600);
  Serial.println();
}

void loop() {

  sonarValue = getWaterLevel();
  Serial.println(sonarValue);

  delay(1000);
}

int getWaterLevel() {
  return sonar.ping_cm();
}