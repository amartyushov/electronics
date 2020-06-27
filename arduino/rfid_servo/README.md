# RFID RC522 + servo
[Source](https://lesson.iarduino.ru/page/kontrol-dostupa-rfid-rc522-servo-arduino/)
## Connection Arduino Uno + RC522

[Details](https://lesson.iarduino.ru/page/urok-6-arduino-schityvaem-metki-rfid-modul-rc522/)

| RC522 | Arduimo Uno |  
|----------------|:---------:|
| RST | 9 digital |
|SDA(SS)|10 digital|
|MOSI|11 digital (ICSP-4)|
|MISO|12 digital (ICSP-1)|
|SCK|13 digital (ICSP-3)|
|3.3V|3.3V|
|GND|GND|

## Connection passive buzzer

| buzzer | Arduimo Uno |  
|----------------|:---------:|
| VCC | 5V |
|GND|GND|
|IO|pin 5 digital|

## Connection servo

| servo | Arduimo Uno |  
|----------------|:---------:|
| red (central) | 5V |
|black/brown (left)|GND|
|white/orange (right)|pin 6 digital|

## Setup
Для того, что бы узнать UID карточки(Метки), необходимо записать данный скетч в arduino, собрать схему, изложенную выше, и открыть Консоль (Мониторинг последовательного порта). Когда вы поднесете метку к RFID, в консоли выведется номер.  

Полученный UID необходимо ввести в следующую строчку:

if (uidDec == 3763966293) // Сравниваем Uid метки, если он равен заданному то сервопривод открывает задвижку.
У каждой карточки данный идентификатор уникальный и не повторяется. Таком образом, когда вы поднесете карточку, идентификатор которой вы задали в программе, система откроет доступ с помощью сервопривода.

![pic](pic.png)






