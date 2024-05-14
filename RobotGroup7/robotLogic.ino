void robotLogic() {

  motorLogic(); //process motor logic based on IR sensor values
}

void motorLogic() {
  int* IRvalues;
  IRvalues = readInfrared();

  if (IRvalues[2] == 1 && IRvalues [1] == 1){
    motorControl(200, 200);
    currentState = "Forward";
  } else if (IRvalues[2] == 0 && IRvalues[1] == 1) {
    motorControl(0, 200); //Turn slightly left
    currentState = "Left";
  } else if (IRvalues[2] == 1 && IRvalues[1] == 0) {
    motorControl(200, 0); //Turn slightly Right
    currentState = "Right";
  } else if (IRvalues[0] == 1 && IRvalues[2] == 1 && IRvalues[1] == 1 && IRvalues[3] == 1) {
    //When none of the IR sensorss detect a line, continue the last state detected by the center IR sensors
    if (currentState == "Forward") {
      motorControl(200, 200); //Move straight forward
    } else if (currentState == "Left") {
      motorControl(150,200); //Turn slightly left
    } else if (currentState == "Right") {
      motorControl(200, 150); //Turn slightly Right
    }
  }
}