// Place include library here
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <FS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <PCF8574.h>

/**
 * IO Used
 * D1 PCF8574
 * D2 PCF8574
 */


// IO Extender (PCF8574)
PCF8574 ioExtendOne(0x20);

void setup() {
  Serial.begin(9600);
  ioExtendOne.begin();
  
  wifiSetup();
//  pageSetup();
//  webSocketSetup();
  motorsSetup();
  udpSetup();  
//  sensorsSetup();
}

void loop() {
  udpLoop();
//  sensorsLoop();
}
