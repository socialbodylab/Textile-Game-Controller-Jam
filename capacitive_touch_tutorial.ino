/*******
Code for the Textile Game Controller Jam by Social Body Lab, Dames Making Game, & Game Play Lab. 
May 30, 2020 - June 6, 2020. 

This is code follows along the "How to Make an Capacitive Sensor Using E-Textile Materials" here: https://youtu.be/kTfoMyjtgws 

The code contains 1 capacitive sensor which lights up when touched. 

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
  CircuitPlayground.begin(); // Initiating the Circuit Playground
}

void loop() {

  if (capButton(0)) { // if the 0 pin is activated through capactive touch
    Serial.println("Pin 0 is activated!");
    
    for (int i = 0 ; i < 10; i++) { // loop through all of the lights and turn them on
      Serial.println(i);
      CircuitPlayground.setPixelColor(i, 255, 0, 200); // pink colour
    }

  } else { // turn off all of the LEDs
    CircuitPlayground.clearPixels();
  }

}
