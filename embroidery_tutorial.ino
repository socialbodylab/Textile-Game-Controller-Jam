/*******
Code for the Textile Game Controller Jam by Social Body Lab, Dames Making Game, & Game Play Lab. 
May 30, 2020 - June 6, 2020. 

This is code follows along the "How to Embroider an E-Textile Capacitve Sensor" here: https://youtu.be/lxuEnd14fhU  

The code contains 2 capactive touch sensors. 

   Circuit Playground Library: 
   https://learn.adafruit.com/circuit-playground-lesson-number-0

*********/
/**Must include the Adafruit_CircuitPlayground.h**/
#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   25 //increase this number if unintentional keypresses occur and 

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

  if (capButton(2)) {// if the 2 pin is activated through capactive touch
    Serial.println("Pin 2 activated - light bulb activated");
    for (int i = 0 ; i < 10; i++) {// loop through all of the LEDs and turn them on
      CircuitPlayground.setPixelColor(i, 200, 100, 0); // yellow colour
    }

  } else {  // if pin 2 is not activated turn off all of the LEDS

    CircuitPlayground.clearPixels();
  }

  if (capButton(9)) { // if the 9 pin is activated through capactive touch
    Serial.println("Pin 9 activated - LED bulb activated");
 
    for (int i = 0 ; i < 10; i++) { // loop through all of the LEDs and turn them on
      CircuitPlayground.setPixelColor(i, 255, 0, 200); // pink colour
    }

  } else { // if pin 9 is not activated turn off all of the LEDS

    CircuitPlayground.clearPixels();
  }
}
