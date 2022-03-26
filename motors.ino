#define RIGHT_MOTOR_FORWARD   P3  /* GPIO15(D8) -> IN1  */
#define RIGHT_MOTOR_BACKWARD  P2  /* GPIO13(D7) -> IN2  */
#define LEFT_MOTOR_FORWARD    P1  /* GPIO2(D2) -> IN3   */
#define LEFT_MOTOR_BACKWARD   P0  /* GPIO0(D3) -> IN4   */

#define RIGHT_MOTOR_ENABLE    D7  /* GPIO14(D5) -> Motor-A Enable */
#define LEFT_MOTOR_ENABLE     D8  /* GPIO12(D6) -> Motor-B Enable */

/**
 * call from setup();
 */
void motorsSetup() {
  ioExtendOne.pinMode(LEFT_MOTOR_FORWARD,  OUTPUT);
  ioExtendOne.pinMode(RIGHT_MOTOR_FORWARD,  OUTPUT);
  ioExtendOne.pinMode(LEFT_MOTOR_BACKWARD,  OUTPUT); 
  ioExtendOne.pinMode(RIGHT_MOTOR_BACKWARD,  OUTPUT);
  
  pinMode(LEFT_MOTOR_ENABLE,  OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE,  OUTPUT);
}

long runMotors(JsonArray value) {
  int direction = value[0];  
  int fl = value[1];
  int fr = value[2];
  int rl = value[3];
  int rr = value[4];

  if (getDistance() < 40 && direction == 0) {
    stopMotors();
    return getDistance();
  }

  if (fr == 0 && rr == 0) {    
    stopMotors();
    return getDistance();
  }

  if (direction == 0) {
    forward(fl,  fr,  rl,  rr);
  }

  if (direction == 1) {
    backward(fl,  fr,  rl,  rr);
  }

  Serial.println();
  Serial.print("Speed Front Left: ");
  Serial.println(fl);
  Serial.print("Speed Front Right: ");
  Serial.println(fr);
  Serial.println();

  return getDistance();
}

void forward (int fl,  int fr,  int rl,  int rr){
  analogWrite(LEFT_MOTOR_ENABLE,  rl);
  analogWrite(RIGHT_MOTOR_ENABLE,  rr);

  ioExtendOne.digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  ioExtendOne.digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  ioExtendOne.digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  ioExtendOne.digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
    
  neoAllRgb(0, 0, 127);
}

void backward (int fl,  int fr,  int rl,  int rr){
  analogWrite(LEFT_MOTOR_ENABLE,  fl);
  analogWrite(RIGHT_MOTOR_ENABLE,  fr);
  
  ioExtendOne.digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  ioExtendOne.digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  ioExtendOne.digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
  ioExtendOne.digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
  
  neoAllRgb(0, 100, 50);
}

void stopMotors(){
  digitalWrite(LEFT_MOTOR_ENABLE, LOW);
  digitalWrite(RIGHT_MOTOR_ENABLE, LOW);

  ioExtendOne.digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  ioExtendOne.digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  ioExtendOne.digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  ioExtendOne.digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

 neoAllRgb(127, 0, 0);
}
