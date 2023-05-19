// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(200);
}

/*
 * A 4.5-9V 130 size hobby DC motor powers the eletric car.
 * @params
 * @returns
 */
void carMotor() {
  
}

/*
 * A SG90 micro servo will open the garage door.
 * @params
 * @returns
 */
void garageDoor() {
  
}

/*
 * A line sensor will trigger when there isnt enough light turning on the headlights of the car.
 * @params
 * @returns
 */
void lightSensor() {
