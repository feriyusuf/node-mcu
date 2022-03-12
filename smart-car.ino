#include <ESP8266WiFi.h>
#include <FS.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Wifi
const char* ssid     = "FYZone Portable";
const char* password = "numpangatuh";
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  pageSetup();
  wifiSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void wifiSetup() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void pageSetup() {
  delay(500);
  if (!SPIFFS.begin()){
    Serial.println("Failed to open file");
    return;
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/page/index.html");
  });
}
