#include <Arduino.h>

int waterLevel;


void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600); // connect monitoring
}

void loop() {
  waterLevel = analogRead(A0);
  Serial.println(waterLevel);

  delay(1000); 
}