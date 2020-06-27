#include <Arduino.h>
#include <MFRC522.h> // библиотека "RFID".
#include <ServoC.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp; // для храниения номера метки в десятичном формате
ServoC servo;


void fromToDegreesClockwise(int from, int to) {
  for (int position = from; position <= to; position += 10) {
    // in steps of 1 degree
    servo.write(position);              // tell servo to go to positionition in variable 'position'
    delay(15);                       // waits 15ms for the servo to reach the positionition
  }
}

void fromToDegreesContrClockwise(int from, int to) {
  for (int position = from; position >= to; position -= 10) {
    // in steps of 1 degree
    servo.write(position);              // tell servo to go to positionition in variable 'position'
    delay(15);                       // waits 15ms for the servo to reach the positionition
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Waiting for card...");
  SPI.begin();        //  инициализация SPI / Init SPI bus.
  mfrc522.PCD_Init(); // инициализация MFRC522 / Init MFRC522 card.
  servo.attach(6);
  servo.write(0); // устанавливаем серву в закрытое состояние
}

void loop()   {
  // Поиск новой метки
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Выбор метки
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  uidDec = 0;
  // Выдача серийного номера метки.
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec * 256 + uidDecTemp;
  }

  Serial.println("Card UID: ");
  Serial.println(uidDec); // Выводим UID метки в консоль.
  if (uidDec == 1808135450) { // Сравниваем Uid метки, если он равен заданому то серва открывает.
    tone(5, 200, 500); // Делаем звуковой сигнал, Открытие

    fromToDegreesClockwise(0, 180);
    fromToDegreesContrClockwise(180, 0);

    tone(5, 500, 500); // Делаем звуковой сигнал,  Закрытие
  }
}

