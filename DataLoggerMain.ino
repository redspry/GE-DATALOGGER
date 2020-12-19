/*
  This is demo test code, Notably would take readings from analog inputs
*/

#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)

// #include <DS3231.h>
// DS3231  rtc(SDA, SCL);

Adafruit_BME280 bme;
File sdcard_file;
int CS_pin = 8; // Pin 8 on Arduino Uno
const int sensor_pin = A0; // connected to accelerometer
float temp;
float output;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(CS_pin, OUTPUT);
  // rtc.begin();
  // SD Card Initialization

  /*
    CODE FOR THE TEMP/HUMIDITY SENSOR
  */
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    //while (1);
  }

  /*
    CODE FOR THE SD CARD WRITING
  */
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }


  /*
    CODE FOR THE DATA.txt file
  */
  Serial.print("Date");
  Serial.print("      ");
  Serial.print("Time");
  Serial.print("     ");
  Serial.print("Acceleration Analog");
  Serial.print("     ");
  Serial.print("Pressure hPa");
  Serial.print("     ");
  Serial.print("Temperature *C");
  Serial.print("     ");
  Serial.print("Approx. Altitude m");
  Serial.print("     ");
  Serial.print("Acceleration Raw");
  Serial.print("     ");
  Serial.print("Humidity %");
  Serial.println("     ");


  sdcard_file = SD.open("data.txt", FILE_WRITE);
  if (sdcard_file) {
    sdcard_file.print("Date");
    sdcard_file.print("      ");
    sdcard_file.print("Time");
    sdcard_file.print("     ");
    sdcard_file.print("Acc");
    sdcard_file.print("     ");
    sdcard_file.print("Pres hPa");
    sdcard_file.print("     ");
    sdcard_file.print("Temp*C");
    sdcard_file.print("     ");
    sdcard_file.print("Alt m");
    sdcard_file.print("     ");
    sdcard_file.print("Humid %");
    sdcard_file.println("     ");
    sdcard_file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
}

void loop() {
  output = analogRead(sensor_pin);
  temp = (output * 500) / 1023;
  Serial.print("DATE");//rtc.getDateStr());
  Serial.print("     ");
  Serial.print("TIME");//rtc.getTimeStr());
  Serial.print("      ");
  Serial.print(temp);
  Serial.print("      ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.print("      ");
  Serial.print(bme.readTemperature());
  Serial.print("      ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.print("      ");
  Serial.println(bme.readHumidity());

  sdcard_file = SD.open("data.txt", FILE_WRITE);
  if (sdcard_file) {
    sdcard_file.print("TIME");//rtc.getTimeStr());
    sdcard_file.print("     ");
    sdcard_file.print("DATE");//rtc.getTimeStr());
    sdcard_file.print("     ");
    sdcard_file.print(temp);
    sdcard_file.print("     ");
    sdcard_file.print(bme.readPressure() / 100.0F);
    sdcard_file.print("     ");
    sdcard_file.print(bme.readTemperature());
    sdcard_file.print("     ");
    sdcard_file.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    sdcard_file.print("     ");
    sdcard_file.print(bme.readHumidity());
    sdcard_file.println("     ");
    sdcard_file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
  delay(1000);
}
