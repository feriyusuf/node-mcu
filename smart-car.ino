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
 * D3 --
 * D4 NeoPixel Input
 * D5 Humadity & Temperature Sensor
 * D6 Ultrasonic Echo (Output)
 * D7 Motor Right
 * D8 Notor Left
 * 
 * 0x20 P0 Motor Left Backward
 * 0x20 P1 Motor Left Forward
 * 0x20 P2 Motor Right Backward
 * 0x20 P3 Motor Right Forward
 * 0x20 P4 Ultra Sonic Trigger (Input)
 */


// IO Extender (PCF8574)
PCF8574 ioExtendOne(0x20);

void setup() {
  Serial.begin(9600);
  ioExtendOne.begin();
  
  wifiSetup();
  sensorsSetup();
  motorsSetup();
  lampsSetup();
  udpSetup();  
}

void loop() {
  udpLoop();
}
