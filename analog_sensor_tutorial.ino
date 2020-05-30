/*******
  Code for the Textile Game Controller Jam by Social Body Lab, Dames Making Game, & Game Play Lab.
  May 30, 2020 - June 6, 2020.

  This is code follows along the "How to Make an E-Textile Analog Sensor" here: https://youtu.be/tA37mGEnPes

  The code contains 1 analog sensor. The amount of lights that turn on is related to the reading of the pressure sensor. 
  If high force is applied onto the sensor, the most of the lights will turn on. If light pressure is applied, only a few will turn on. 
   
   Circuit Playground Library:
   https://learn.adafruit.com/circuit-playground-lesson-number-0

*********/

/**Must include the Adafruit_CircuitPlayground.h**/
#include <Adafruit_CircuitPlayground.h>

int analogPin = 11;    // select the input pin for the potentiometer
int analogValue;  // variable to store the value coming from the sensor
int analogMin = 1023;        // minimum sensor value
int analogMax = 0;    // maximum sensor vlalue
int colour;     // value for brightness

void setup() {

  Serial.begin(9600); // Starting the serial monitor

  CircuitPlayground.begin(); // Initializing the Circuit Playground

  /**Calibrating the values for the analog sensor**/
  /**Press as hard as your can on the analog sensor for 3 seconds and then let it rest for two seconds
    This snippet of code finds the highest value and lowest value from the analog sensor**/

  while (millis() < 5000) {
    analogValue = analogRead(analogPin); // Read all of the incoming analog values
    Serial.println(analogValue); // print out these values

    // record the maximum sensor value
    if (analogValue > analogMax) { // if the value that is read is higher than the last highest value
      analogMax = analogValue; // analogMax is now the highest value that is read
    }

    // record the minimum sensor value
    if (analogValue < analogMin) { // if the value that is read is lower than the last lowest value
      analogMin = analogValue; // analogMin is now the lowest value that is read
    }
  }

}

void loop() {

  analogValue = analogRead(analogPin); // Read the Analog Sensor

  colour =  map(analogValue, analogMin, analogMax, 0, 250); // Map the incoming value. If it is near the maxium value that was calibrated, the variable colour will be assigned a number close to 250.
  int len = colour / 25; // The highest value is 250, and there are 10 pixels. Dividing by 25 will give us a value between 1-10.
  Serial.println(len); // print out the value of len

  if (len > 1) { // if the sensor is activated
    for (int i = 0; i < len; i++) { // loop through until how "hard" the user was pushing.
      CircuitPlayground.setPixelColor(i, 255, 255, 255); // set the lights to white
      delay(50); // delay allows us to see the LEDs light up individually
    }
  } else { // loop backwards and decress
    for (int i = 10; i >= 0 ; i--) { // when the pressure is released, start from the highest number (9) and go to the lowest (0).
      CircuitPlayground.setPixelColor(i, 0, 0, 0);
      delay(50);  // delay allows us to see the LEDs turn off individually
    }
  }
}
