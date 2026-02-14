#include <Arduino.h>

// Define Pins for Sensors
const int bottomSensor = 10;
const int topSensor = 11;

// Define Pins for Steps (LEDs)
int steps[] = {2, 3, 4, 5, 6}; 
int totalSteps = 5;

// Animation timing (in milliseconds)
int stepDelay = 300; 
int stayOnTime = 5000; 
int exitDelay = 2000; // Time to walk away from the sensor at the end

void setup() {
  for (int i = 0; i < totalSteps; i++) {
    pinMode(steps[i], OUTPUT);
  }
  pinMode(bottomSensor, INPUT);
  pinMode(topSensor, INPUT);
}

void loop() {
  // Check if someone is at the bottom
  if (digitalRead(bottomSensor) == HIGH) {
    ascendSequence();
  } 
  // Check if someone is at the top
  else if (digitalRead(topSensor) == HIGH) {
    descendSequence();
  }
}

void ascendSequence() {
  // Turn on one by one UP
  for (int i = 0; i < totalSteps; i++) {
    digitalWrite(steps[i], HIGH);
    delay(stepDelay); 
  }
  delay(stayOnTime);
  // Turn off one by one UP
  for (int i = 0; i < totalSteps; i++) {
    digitalWrite(steps[i], LOW);
    delay(stepDelay);
  }
  // Wait for the person to walk away from the top sensor
  delay(exitDelay); 
}

void descendSequence() {
  // Turn on one by one DOWN
  for (int i = totalSteps - 1; i >= 0; i--) {
    digitalWrite(steps[i], HIGH);
    delay(stepDelay);
  }
  delay(stayOnTime);
  // Turn off one by one DOWN
  for (int i = totalSteps - 1; i >= 0; i--) {
    digitalWrite(steps[i], LOW);
    delay(stepDelay);
  }
  // Wait for the person to walk away from the bottom sensor
  delay(exitDelay);
}








// #include <Arduino.h>

// // Define Pins for Sensors
// const int bottomSensor = 10;
// const int topSensor = 11;

// // Define Pins for Steps (LEDs)
// int steps[] = {2, 3, 4, 5, 6}; 
// int totalSteps = 5;

// // Animation timing (in milliseconds)
// int stepDelay = 300; // Time between each step lighting up
// int stayOnTime = 5000; // How long the stairs stay lit

// void setup() {
//   for (int i = 0; i < totalSteps; i++) {
//     pinMode(steps[i], OUTPUT);
//   }
//   pinMode(bottomSensor, INPUT);
//   pinMode(topSensor, INPUT);
// }

// void loop() {
//   // Check if someone is at the bottom
//   if (digitalRead(bottomSensor) == HIGH) {
//     ascendSequence();
//   } 
//   // Check if someone is at the top
//   else if (digitalRead(topSensor) == HIGH) {
//     descendSequence();
//   }
// }

// void ascendSequence() {
//   // Turn on one by one UP
//   for (int i = 0; i < totalSteps; i++) {
//     digitalWrite(steps[i], HIGH);
//     delay(stepDelay); 
//   }
//   delay(stayOnTime);
//   // Turn off one by one UP
//   for (int i = 0; i < totalSteps; i++) {
//     digitalWrite(steps[i], LOW);
//     delay(stepDelay);
//   }
// }

// void descendSequence() {
//   // Turn on one by one DOWN
//   for (int i = totalSteps - 1; i >= 0; i--) {
//     digitalWrite(steps[i], HIGH);
//     delay(stepDelay);
//   }
//   delay(stayOnTime);
//   // Turn off one by one DOWN
//   for (int i = totalSteps - 1; i >= 0; i--) {
//     digitalWrite(steps[i], LOW);
//     delay(stepDelay);
//   }
// }