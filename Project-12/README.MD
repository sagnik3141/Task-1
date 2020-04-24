# Project-12: Line-Following Robot using RPi
## Problem Statement
Build a robot which uses line sensors with RPi to move on a particular line.
## Description
Each line sensor has three pins: VCC for power, GND for ground, and DO for digital out.

Now connect the VCC pins of both line sensors to a 5V pin on your Raspberry Pi, and the GND pins of the sensors to a GND pin on your Raspberry Pi. Each of the two DO pins can be connected to any numbered GPIO pin.

The motor controller board is connected so that the left motor is on pins GPIO 7 and GPIO 8, and the right motor is on pins GPIO 9 and GPIO 10. The left line sensor is on pin GPIO 17, and the right line sensor is on pin GPIO 27.

The algorithm used is as follows:


    The robot is perfectly on the line and should drive forwards:
        Both line sensors are off the line and outputting a 0
        Both motors should receive 1 to drive forwards
    The robot has drifted left and needs to turn right:
        The right sensor is on the line and outputting a 1
        The left sensor is off the line and outputting a 0
        The left motor should run backwards and so receive a -1
        The right motor should run forwards and so receive a 1
    The robot has drifted right and needs to turn left:
        The right sensor is off the line and outputting a 0
        The left sensor is on the line and outputting a 1
        The Left motor should run forwards and so receive a 1
        The right motor should run backwards and so receive a -1


## Personal Comments:
* To run the code, the LineSensor library needs to be imported.
