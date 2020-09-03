void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  int pir1 = digitalRead(2);
  int pir2 = digitalRead(3);
  Serial.print(pir1);
  Serial.print(", ");
  Serial.print(pir2);
  Serial.println();

  if (pir1 == HIGH || pir2 == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}
