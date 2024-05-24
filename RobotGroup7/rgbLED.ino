int threshold = 4;
String colorState = "";

void color(int Red, int Green, int Blue, int Threshold, String color) {
  if ((avgRed + Threshold == Red) || (avgRed - Threshold == Red)) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
    colorState = "Red";

  } else if (avgGreen + Threshold == Green || avgGreen - Threshold == Green) {
    // Green detected
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
    colorState = "Green";

  } else if (avgBlue + Threshold == Blue || avgBlue - Threshold == Blue) {
    // Blue detected
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
    colorState = "Blue";

  } else {
    // No specific color detected
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
    colorState = "Black or White";

  }

  Serial.print("Color Detected is: ");
  Serial.println(colorState);
}



//    // Check if certain color conditions are met based on threshold values
//   if (avgRed > avgGreen && avgRed > avgBlue) {
//     // Red detected
//     digitalWrite(LED_R, HIGH);
//     digitalWrite(LED_G, LOW);
//     digitalWrite(LED_B, LOW);
//     colorState = "Red";
//   } else if (avgGreen > avgRed && avgGreen > avgBlue) {
//     // Green detected
//     digitalWrite(LED_R, LOW);
//     digitalWrite(LED_G, HIGH);
//     digitalWrite(LED_B, LOW);
//     colorState = "Green";
//   } else if (avgBlue > avgRed && avgBlue > avgGreen) {
//     // Blue detected
//     digitalWrite(LED_R, LOW);
//     digitalWrite(LED_G, LOW);
//     digitalWrite(LED_B, HIGH);
//     colorState = "Blue";
//   } else {
//     // No specific color detected
//     digitalWrite(LED_R, LOW);
//     digitalWrite(LED_G, LOW);
//     digitalWrite(LED_B, LOW);
//     colorState = "Black or White";
//   }



// Serial.print("Color Detected: ");
// Serial.println(colorState);