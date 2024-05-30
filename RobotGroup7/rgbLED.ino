//Declare Threshold of 4, creating a range which the average readings can be in
int threshold = 4;

//Create a color state variable to keep track of the color detected, could be used for the efficent routing
String colorState = "";

//Function to display the detected color on the RGB LED
void displayColor(int Red, int Green, int Blue) {
      Serial.println(Red);
      Serial.println(Green);
      Serial.println(Blue);

  //Use analog write to set each LED value (0-255)
  WiFiDrv::analogWrite(LED_R, Red);
  WiFiDrv::analogWrite(LED_G, Green);
  WiFiDrv::analogWrite(LED_B, Blue);

}

//Create arrays with the expected average color ratings for the colors red, green, yellow and blue
const int ExpectedRed[3] = { 12, 4, 5 };
const int ExpectedGreen[3] = { 12, 17, 12 };
const int ExpectedBlue[3] = { 4, 7, 16 };
const int ExpectedYellow[3] = { 30, 20, 12 };

//Create function check color to read and display colors on the RGB LED
void checkColor() {

  //If statement checking if the average color values are within a threshold of the expected RED color values, and turning the red LED on if it is
  if (abs(avgRed - ExpectedRed[0] <= threshold) && abs(avgGreen - ExpectedRed[1] <= threshold) && abs(avgBlue - ExpectedRed[2] <= threshold && avgRed > avgGreen)) {
    
    //Use display color function to set Red led to max (for some reason the order is green, red, blue instead of rgb)
    displayColor(0, 255, 0);
    //Use colorState to keep track of the color (could be useful for efficient routing)
    colorState = "Red";
    Serial.println("Color Detected: Red");

  } else if (abs(avgRed - ExpectedGreen[0] <= threshold) && abs(avgGreen - ExpectedGreen[1] <= threshold) && abs(avgBlue - ExpectedGreen[2] <= threshold)) {
    
    displayColor(255, 0, 0);
    colorState = "Green";
    Serial.println("Color Detected: Green");
    
  } else if (abs(avgRed - ExpectedBlue[0] <= threshold) && abs(avgGreen - ExpectedBlue[1] <= threshold) && abs(avgBlue - ExpectedBlue[2] <= threshold)) {
    
    displayColor(0, 0, 255);
    colorState = "Blue";
    Serial.println("Color Detected: Blue");

  } else if (abs(avgRed - ExpectedYellow[0] <= threshold) && abs(avgGreen - ExpectedYellow[1] <= threshold) && abs(avgBlue - ExpectedYellow[2] <= threshold)) {
    
    displayColor(255, 255, 0);
    colorState = "Yellow";
    Serial.println("Color Detected: Yellow");

  } else {

    displayColor(255, 255, 255);
    colorState = "None";
    Serial.println("Color Detected: None");

  }

}
