#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//int position = 0;    // variable to store the servo positionition

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  fromToDegreesClockwise(0, 180);
  fromToDegreesContrClockwise(180, 0);
}


void fromToDegreesClockwise(int from, int to) {
  for (int position = from; position <= to; position += 1) {
    // in steps of 1 degree
    myservo.write(position);              // tell servo to go to positionition in variable 'position'
    delay(15);                       // waits 15ms for the servo to reach the positionition
  }
}

void fromToDegreesContrClockwise(int from, int to) {
  for (int position = from; position >= to; position -= 1) {
    // in steps of 1 degree
    myservo.write(position);              // tell servo to go to positionition in variable 'position'
    delay(15);                       // waits 15ms for the servo to reach the positionition
  }
}
