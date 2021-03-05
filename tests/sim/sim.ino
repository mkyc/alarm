void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);

  delay(1000);
  Serial.println("1");
  
  //Begin serial communication with Arduino and SIM800L
  Serial1.begin(9600);
  delay(1000);
  Serial.println("Initializing...");
  delay(1000);

  Serial1.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  Serial1.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  Serial1.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  Serial1.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
  Serial.println("... finished.");
}

void loop()
{ 
  updateSerial();
}

void updateSerial()
{
  delay(1000);
  while (Serial.available()) 
  { 
    Serial1.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(Serial1.available()) 
  {
    Serial.write(Serial1.read());//Forward what Software Serial received to Serial Port
  }
}
