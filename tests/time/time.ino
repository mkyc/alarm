#include <GSMSimTime.h>

// You can use any Serial interface. I recommended HardwareSerial. Please use the library with highiest baudrate.
// In examples, i used HardwareSerial. You can change it anymore.


#define RESET_PIN 10 // you can use any pin.


GSMSimTime dateTime(Serial1, RESET_PIN); // GSMSimTime inherit from GSMSimGPRS. You can use GSMSim and GSMSimGPRS methods with it.

void setup() {
  delay(3000);
  Serial1.begin(9600);

  while (!Serial1) {
    ; // wait for module for connect.
  }

  Serial.begin(9600);

  // Init module...
  dateTime.init(); // use for init module. Use it if you dont have any valid reason.

  Serial.print("Set Phone Function... ");
  Serial.println(dateTime.setPhoneFunc(1));
  //delay(1000);

  Serial.print("is Module Registered to Network?... ");
  Serial.println(dateTime.isRegistered());
  //delay(1000);

  Serial.print("Signal Quality... ");
  Serial.println(dateTime.signalQuality());
  //delay(1000);

  Serial.print("Operator Name... ");
  Serial.println(dateTime.operatorNameFromSim());
  //delay(1000);


  //Serial.print("GPRS Init... ");
  //Serial.println(dateTime.gprsInit("internet")); // Its optional. You can set apn, user and password with this method. Default APN: "internet" Default USER: "" Default PWD: ""
  //delay(1000);


  Serial.print("Connect GPRS... ");
  Serial.println(dateTime.connect());
  //delay(1000);

  Serial.print("Get IP Address... ");
  Serial.println(dateTime.getIP());
  delay(1000);


  Serial.print("Get module date time... ");
  Serial.println(dateTime.getRaw());
  delay(1000);

  char testDns[] = "AT+CDNSCFG=?";

  Serial.print("Test DNS... ");
  Serial.println(dateTime.sendATCommand(testDns));
  delay(1000);

  char setDns[] = "AT+CDNSCFG=\"8.8.8.8\",\"8.8.4.4\"";

  Serial.print("Set DNS... ");
  Serial.println(dateTime.sendATCommand(setDns));
  delay(1000);

  char getDns[] = "AT+CDNSCFG?";

  Serial.print("Get DNS... ");
  Serial.println(dateTime.sendATCommand(getDns));
  delay(1000);

  Serial.print("Set timezone and time server... ");
  Serial.println(dateTime.setServer(1, "0.pl.pool.ntp.org")); // timezone +3
  delay(1000);

  Serial.print("Sync date time from server... ");
  Serial.println(dateTime.syncFromServer());
  delay(1000);

  Serial.print("Get module date time after sycn... ");
  Serial.println(dateTime.getRaw());
  delay(1000);

  Serial.print("Close GPRS... ");
  Serial.println(dateTime.closeConn());
  //delay(1000);

  // For other methods please look at readme.txt file.

}

void loop() {
  updateSerial();
}

void updateSerial()
{
  delay(1000);
  bool got = false;
  while (Serial.available()) 
  { 
    got = true;
    String c = Serial.readString();
    Serial.print(c);
    Serial1.println(c);//Forward what Serial received to Software Serial Port
  }
  if(got) {
    Serial.println();
  }
  
  while(Serial1.available()) 
  {
    Serial.write(Serial1.read());//Forward what Software Serial received to Serial Port
  }
}
