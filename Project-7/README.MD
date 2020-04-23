# Project-7: Motion and Gesture Detection by PIR Sensor & Arduino
## Problem Statement
Making a gesture detector system using PIR and Arduino.
## Components
* Arduino Nano R3
* TPA81 8 pixel thermal array sensor
* 0.96inch SPI 128X64 OLED Display Module
* Breadboard
* Male/Female Jumper Wires
## Description
The TPA81 has an array of eight thermopiles arranged in a row. It can measure the temperature of 8 adjacent points simultaneously.

We use this to create arrays of temeprature values corresponding to a particular gesture and then use that to detect gestures.

This project uses an algorithm to detect a simple gesture like increasing or decreasing the volume of a sound player.

Here's how it works:

This is a small segment of the code:
```
void loop() {
 // Print temperature light
 Serial.print(tpa.getAmbient());
 Serial.print(" ");
 // Print all temperature point
 for (int i = 1; i <= 8; i++) { if (tpa.getPoint(i)>29)
   Serial.print("#  ");
   else
   Serial.print(".  ");
 }
Serial.println(" ");
 delay(100);
}
```

After running this code, Open the Serial Terminal in Arduino IDE and look at the 8 array temperature sensed by TPA81. the first number in each line belongs to the total temperature. Now put your hand in front of the sensor and see the temperature of your body. To define a gesture by hand, you should know your hand temperature and set it as an offset. We set it to 29 degrees. Upload the next code to see your hand movement in front of TPA81.

The required info is displayed on the OLED Display by converting an image into hexadecimal values using a software.

## Personal Comments
* For the code to run, the TPA and SSD1306 libraries need to be installed.
* Learnt how to use and run an 8-pixel PIR sensor named TPA81.
* Learnt how to display images on the OLED Display.
