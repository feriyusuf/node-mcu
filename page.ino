void loop() {
  // put your main code here, to run repeatedly:
}


void pageSetup() {
  if (!SPIFFS.begin()){
    Serial.println("Failed to open file");
    return;
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/page/index.html");
  });
}
