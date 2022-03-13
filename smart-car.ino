// Place include library here
#include <ESP8266WiFi.h>
#include <FS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

// Wifi
const char* ssid     = "FYZone Portable";
const char* password = "numpangatuh";

// Web Server and Web Socket
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
String wsMessage = "";

void setup() {
  Serial.begin(9600);
  wifiSetup();
  pageSetup();
  webSocketSetup();
  motorsSetup();
}