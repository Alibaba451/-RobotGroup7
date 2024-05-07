void readInfrared(){
  
  //Read values from infrared sensors
  int IRvalue1 = digitalRead(IR_1);
  int IRvalue2 = digitalRead(IR_2);
  int IRvalue3 = digitalRead(IR_3);
  int IRvalue4 = digitalRead(IR_4);

  //Print the Infrared values to the serial monitor
  Serial.print("IR_1 is: ");
  Serial.print(IRvalue1);
  Serial.print(", IR_2 is: ");
  Serial.print(IRvalue2);
  Serial.print(", IR_3 is: ");
  Serial.print(IRvalue3);
  Serial.print(", IR_4 is: ");
  Serial.println(IRvalue4);

}