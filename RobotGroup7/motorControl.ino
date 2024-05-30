//Declare Motor Multipliers to determine capacity at which motors run
float motor1Multiplier = 0.95;
float motor2Multiplier = 0.95;

//Create motorControl function
void motorControl(int speed1, int speed2) {

  //Apply the motor multipliers to the motor speed
  int adjustedSpeed1 = speed1 * motor1Multiplier;
  int adjustedSpeed2 = speed2 * motor2Multiplier;

  //Prevent the adjusted speeds from  exceeding the PWM range [0, 255]
  adjustedSpeed1 = max(-255, min(255, adjustedSpeed1));
  adjustedSpeed2 = max(-255, min(255, adjustedSpeed2));

  //Apply the adjusted speed to the motors using shortened if statements
  analogWrite(MOTOR_PIN1, adjustedSpeed1 > 0 ? adjustedSpeed1 : 0);
  analogWrite(MOTOR_PIN2, adjustedSpeed1 < 0 ? -adjustedSpeed1 : 0);
  analogWrite(MOTOR_PIN3, adjustedSpeed2 > 0 ? adjustedSpeed2 : 0);
  analogWrite(MOTOR_PIN4, adjustedSpeed2 < 0 ? -adjustedSpeed2 : 0);
  
}