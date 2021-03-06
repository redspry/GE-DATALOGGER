# GE-DATALOGGER
Capstone Project for GE Datalogger

#### **<u>Resources</u>**

if you are unfamiliar with Arduino programming or C this is a good place to start

https://create.arduino.cc/

 download the code from this GitHub repo here, and keep it as a **.zip** file

![GitHub](images/GitHub.png)

on the site https://create.arduino.cc/ you can copy this code into the online editor seen here, use the upload button, and select the zip file you downloaded from this GitHub and select import. 

![ArduinoIDE](images/ArduinoIDE.png)



#### FRITZING SCHEMATIC

this schematic is a simplified version of the protoytpe/production schematic. It allows for better visibility of ports and is a good representation for ports and protocols. 

![fritzing](images/fritzing.png)

## ICs THAT USE UART

USB connector to the Arduino Mini

## ICs THAT USE I2C

#### Temperature and Humidity Sensor

Address

#### Accelerometer

Address

#### Hazardous Gas Sensors

Address

#### Battery Monitor

Address



## ICs THAT USE SPI PROTOCOL 

#### **BLUETOOTH MODULE**

**Adafruit SPI BLE:** https://learn.adafruit.com/introducing-the-adafruit-bluefruit-spi-breakout/configuration

the BluefruitConfig.h file is to configure the Arduino pins we are using for this design, it is used by the bluetooth.ino file

```c
// SHARED SPI SETTINGS
#define BLUEFRUIT_SPI_CS               8
#define BLUEFRUIT_SPI_IRQ              7
#define BLUEFRUIT_SPI_RST              4    // Optional but recommended, set 
```

The bluetooth.ino file will run a test, you can run it alone

