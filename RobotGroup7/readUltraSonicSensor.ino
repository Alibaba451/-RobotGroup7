//Declare Distance and Duration as long variables

//Function to Send out and recieve signals from Echo and Trig pins to read distance
void readUltrasonicSensor() {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
long duration, distance;
  //Send out signal from Trigger pin by setting it high
  digitalWrite(TRIG_PIN, LOW);
  delay(2);
  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  //Use pulseIn to measure the duration the signal is sent out for
  duration = pulseIn(ECHO_PIN, HIGH);
  //Multiply the duration by the speed of sound and divide by two to calculate the distance
   distance = duration * 0.034 / 2;

  //Print the distance to the serial monitor
  Serial.print(" Distance: ");
  Serial.println(distance);

  currentDistance = distance;

}