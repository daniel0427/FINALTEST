#include <Ultrasonic.h>
#include <LWiFi.h>
#include <WiFiClient.h>
#include "MCS.h"


#define _SSID "Xresm"
#define _KEY  "bnw88427"
MCSDevice mcs("DAS0g5tq", "MTIBcd5X2uouuSJz");
MCSDisplayFloat Distance("Distance");

Ultrasonic ultrasonic(12, 13);
int distance;

void setup() {
  Serial.begin(9600);
  mcs.addChannel(Distance);
  while (WL_CONNECTED != WiFi.status())
  {
    Serial.print("WiFi.begin(");
    Serial.print(_SSID);
    Serial.print(",");
    Serial.print(_KEY);
    Serial.println(")...");
    WiFi.begin(_SSID, _KEY);
  }
  Serial.println("WiFi connected !!");
   while (!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");
  
}

void loop() {
  
  distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  Distance.set(distance);
  delay(1000);
}
