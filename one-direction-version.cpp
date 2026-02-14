#include <Arduino.h>

// Pin Definitions
const int pirPin = 2;     // PIR sensor output
const int ledRows[] = {9, 10, 11}; // Pins for Row 1, 2, and 3
const int rowCount = 3;

// Timing Variables
int animationDelay = 500; // Time between each row (ms)
int stayOnTime = 3000;    // How long lights stay on total (ms)

void setup() {
  pinMode(pirPin, INPUT);
  for (int i = 0; i < rowCount; i++) {
    pinMode(ledRows[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    Serial.println("Motion Detected! Starting Animation...");
    
    // 1. Turn ON from Bottom to Top
    for (int i = 0; i < rowCount; i++) {
      digitalWrite(ledRows[i], HIGH);
      delay(animationDelay); 
    }

    // 2. Wait while the person (presumably) walks up
    delay(stayOnTime);

    // 3. Turn OFF from Bottom to Top (as requested)
    for (int i = 0; i < rowCount; i++) {
      digitalWrite(ledRows[i], LOW);
      delay(animationDelay);
    }
    
    Serial.println("Animation Complete.");
  }
}