/*******
Code for the Textile Game Controller Jam by Social Body Lab, Dames Making Game, & Game Play Lab. 
May 30, 2020 - June 6, 2020. 

This is code follows along the "How to Felt an E-Textile Capacitve Sensor" here: https://youtu.be/NowvCFEpItk 

The code contains 2 capactive touch sensors. 

   Circuit Playground Library: 
   https://learn.adafruit.com/circuit-playground-lesson-number-0

*********/
/**Must include the Adafruit_CircuitPlayground.h**/
#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   65 //increase this number if unintentional keypresses occur and 

/**Setting up the ability to read capactive touch on the Circuit Playgroun**/
/**If using capactive touch, you must include this line in your code!**/
boolean capButton(uint8_t pad) {
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;
  } else {
    return false;
  }
}

void setup() {
  Serial.begin(9600); // Starting the serial monitor
  CircuitPlayground.begin(); // Initializing the Circuit Playground
}

void loop() {

  if (capButton(6)) { // if the 6 pin is activated through capactive touch
    Serial.println("Pin 6 activated - bottom of the cone");
    
    for (int i = 0 ; i < 10; i++) {// loop through all of the LEDs and turn them on
      CircuitPlayground.setPixelColor(i, 0, 75, 255); // light blue colour
    }

  } else { // if pin 6 is not activated turn off all of the LEDS
    CircuitPlayground.clearPixels();
  }

    if (capButton(9)) {// if the 9 pin is activated through capactive touch
    Serial.println("Pin 9 activated - top of the cone");
    
    for (int i = 0 ; i < 10; i++) { // loop through all of the LEDs and turn them on
      CircuitPlayground.setPixelColor(i, 255, 0, 200); // light pink 
    }

  } else { // if not turn off all of the LEDS
    CircuitPlayground.clearPixels();
  }

}
