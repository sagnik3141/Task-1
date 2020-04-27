# Project-19: Arduino and Android based Universal IR Remote Control
## Problem Statement
Convert an Android Phone into an IR Remote using Arduino to control various devices at home.
## Description
An Android Phone with the custom made Android App sends the signal to Arduino circuit over Bluetooth, further the Arduino receives the signal through TSOP-IR receiver (1838T) and analyses it. Then Arduino commands the IR LED to blink in a particular pattern, corresponding to the button pressed on that Android Device App. This blinking pattern is captured by TV or Set-Top box’s IR receiver and it follows the instruction accordingly like changing the channel or increasing the volume.
## Personal Comments
* Learnt how to to work with TSOP-IR receiver (1838T)
* Learnt how to develop a custom application using MIT’s APP inventor-2

Need to download and install the IR remote library to run the code.
