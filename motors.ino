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
void runMotors(JsonObject value) {
  int direction = value[String("direction")];
  JsonArray pwm = value[String("pwm")];
  
  int fL = pwm[0];
  int fR = 0;
  int bL = 0;
  int bR = 0;

  Serial.println(fL);
}

/**
 * call from setup();
 */
void motorsSetup() {

}
