int ledPin = 13;
int sensorPin = 7;
boolean currentSensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  currentSensorValue = digitalRead(sensorPin);
  Serial.println(currentSensorValue);

  if (currentSensorValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(2000);
  } else {
    digitalWrite(ledPin, LOW);
  }

  

}
