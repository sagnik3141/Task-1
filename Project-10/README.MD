# Project-10: DIY IR Contact Less Thermometer an IOT device
## Problem Statement
Build up a complete autonomous IR contactless Temperature device which can be mounted anywhere like a door, apartment gates or community halls and track the temperature and post the result to any cloud.
## Components
* Mlx90614 Contactless IR Infrared Temperature Sensor Module
* Nodemcu ESP8266 Wifi IOT Development Board as a Microcontroller
* LCD 16X2 Alphanumeric Display
## Description
* This device takes temperature information from the Mlx90614 Temperature Sensor Module.

* It connects to WiFi and sends the temperature information to a personal slack channel.

* The LCD Dispay communicates though the I2C method and SCL and SDA lines have to be connected accordingly.

* The temperature is also displayed on the LCD Display.
## Circuit
![](capture_z5AQbA3y6s.jpg)

## Personal Comments
* Need to install the MLX sensor library and the ESP8266WiFi.h library before uploading the code.
* Understanding this project helped me understand how to connect and display stuff on the LCD Display.
* Got better clarity on communicating with the internet using a microcontroller.
