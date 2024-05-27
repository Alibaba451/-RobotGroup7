int threshold = 2;
String colorState = "";

//Function to display the detected color on the RGB LED
void displayColor(int Red, int Green, int Blue) {
  WiFiDrv::analogWrite(LED_R, Red);
  WiFiDrv::analogWrite(LED_G, Green);
  WiFiDrv::analogWrite(LED_B, Blue);
}

void checkColor() {
  int threshold = 2;

  if (avgRed > avgGreen && avgRed > avgBlue && avgWhite < 35) {
    if (abs(avgRed - 12) <= threshold && abs(avgGreen - 4) <= threshold && abs(avgBlue - 5) <= threshold) {
      displayColor(255, 0, 0);  // Red
      colorState = "Red";
      Serial.println("Color Detected: Red");
    }
  } else if (avgGreen > avgRed && avgGreen > avgBlue && avgWhite < 35) {
    if (abs(avgRed - 12) <= threshold && abs(avgGreen - 17) <= threshold && abs(avgBlue - 9) <= threshold) {
      displayColor(0, 255, 0);  // Green
      colorState = "Green";
      Serial.println("Color Detected: Green");
    }
  } else if (avgBlue > avgRed && avgBlue > avgGreen && avgWhite < 35) {
    if (abs(avgRed - 4) <= threshold && abs(avgGreen - 7) <= threshold && abs(avgBlue - 18) <= threshold) {
      displayColor(0, 0, 255);  // Blue
      colorState = "Blue";
      Serial.println("Color Detected: Blue");
    }
  } else if (avgRed > avgBlue && avgGreen > avgBlue && avgRed > avgBlue && avgWhite > 35) {
    if (abs(avgRed - 39) <= threshold && abs(avgGreen - 24) <= threshold && abs(avgBlue - 13) <= threshold) {
      displayColor(100, 255, 200);  // Blue
      colorState = "Blue";
      Serial.println("Color Detected: Yellow");
    }
  } else {
    displayColor(255, 255, 255);  // No color detected
    colorState = "White/No Color Detected";
    Serial.println("Color Detected: None");
  }
}
