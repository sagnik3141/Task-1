# Project-9: Fire Chasing Robot
## Problem Statement
Creating a firefighting robot that chases a flame and extinguishes it by blowing air at it from a fan.
## Components
* PICO
* Flame sensor
* DC motor
* Propeller
* L298N H-bridge motor driver
* PCA9685 12-bit 16-channel PWM driver
* 2WD robot chassis kit
* Mini breadboard
* Jumper Wires
## Description
We'll be using 3 flame sensors in this project and we'll have the robot move independently using their readings, we'll place these sensors on the middle, left, and right side of the robot's chassis. And they'll be placed in such a way to have the ability to accurately pin point the flame source and put it out.

Please note that our sensors, have a low reading "0" when they sense fire, and a high reading "1" when they don't sense fire.

To make a fire fighting robot effective it must have the ability to fight fire, and for that we are going to create a fan that we aim at the fire and put it out with. And we're going to create this fan by using a small DC motor with a propeller installed on it.

To be able to control the DC motor's running speed and direction you need to use the L298N H-bridge motor driver, which is a motor driver module that has the ability to control the motor's running speed and direction, with the ability to feed the motors from an external power source.
## Personal Notes
* Learn how to use flame sensors with PICO, how to read their output value and how to act on it, and how to use Darlington sensors with DC motors and how to control them.
