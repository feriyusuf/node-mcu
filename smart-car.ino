// Place include library here
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <FS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

// Wifi
#define WIFI_SSID "FYZone Portable"
#define WIFI_PASSWORD "numpangatuh"
#define UDP_PORT 4210

// UDP
WiFiUDP UDP;
char packet[255];
char reply[] = "Packet received!";

// Web Server and Web Socket
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
String wsMessage = "";

void setup() {
  Serial.begin(9600);
  wifiSetup();
  pageSetup();
//  webSocketSetup();
  motorsSetup();
  udpSetup();
}

void loop() {
  udpLoop();
}
