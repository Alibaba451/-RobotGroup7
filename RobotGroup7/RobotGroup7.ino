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

//State turn direction state variable to keep track of each turn direction
String turnDirection = "";

//State last turn direction as a string to remember the last turn
String lastTurnDirection = "";

//boolean variable as global variable to keep track of turning state
bool isTurning = false;

//boolean variable as global variable to keep track of if a wall was detected
bool wallDetected = false;

//State a global variable as a flag to track the current state of the robot.
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

//Declare global variable ultraSonicMillis
unsigned long RGBMillis = 0;

//Declare global variable
unsigned long currentDistance = 1000;

//Declare the average color sensor readings as global variables
int avgRed;
int avgGreen;
int avgBlue;
int avgWhite;

//Main Setup
void setup() {

  //Serial Begin at 115200 Baud Rate
  Serial.begin(115200);

  //Setup onboard RGB LED pins
  WiFiDrv::pinMode(LED_R, OUTPUT);  //Red LED defined
  WiFiDrv::pinMode(LED_G, OUTPUT);  //Green LED defined
  WiFiDrv::pinMode(LED_B, OUTPUT);  //Blue L ED defined

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

  //Return the current run time in milliseconds
  currentMillis = millis();

  //Serial print the time running in serial monitor to troubleshoot for delays
  Serial.println(currentMillis);

  //Serial print the current state of the robot to troubleshoot for turnlogic
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

  //If statement to read the Ultrasonic Sensor every 15 ms
  if (currentMillis - ultraSonicMillis >= 15) {

    ultraSonicMillis = currentMillis;
    readUltrasonicSensor();
  }

  //If statement to Display color to the RGB LEDs every 500 ms
  if (currentMillis - RGBMillis >= 500) {

    RGBMillis = currentMillis;
    //Call checkColor function to read the RGB LED
    checkColor();
  }


  //Call robot logic function to run in stragiht line with motorlogic and turn with turnlogic
  robotLogic();
}
