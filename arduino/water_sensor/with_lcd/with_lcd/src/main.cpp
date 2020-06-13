#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

int sensorValue = 0;
int sensorPin = A5;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2); 
  
  // Print a message to the LCD. 
  lcd.print("WATER LEVEL: "); 
}

void loop() {
  // set the cursor to column 0, line 1 
  lcd.setCursor(0, 1); 
    
  sensorValue = analogRead(sensorPin); //Read data from analog pin 
   
  if (sensorValue<=100) {
    lcd.println("Empty            "); 

  } else if (sensorValue>100 && sensorValue<=300) { 
    lcd.println("Low              "); 
  } else if (sensorValue>300 && sensorValue<=330) {
    lcd.println("Medium           "); 
  } else if (sensorValue>330) { 
    lcd.println("High             "); 
  }
  delay(1000); 
}