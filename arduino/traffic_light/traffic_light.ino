int led_red = 2;
int led_yellow = 3;
int led_green = 4;

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
}

void loop() {
  digitalWrite(led_red, HIGH);
    delay(1000);
  digitalWrite(led_yellow, HIGH);
    delay(200);
  
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
    delay(1000);
  
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_green, LOW);
    delay(200);
  digitalWrite(led_yellow, LOW); 
}
