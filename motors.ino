/**
 * Running motors based on value
 * JsonObject value
 {
    "component": "motors",
    "value": {
        "direction": 0,             --> or 1 to backward
        "pwm": [255, 255, 255, 255] --> [front-left, ]
    }
  }
 */
void runMotors(JsonArray value) {
  int direction = value[0];  
  int fl = value[1];
  int fr = value[2];
  int rl = value[3];
  int rr = value[4];

  Serial.println("\n==========================");
  Serial.println(direction);
  Serial.println(fl);
  Serial.println(fr);
  Serial.println(rl);
  Serial.println(rr);
  Serial.println("==========================\n");
  
}

/**
 * call from setup();
 */
void motorsSetup() {

}
