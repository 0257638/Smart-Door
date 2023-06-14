#define ledGreen A2
#define ledYellow A1
#define ledRed A0
#define crashSensor 7
#define servoPin 9
#define trigPin 2
#define echoPin A4
#define buzzerPin 8


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

     Serial.begin (9600);         // initialize serial port
  pinMode(trigPin, OUTPUT);   // set arduino pin to output mode
  pinMode(echoPin, INPUT);    // set arduino pin to input mode
  pinMode(buzzerPin, OUTPUT); // set arduino pin to output mode
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

  lightSystem();

  myservo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);

int ldrValue = analogRead(0);
  if (ldrValue < 512) {
   digitalWrite(8, HIGH);
  } else {
  digitalWrite(8, LOW);
}
  
  garageDoor();
  breakAlarm();
}  

/*
 * A traffic light shows how much charge is left in the car.
 * @params: none
 * @returns: void
 */
void lightSystem() {  
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
 * A DC 3v Yl-99 crash switch will trigger the SG90 Micro servo to close the garage door.
 * @params
 * @returns
 */
void garageDoor() {
  int servoPos = 100;
  if (digitalRead(crashSensor) == 0) {
    // if button pressed open garage door
    myservo.write(180); 
    } else {
    // if button is not pressed for 5 seconds close garage door
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
//    logEvent("Check lightSystem status");
}

/*
 * A TCRT5000 line sensor will trigger when there isnt enough light turning on the headlights of the car.
 * @params
 * @returns
 */
void lightSensor() {  
  
}

/*
 * A RV24AF-10-40R1-B10K potentiometer controls the speed of the 4.5-9V 130 size hobby DC motor.
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
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
int  durationUs = pulseIn(echoPin, HIGH);
  // calculate the distance
int  distanceCm = 0.017 * durationUs;
  // 100 = 1 meter from back wall of garage
  if(distanceCm <= 100)
    digitalWrite(buzzerPin, HIGH); // turn on Piezo Buzzer
  else
    digitalWrite(buzzerPin, LOW);  // turn off Piezo Buzzer

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
}

/*
 * A Neo 6m GPS will trigger the SG90 Micro Servo to open the garage door
 * @params
 * @returns
 */
void garageTrigger() {  
  
}
