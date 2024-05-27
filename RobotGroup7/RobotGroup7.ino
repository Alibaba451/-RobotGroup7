//NAME: SHAHEER SIDDIQUI
//DATE: April 30, 2024
//TITLE: ROBOTICS PROJECT

//Include TSC3200 library
#include <tcs3200.h>

//Include Wifi Driver
#include <WiFiNINA.h>

//Define Color Sensors as Analog Pins
#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

//Define Infrared Sensors
#define IR_1 4
#define IR_2 7
#define IR_3 8
#define IR_4 12

//Define Motor Pins
#define MOTOR_PIN1 3
#define MOTOR_PIN2 5
#define MOTOR_PIN3 6
#define MOTOR_PIN4 9

//Define Trig and Echo Pins for Ultrasonic Sensor
#define TRIG_PIN 10
#define ECHO_PIN 11

//Define RGB LED pins
#define LED_R 25
#define LED_G 26
#define LED_B 27

//Turning Logic
String turnDirection = "";
String lastTurnDirection = "";
bool isTurning = false;
bool wallDetected = false;

//State Logic
String currentState = "Null";
String oldCurrentState = "Null";

//Return the current run time in milliseconds
unsigned long currentMillis = millis();

//Declare global variable called irSensorMillis
unsigned long irSensorMillis = 0;

//Declare global variable to track the reporting period of the color sensor
unsigned long colorSensorMillis = 0;

//Declare global variable ultraSonicMillis
unsigned long ultraSonicMillis = 0;

//Declare global variable
unsigned long currentDistance = 1000;

//Declare Global Variables to hold average color values
int avgRed = 0;
int avgGreen = 0;
int avgBlue = 0;
int avgWhite = 0;

//Main Setup
void setup() {

  //Serial Begin at 9600 Baud Rate
  Serial.begin(115200);

  //Setup onboard RGB LED pins
  WiFiDrv::pinMode(LED_R, OUTPUT);  //Red LED defined
  WiFiDrv::pinMode(LED_G, OUTPUT);  //Green LED defined
  WiFiDrv::pinMode(LED_B, OUTPUT);  //Blue LED defined

  //Declare Infared Pins as INPUT
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);

  //Declare Motor Pins as OUTPUTS
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PIN3, OUTPUT);
  pinMode(MOTOR_PIN4, OUTPUT);

  //Declare Trig and Echo pins as OUTPUT and INPUT
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

//Main Loop
void loop() {

  //Return the curren t run time in milliseconds
  currentMillis = millis();

  Serial.println(currentMillis);

  Serial.println(currentState);

  //Check the states of the IR sensors every 500 Milliseconds
  if (currentMillis - irSensorMillis >= 500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }

  //If statement to read the color sensor at set intervals (every 250 ms), Should also see output in the serial monitor with the colors
  if (currentMillis - colorSensorMillis >= 250) {
    colorSensorMillis = currentMillis;
    readColorSensor();
  }

  //If statement to read the Ultrasonic Sensor every 500 ms
  if (currentMillis - ultraSonicMillis >= 20) {
    ultraSonicMillis = currentMillis;
    readUltrasonicSensor();
  }

  //If statement to read the color sensor at set intervals and display the color on the RGB LED
  if (currentMillis - colorSensorMillis >= 250) {
    colorSensorMillis = currentMillis;
    checkColor();
  }

  /*Motor Control Test Routine, move forward for 1 second, and than turn 90 degrees right
  motorControl(255, 255); //Move forward
  delay(1000); 
  motorControl(0, 0); //Stop
  delay(100);
  motorControl(255, -255); //Turn Right
  delay(400);
  motorControl(0, 0); //Stop
  delay(100); 
  */

  //Call robot logic function to run in stragiht line
  robotLogic();
}
