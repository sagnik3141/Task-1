# Project-2: Arduino Wireless Weather Station
## Problem Statement
Building a weather station using an Arduino which displays indoor and remote tempertaure and humidity on a TFT display.
## Components
* Arduino Due
* Arduino Nano
* TFT HX8357C
* DHT22 Temperature Sensor
* Breadboard
* NRF24L01+: Wireless Modules
## Overview
There are two parts of this Weather Station, the transmitter circuit and the receiver circuit.

There are sensors on both the transmitter and the receiver circuits to get both indoor and remote data.

The transmitter measures the temperature and the humidity, and sends the data wirelessly to the receiver. The receiver measures the temperature and the humidity, receives the data from the remote sensor and displays everything on the TFT display.
## Transmitter Circuit
The transmitter circuit uses the DHT22 sensor to sense temperature and humidity remotely. This has a VCC and a ground pin which needs to be connected appropriately. The OUT pin can be connected to any digital pin.

In order to use the DHT22 sensor with Arduino, we have to use the DHT library.

The NRF24L01 module is a bi-directional transceiver module. It uses the SPI interface in order to communicate with Arduino.

Three of the pins on this module are the SPI pins used for communication and are connected to the corresponding pins on the Arduino. The first of these pins is SCK which goes to digital pin 13 of the Arduino Uno. The next pin is MOSI which goes to digital pin 11, and the last pin in MISO which goes to digital pin 12. The CSN and CE pins can be connected to any digital pins and are used to decide if the module is in standby or active mode.

We need to use the NRF24L01 library to use the module.
## Receiver Circuit
The receiver circuit uses the DHT22 sensor to measure the temperature and humidity indoor. Output pin is connected to Arduino's digital pin 8.

It also uses the NRF24L01 module to receive the data from the transmitter circuit. 3rd pin to Arduino's digital pin 6. 4th pin to Arduino's digital pin 7. The 5th, 6th and 7th pins to the Arduino's SCK, MOSI, and MISO pins respectively.
## Code
The transmitter code and the receiver code are attached. Before uploading them, we need to install the DHT library, the NRF24L01 library and the display library.
## Personal Notes
* This project gave me an understanding of how wireless networks work.
* I understood briefly two different Serial Communication Protocols and their differences. They are the SPI and the I2C.
* I learnt how to connect the transciever module to the right pins and also understood how to use them to establish communication between two boards.
* I understood how to display text on the TFT display.
* Understood how to work with the DHT sensor module.




