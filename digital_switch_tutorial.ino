/*******
Code for the Textile Game Controller Jam by Social Body Lab, Dames Making Game, & Game Play Lab. 
May 30, 2020 - June 6, 2020. 

This is code follows along the "How to Make an E-Textile Digital Switch" here: https://youtu.be/OHO1NxV-ebw 

The code contains 1 digital switch which lights up the LED ring when activated. 

Circuit Playground Library: 
https://learn.adafruit.com/circuit-playground-lesson-number-0

*********/

/**Must include the Adafruit_CircuitPlayground.h**/

#include <Adafruit_CircuitPlayground.h>

int buttonVal; // Reads the input of the switch, returns either a 0 or 1
int buttonPin = 1; // The physical pin that e-textile material is connected to 

void setup() {

  Serial.begin(9600); // Starting the serial monitor
  CircuitPlayground.begin(); // Initiating the Circuit Playground
  pinMode(buttonPin, INPUT_PULLUP); // Indicating the type of input for the pin  used

}

void loop() {
  buttonVal = digitalRead(buttonPin); // Reading the current value of the button pin (is it activated or not?)

  if (buttonVal == LOW) { // if the digital switch is activated
    for (int i = 0 ; i < 10; i++) { // loop through all of the LED lights on the Circuit Playground and light them up.
      CircuitPlayground.setPixelColor(i, 255, 0, 200); // Aqua colour
    }
  } else { // if the digital switch is not activated, turn the LED lights off. 
    CircuitPlayground.clearPixels();
  }
}
