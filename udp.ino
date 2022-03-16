// UDP
WiFiUDP UDP;
char packet[255];
char reply[] = "Packet received!";

void udpLoop() {
  int packetSize = UDP.parsePacket();
  if (packetSize) {
    int len = UDP.read(packet, 255);
    if (len > 0)
    {
      packet[len] = '\0';
    }

    DynamicJsonDocument doc(1024);

    // Store websocket message as json object
    deserializeJson(doc, packet);
    JsonObject obj = doc.as<JsonObject>();
  
    String component = obj[String("component")];
    JsonArray value = obj[String("value")];
  
    if (component == "motors") {
      runMotors(value);
      return;
    }
      
    if (component == "underlamp") {
      return;
    }

    // Send return packet
    UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
    UDP.write(reply);
    UDP.endPacket();
  }
}

void udpSetup() {
  // Begin Listening to UDP
  UDP.begin(UDP_PORT);
  Serial.print("Listening on UDP port ");
  Serial.println(UDP_PORT);
}
