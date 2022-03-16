// Wifi
#define WIFI_SSID "FYZone Portable"
#define WIFI_PASSWORD "numpangatuh"
#define UDP_PORT 4210

// Web Server and Web Socket
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
String wsMessage = "";

void wifiSetup() {
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
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
