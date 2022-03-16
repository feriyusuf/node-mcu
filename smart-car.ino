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
 * D3 Speed Motor Left
 * D4 Speed Motor Right
 * D5 Humadity and Temperature Sensor
 * D6 Distance Input
 * D7 Distance Output
 */


// IO Extender (PCF8574)
PCF8574 ioExtendOne(0x20);

void setup() {
  Serial.begin(9600);
  sensorsSetup();
  wifiSetup();
  pageSetup();
//  webSocketSetup();
  motorsSetup();
  udpSetup();
}

void loop() {
  sensorsLoop();
  udpLoop();
}
