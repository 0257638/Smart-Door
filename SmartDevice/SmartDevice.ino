#define ledGreen A2
#define ledYellow A1
#define ledRed A0
#define crashSensor 7
#define servoPin 9

// SD Card Module
#include <SPI.h>
#include <SD.h>

#include <Servo.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 10

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
 /* Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");
*/
    
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  LightSystem();

  myservo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  garageDoor();
}  

/*
 * A traffic light shows how much charge is left in the car.
 * @params: none
 * @returns: void
 */
void LightSystem() {  
  digitalWrite(ledRed, HIGH);
  delay(1000);
  digitalWrite(ledRed, LOW);
  delay(50);
  digitalWrite(ledYellow, HIGH);
  delay(1000);
  digitalWrite(ledYellow, LOW);
  delay(50);
  digitalWrite(ledGreen, HIGH);
}

/*
 * A 4.5-9V 130 size hobby DC Motor powers the eletric car.
 * @params: none
 * @returns: void
 */
void carMotor() {
 
}

/*
 * A SG90 Micro Servo will open the garage door.
 * @params
 * @returns
 */
void garageDoor() {
  int servoPos = 100;
 // myservo.write(servoPos);
  if (digitalRead(crashSensor) == 0) {
    // if button pressed
    myservo.write(180); 
    } else {
    //button not pressed for 5 seconds
    delay(5000);
    myservo.write(0);
  }
}

/*
 * A Micro SD card stores how much charge was used on the last trip.
 * @params
 * @returns
 */
void checkCharge() {
//    logEvent("");
}

/*
 * A TCRT5000 line sensor will trigger when there isnt enough light turning on the headlights of the car.
 * @params
 * @returns
 */
void lightSensor() {  
  
}

/*
 * A RV24AF-10-40R1-B10K potentiometer controls the speed of the DC motor.
 * @params
 * @returns
 */
void speedControl() {  
  
}

/*
 * A HYDZ Piezo buzzer will trigger when the car is 30 cm away from a wall.
 * @params
 * @returns
 */
void breakAlarm() {  
  
}

/*
 * A Neo 6m GPS will trigger the SG90 Micro Servo to open the garage door
 * @params
 * @returns
 */
void garageTrigger() {  
  
}

/*
 * A DC 3v Yl-99 crash switch will trigger the servo to close the garage door.
 * @params
 * @returns
 */
void carshSwitch() {  
  
}
