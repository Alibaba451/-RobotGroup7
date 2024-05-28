//Declare Threshold of 2, creating a range which the average readings can be in 
int threshold = 4;

//Create a color state variable to keep track of the color detected, could be used for the efficent routing
String colorState = "";

//Function to display the detected color on the RGB LED
void displayColor(int Red, int Green, int Blue) {
  WiFiDrv::analogWrite(LED_R, Red);
  WiFiDrv::analogWrite(LED_G, Green);
  WiFiDrv::analogWrite(LED_B, Blue);
}

//Create arrays with the expected average color ratings for the colors red green and blue
const int ExpectedRed[3] = {12, 4, 5};
const int ExpectedGreen[3] = {12, 17, 9};
const int ExpectedBlue[3] = {4, 7, 18};
const int ExpectedYellow[3] = {30, 20, 12};

void checkColor() {

  if (abs(avgRed - ExpectedRed[0] <= threshold) && abs(avgGreen - ExpectedRed[1] <= threshold) && abs(avgBlue - ExpectedRed[2] <= threshold && avgRed > avgGreen))  {
    displayColor(255, 0, 0);
    colorState = "Red";
    Serial.println("Color Detected: Red");
  } else if (abs(avgRed - ExpectedGreen[0] <= threshold) && abs(avgGreen - ExpectedGreen[1] <= threshold) && abs(avgBlue - ExpectedGreen[2] <= threshold)) {
    displayColor(0, 255, 0);
    colorState = "Green";
    Serial.println("Color Detected: Green");
  } else if (abs(avgRed - ExpectedYellow[0] <= threshold) && abs(avgGreen - ExpectedYellow[1] <= threshold) && abs(avgBlue - ExpectedYellow[2] <= threshold)) {
    displayColor(255, 170, 85);
    colorState = "Yellow";
    Serial.println("Color Detected: Yellow");
  }
}

//   if (avgRed > avgGreen && avgRed > avgBlue && avgWhite < 35) {
//     if (abs(avgRed - 12) <= threshold && abs(avgGreen - 4) <= threshold && abs(avgBlue - 5) <= threshold) {
//       displayColor(255, 0, 0);  // Red
//       colorState = "Red";
//       Serial.println("Color Detected: Red");
//     }
//   } else if (avgGreen > avgRed && avgGreen > avgBlue && avgWhite < 35) {
//     if (abs(avgRed - 12) <= threshold && abs(avgGreen - 17) <= threshold && abs(avgBlue - 9) <= threshold) {
//       displayColor(0, 255, 0);  // Green
//       colorState = "Green";
//       Serial.println("Color Detected: Green");
//     }
//   } else if (avgBlue > avgRed && avgBlue > avgGreen && avgWhite < 35) {
//     if (abs(avgRed - 4) <= threshold && abs(avgGreen - 7) <= threshold && abs(avgBlue - 18) <= threshold) {
//       displayColor(0, 0, 255);  // Blue
//       colorState = "Blue";
//       Serial.println("Color Detected: Blue");
//     }
//   } else if (avgRed > avgBlue && avgGreen > avgBlue && avgRed > avgBlue && avgWhite > 35) {
//     if (abs(avgRed - 39) <= threshold && abs(avgGreen - 24) <= threshold && abs(avgBlue - 13) <= threshold) {
//       displayColor(100, 255, 200);  // Blue
//       colorState = "Blue";
//       Serial.println("Color Detected: Yellow");
//     }
//   } else {
//     displayColor(255, 255, 255);  // No color detected
//     colorState = "White/No Color Detected";
//     Serial.println("Color Detected: None");
//   }
// }
