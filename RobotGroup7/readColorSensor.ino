//Create a tcs3200 object and assign the analog color pins to it
tcs3200 tcs(COLOR_0, COLOR_1, COLOR_2, COLOR_3, COLOR_OUT);

//Function to read the color sensor
void readColorSensor() {

  //Variable Sample set as 5 (Read each color 5 times for greater accuracy)
  const int samples = 5; 
  
  //Declare long variables for each color to take in large numbers representing each color
  long sumRed = 0, sumGreen = 0, sumBlue = 0, sumWhite = 0;

  //Run the for loop 5 times to read the color sensor values, adding the value each time
  for (int i = 0; i < samples; i++) {
    sumRed += tcs.colorRead('r');
    sumGreen += tcs.colorRead('g');
    sumBlue += tcs.colorRead('b');
    sumWhite += tcs.colorRead('c');

  }

  //Divide the sum of the 5 iterations of color sensor values by the sample number (5) to get accurate average
  int avgRed = sumRed / samples;
  int avgGreen = sumGreen / samples;
  int avgBlue = sumBlue / samples;
  int avgWhite = sumWhite / samples;

  //Serial print the average color sensor readings
  Serial.print("Average Color Sensor Readings: ");
  Serial.print(" R= ");
  Serial.print(avgRed);
  Serial.print("Average Color Sensor Readings: ");
  Serial.print(" G= ");
  Serial.print(avgGreen);
  Serial.print("Average Color Sensor Readings: ");
  Serial.print(" B= ");
  Serial.print(avgBlue);
  Serial.print("Average Color Sensor Readings: ");
  Serial.print(" W(clear)= ");
  Serial.print(avgWhite);
  
}