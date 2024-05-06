//NAME: SHAHEER SIDDIQUI
//DATE: April 30, 2024
//TITLE: ROBOTICS PROJECT

//Include TSC3200 library
#include <tcs3200.h>

//Define Color Sensors as Analog Pins
#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

//Define Infrared Sensors
#define IR_1 2
#define IR_2 4
#define IR_3 7
#define IR_4 8

//Define Motor Pins
#define  MOTOR_PIN1 3
#define  MOTOR_PIN2 5
#define  MOTOR_PIN3 6
#define  MOTOR_PIN4 9


//Declare global variable called irSensorMillis
unsigned long irSensorMillis = 0;

//Declare global variable to track the reporting period of the color sensor
unsigned long colorSensorMillis = 0;

//Main Setup
void setup() {
//Serial Begin at 9600 Baud Rate
Serial.begin(9600);

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
}

//Main Loop
void loop() {
//Return the current run time in milliseconds
unsigned long currentMillis = millis();

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

//Motor Control Test Routine, move forward for 1 second, and than turn 90 degrees right
motorControl(255, 255); //Move forward
delay(1000); 
Serial.println("FORWARD");
motorControl(0, 0); //Stop
delay(100);
motorControl(255, -255); //Turn Right
delay(400);
Serial.println("TURN RIGHT");
motorControl(0, 0); //Stop
delay(100);

}
