
void setup()  
{
  // Open serial communication
  Serial.begin(9600);

  // set the data rate for the SoftwareSerial port
  Serial1.begin(9600);

  delay(1000);
  Serial.println("Testing SIM800L module");
  Serial.println();
  Serial.print("Sizeof(Serial1) = "); Serial.println(sizeof(Serial1));
  Serial.println();

}

void loop() // run over and over
{

  while( Serial1.available() )
  {
    char c = Serial1.read();
    Serial.print(c);
  }

  if(Serial.available())
  {
    String Arsp = Serial.readString();

    Serial.println("Serial available");
    Serial.println(Arsp);
    Serial1.println(Arsp);
    Serial.println("Serial available end");
  }

}
