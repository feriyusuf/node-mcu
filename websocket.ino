void webSocketSetup() {
  ws.onEvent(onEventWebSocket);
  server.addHandler(&ws);
}

void onEventWebSocket(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      Serial.println("Error WebSocket");
      break;
  }
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    wsMessage = (char*)data;
    notifyClients(wsMessage);
    componentHandler(wsMessage);
  }
}

// For notify others clients
void notifyClients(String message) {
  ws.textAll(message);
}

// Handling json string from client
void componentHandler(String jsonString) {
  DynamicJsonDocument doc(1024);

  // Store websocket message as json object
  deserializeJson(doc, jsonString);
  JsonObject obj = doc.as<JsonObject>();

  String component = obj[String("component")];
  JsonObject value = obj[String("value")];

  if (component == "motors") {
    runMotors(value);
    return;
  }
    
  if (component == "underlamp") {
    return;
  }

  // TODO: Control other components

  Serial.println("Unknown component to set");
}
