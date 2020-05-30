/*******
Code for the Textile Game Controller Jam by Social Body Lab, Dames Making Game, & Game Play Lab. 
May 30, 2020 - June 6, 2020. 

This is an assortment code that is pre-programmed onto all of the Circuit Playgrounds distributed to the game jam participants. 

The code contains 2 digital switches, 4 capactive touch buttons, and 1 analog sensor. 

   This is a small sample to run in the browser to see if your keys are working
   https://editor.p5js.org/2sman/sketches/rkGp1alib
   
   Follow along on this video here: https://youtu.be/AXbMM8rbhq8

   Arduino Example code:
   https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/
   https://www.arduino.cc/en/Reference/KeyboardModifiers

   Circuit Playground Library: 
   https://learn.adafruit.com/circuit-playground-lesson-number-0

*********/

/**Must include the Adafruit_CircuitPlayground.h**/
#include <Adafruit_CircuitPlayground.h>
#include <Keyboard.h> // this library allows the Circuit Playground to activate keyboard keys such as ASDF or the arrow keys. 

#define CAP_THRESHOLD   65 //increase this number if unintentional keypresses occur 
#define DEBOUNCE        100 // delay for ensuring that the button presses do not overlap

/**Capactive touch pins**/
int LeftPin = 9; // Pin "#9" on the Circuit Playground
int RightPin = 3; // Pin "#3" on the Circuit Playground
int UpPin = 10; // Pin "#10" on the Circuit Playground
int DownPin = 6;  //Pin "#6" on the Circuit Playground

/**Analog Sensor Inputs 
Variables to calibrate the sensor**/
int analogPin = 11; // Pin "#12" on the Circuit Playground
int analogValue;  // variable to store the value coming from the analog sensor
int analogMin = 1023;        // minimum sensor value
int analogMax = 0; // maximum sensor value 
int colour; // value for brightness

/** Button Inputs **/
int A_buttonPin = 0; // Pin "#0" on the Circuit Playground
int A_buttonVal; // Variable that stores the value of the A button

int B_buttonPin = 1; // Pin "#1" on the Circuit Playground
int B_buttonVal; // Variable that stores the value of the B button

/*** Change the below values according to what keys you want to
ASCII values can be found here:  http://www.asciitable.com/ ****/
int left_key = 216; // Set ASCII value for Left key
int right_key = 215; // Set ASCII value for Right key
int up_key = 218; // Set ASCII value for Up key
int down_key = 217; // Set ASCII value for Down key


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

  /**If using digital switch, you must include this in your code**/
  pinMode(A_buttonPin, INPUT_PULLUP); // Indicating the type of input for the A button
  pinMode(B_buttonPin, INPUT_PULLUP); // Indicating the type of input for the A button

  /**Calibrating the values for the analog sensor**/
  /**Press as hard as your can on the analog sensor for 3 seconds and then let it rest for two seconds
  This snippet of code finds the highest value and lowest value from the analog sensor**/
  
  while (millis() < 5000) { // for the first five seconds after uploading the code or plugging the Circuit Playground in
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
  
  A_buttonVal = digitalRead(A_buttonPin); // Read the A Button
  B_buttonVal = digitalRead(B_buttonPin); // Read the B Button

  analogValue = analogRead(analogPin); // Read the Analog Sensor 

  colour =  map(analogValue, analogMin, analogMax, 0, 250); // Map the incoming value. If it is near the maxium value that was calibrated, the variable colour will be assigned a number close to 250.
  Serial.println(colour); // print out colour to the serial monitor

  if (colour > 150) { // if the value is over 150
    Serial.println("Analog Sensor Pressed!"); // Print Message.
    for (int i = 0 ; i < 10; i++) { // loop through all of the leds and give them the intensity of "colour"
      CircuitPlayground.setPixelColor(i, colour, colour, colour);
    }
  } else {
    CircuitPlayground.clearPixels(); // else turn off the leds
  }

  if (A_buttonVal == LOW) { // if the A Button is pressed 
    Serial.println("A Button Touched!"); // Print Message.
    for (int i = 0 ; i < 10; i++) { // loop through all of the leds
      CircuitPlayground.setPixelColor(i, 0, 255, 0); // and turn them on to green
    }
  } else {
    CircuitPlayground.clearPixels(); // else turn off the leds
  }

  if (B_buttonVal == LOW) { // if the B Button is pressed 
    Serial.println("B Button Touched!"); // Print Message.
    for (int i = 0 ; i < 10; i++) { // loop through all of the leds
      CircuitPlayground.setPixelColor(i, 0, 0, 255); // and turn them on to blue
    }
  } else {
    CircuitPlayground.clearPixels(); // else turn off the leds
  }

  if (capButton(UpPin)) { // if the up button is pressed
    Serial.println("Up Button Touched!"); // Print Message.
    // turn on the LEDs to make an up arrow
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);

    Keyboard.press(up_key);  //Press the Up key 

    delay(DEBOUNCE);

  } else {
    // clear the colour of the LEDs in the up arrow
    CircuitPlayground.clearPixels();
    Keyboard.release(up_key); //Release the Up Key

  }
  if (capButton(LeftPin)) { // if the left button is pressed
    Serial.println("Left Button Touched!"); // Print message.

    // turn on the LEDs to make a left arrow
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(0, 255, 0, 0);

    Keyboard.press(left_key);  //Press the Left key 

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs in the left arrow
    CircuitPlayground.clearPixels();
    Keyboard.release(left_key); //Release the Left Key

  }
  if (capButton(RightPin)) { // if the right button is pressed

    Serial.println("Right Button Touched!"); // Print message.

    // turn on the LEDs to make a right arrow
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);

    Keyboard.press(right_key);  //Press the Right key 

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs in the right arrow
    CircuitPlayground.clearPixels();
    Keyboard.release(right_key); //Release the Right key

  }
  if (capButton(DownPin)) { // if the up button is pressed

    Serial.println("Down Button Touched!"); // Print message.

    // turn on the LEDs to make a down arrow
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);

    Keyboard.press(down_key);  //Press the Down key

    delay(DEBOUNCE);

  } else {
    // clear the colour of the LEDs in the down arrow
    CircuitPlayground.clearPixels();
    Keyboard.release(down_key); //Release the Down key
  }
}
