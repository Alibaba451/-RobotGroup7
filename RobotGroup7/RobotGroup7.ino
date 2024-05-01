//NAME: SHAHEER SIDDIQUI
//DATE: April 30, 2024
//TITLE: ROBOTICS PROJECT

//Define Infrared Sensors
#define IR_1 2
#define IR_2 4
#define IR_3 7
#define IR_4 8

//Declare global variable called irSensorMillis
unsigned long irSensorMillis = 0;

//Setup
void setup() {
//Declare Infared Pins as INPUT
pinMode(IR_1, INPUT);
pinMode(IR_2, INPUT);
pinMode(IR_3, INPUT);
pinMode(IR_4, INPUT);

}

//Loop
void loop() {
//Return the current run time in milliseconds
unsigned long currentMillis = millis();

if (currentMillis - irSensoreMillits >= 500) {
  irSensorMillis = currentMillits;
  readInfrared();
}
}
