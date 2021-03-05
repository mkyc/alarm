#include <GSMSimHTTP.h>
#include <SoftwareSerial.h>

#define RESET_PIN 6 // you can use any pin.

SoftwareSerial ss(10, 11); // RX, TX

GSMSimHTTP http(ss, RESET_PIN, DEFAULT_LED_PIN, DEFAULT_LED_PIN, (Stream *)&Serial); // GSMSimHTTP inherit from GSMSimGPRS. You can use GSMSim and GSMSimGPRS methods with it.

void setup() {
  ss.begin(9600); // If you dont change module baudrate, it comes with auto baudrate.
  Serial.begin(9600); // Serial for debug...

  while (!ss);
  while (!Serial);

  // Init module...
  http.init(); // use for init module. Use it if you dont have any valid reason.

  Serial.print("Set Phone Function... ");
  Serial.println(http.setPhoneFunc(1));
  //delay(1000);

  Serial.print("is Module Registered to Network?... ");
  Serial.println(http.isRegistered());
  //delay(1000);

  Serial.print("Signal Quality... ");
  Serial.println(http.signalQuality());
  //delay(1000);

  Serial.print("Operator Name... ");
  Serial.println(http.operatorNameFromSim());
  //delay(1000);

  Serial.print("Init GPRS... ");
  http.gprsInit("www.mobilny.pl");
  //delay(1000);

  Serial.print("Connect GPRS... ");
  Serial.println(http.connect());
  //delay(1000);

  Serial.print("Get IP Address... ");
  Serial.println(http.getIP());
  delay(1000);

  Serial.print("Is GPRS connected ... ");
  Serial.println(http.isConnected());
  delay(1000);

  Serial.print("Get... ");
  Serial.println(http.get("httpbin.org/get", true));
  delay(1000);

  Serial.print("Close GPRS... ");
  Serial.println(http.closeConn());
  //delay(1000);

  // For other methods please look at readme.txt file.

}

void loop() {
  updateSerial();
}

void updateSerial()
{
  delay(1000);
  while (Serial.available()) 
  { 
    ss.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  
  while(ss.available()) 
  {
    Serial.write(ss.read());//Forward what Software Serial received to Serial Port
  }
}

void initialize() {
  
}
