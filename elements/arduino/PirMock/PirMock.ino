bool ir1 = false;
bool ir2 = false;
bool ir3 = false;
bool ir4 = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  changeState();
  Serial.println("{\"IR1\":" + String(ir1) + ",\"IR2\":" + String(ir2) + ",\"IR3\":" + String(ir3) +",\"IR4\":" + String(ir4) + "}");
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void changeState() {
  int randNumber = random(10);
  switch (randNumber) {
  case 1:
    ir1 = !ir1;
    break;
  case 2:
    ir2 = !ir2;
    break;
  case 3:
    ir3 = !ir3;
    break;
  case 4:
    ir4 = !ir4;
    break;
  default:
    break;
  }
}
