# Textile-Game-Controller-Jam

## Overview
These sample codes were written for the [Textile Game Controller Jam](http://socialbodylab.com/textile-game-controllers-jam/).

These samples provide basic input for *digital switches*, *analog sensors*, and *capactive sensing*. 

All of the examples use an [Adafruit Circuit Playground Classic](https://www.adafruit.com/product/3000). An overview of the Circuit Playground Classic can be found [here](https://learn.adafruit.com/introducing-circuit-playground/overview).


## Table of Contents 

* [Materials Used](#materials)
* [Digital Switch](#digital)
* [Analog Sensor](#analog)
* [Capactive Sensing - Conductive Fabric](#capactive-fab)
* [Capactive Sensing - Felting](#capactive-felt) 
* [Capactive Sensing - Embroidery](#capactive-em) 

<a name="materials"/>

## Materials Used

### Conductive & Electronic Components
- [Adafruit Circuit Playground](https://www.adafruit.com/product/3000)
- [Conductive Thread](https://www.digikey.ca/en/products/detail/adafruit-industries-llc/641/5356753)
- [Conductive Fabric](https://www.digikey.ca/en/products/detail/adafruit-industries-llc/1168/5356770)
- [Conductive Wool Fiber](https://www.digikey.ca/en/products/detail/adafruit-industries-llc/1088/10670014)
- [Velostat](https://www.digikey.ca/catalog/en/partgroup/pressure-sensitive-conductive-sheet-velostat-linqstat/71881)
- [10K Ohm Resistors](https://www.digikey.ca/en/products/detail/yageo/CFR-25JB-52-10K/338)

### Accessory Components 
- Cotton Thread
- Sewing Needles
- Needle Threader
- Industrial Felt 
- Craft Felt
- Sponge 
- Felting Needles 
- Coloured Wool Fiber
- Silicone Finger Protector
- Embroidery Hoop
- Embroidery Needle (wide-eyed needle)
- Embroidery Floss
- Cotton Fabric 

<a name="digital"/>

## Digital Switch

Follow along on the video tutorial ["How to Make an E-Textile Digital Switch"](https://youtu.be/OHO1NxV-ebw)

[Sample Code for Digital Switch](/digital_switch_tutorial.ino)

The code contains 1 digital switch which lights up the LED ring when activated. 

### Circuit Diagram
![Circuit Diagram for Digital Switch](/read-me-assets/digital-switch-diagram.png)

<a name="analog"/>

## Analog Sensor

Follow along on the video tutorial ["How to Make an E-Textile Analog Sensor"](https://youtu.be/tA37mGEnPes)

[Sample Code for Analog Sensor](/analog_sensor_tutorial.ino)

The code contains 1 analog sensor. The amount of lights that turn on is related to the reading of the pressure sensor. If high force is applied onto the sensor, the most of the lights will turn on. If light pressure is applied, only a few will turn on. 
  
![Circuit Diagram for Analog Sensor](/read-me-assets/analog-sensor-diagram.png)

<a name="capactive-fab"/>

## Capactive Sensing - Conductive Fabric

Follow along on the video tutorial ["How to Make an Capacitive Sensor Using E-Textile Materials"]( https://youtu.be/kTfoMyjtgws)

[Sample Code for Capactive Touch with Fabric](/capacitive_touch_tutorial.ino)

The code contains 1 capacitive sensor which lights up when touched. 

![Circuit Diagram for Capactive Sensing](/read-me-assets/capacitive-sensing-diagram.png)

<a name="capactive-felt"/>

## Capactive Sensing - Felting

Follow along on the video tutorial ["How to Felt an E-Textile Capacitve Sensor"](https://youtu.be/NowvCFEpItk)  

[Sample Code for Capactive Touch with Felting](/felting_tutorial.ino)

The code contains 2 capactive touch sensors. 

<a name="capactive-em"/>

## Capactive Sensing - Embroidery

Follow along on the video tutorial  ["How to Embroider an E-Textile Capacitve Sensor"](https://youtu.be/lxuEnd14fhU)  

[Sample Code for Capactive Touch with Embroidery](/embroidery_tutorial.ino)

The code contains 2 capactive touch sensors. 


