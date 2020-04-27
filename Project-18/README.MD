# Project-18: Arduino based Angry Bird Game Controller
## Problem Statement
Build an Angry Bird game controller using flex sensor and potentiometer.
## Description
The Arduino Board reads the values from the Potentiometer and Flex Senor and Transmits them to the Laptop/PC through USB COM port via normal Serial.write() function. We then read this information using Processing and control the mouse cursor using the Robot class in Java which is supported by processing IDE. We have programmed the processing IDE in such a way that when the Flex sensor is pulled a mouse click will be made and based on how much it is pulled the mouse pointer will move in X direction. Then based on the value from potentiometer we will move the mouse cursor in Y direction, this way we can set the direction in which bird should be launched.
## Personal Comments
* Learnt hoe to control cursor using potentiometer.
* Learnt how to use flex sensor and how to control cursor using it.
