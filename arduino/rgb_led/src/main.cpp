#include <Arduino.h>

#define RED 9  // 11 for blink, 9 for smooth
#define GREEN 10 // 12 for blink, 10 for smooth
#define BLUE 11  // 13 for blink, 11 for smooth

void ledsBlink() {
  digitalWrite(RED, HIGH); // включаем красный свет
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
 
  delay(1000); // устанавливаем паузу для эффекта
 
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH); // включаем зеленый свет
  digitalWrite(BLUE, LOW);
 
  delay(1000); // устанавливаем паузу для эффекта
 
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH); // включаем синий свет
 
  delay(1000); // устанавливаем паузу для эффекта
}

void ledsSmooth() {
   // плавное включение/выключение красного цвета
   for (int i = 0; i <= 255; i++) {
      analogWrite(RED, i);
      delay(2);
   }
   for (int i = 255; i >= 0; i--) {
      analogWrite(RED, i);
      delay(2);
   }

   // плавное включение/выключение зеленого цвета
   for (int i = 0; i <= 255; i++) {
      analogWrite(GREEN, i);
      delay(2);
   }
   for (int i = 255; i >= 0; i--) {
      analogWrite(GREEN, i);
      delay(2);
   }

   // плавное включение/выключение синего цвета
   for (int i = 0; i <= 255; i++) {
      analogWrite(BLUE, i);
      delay(2);
   }
   for (int i = 255; i >= 0; i--) {
      analogWrite(BLUE, i);
      delay(2);
   }
}

void setup() {
  pinMode(RED, OUTPUT);  // используем Pin11 для вывода
  pinMode(GREEN, OUTPUT); // используем Pin12 для вывода
  pinMode(BLUE, OUTPUT);  // используем Pin13 для вывода
}

void loop() {
  ledsSmooth();
}

