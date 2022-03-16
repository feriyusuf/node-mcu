#define ENA_LEFT D3
#define ENA_RIGHT D4

#define IN_LEFT_1 P0
#define IN_LEFT_2 P1
#define IN_RIGHT_1 P2
#define IN_RIGHT_2 P3

/**
 * call from setup();
 */
void motorsSetup() {
  pinMode(ENA_LEFT, OUTPUT);
  pinMode(ENA_RIGHT, OUTPUT);

  ioExtendOne.pinMode(IN_LEFT_1, OUTPUT);
  ioExtendOne.pinMode(IN_LEFT_2, OUTPUT);
  ioExtendOne.pinMode(IN_RIGHT_1, OUTPUT);
  ioExtendOne.pinMode(IN_RIGHT_2, OUTPUT);
}

void runMotors(JsonArray value) {
  int direction = value[0];  
  int fl = value[1];
  int fr = value[2];
  int rl = value[3];
  int rr = value[4];

  if (direction == 0) {
    forward(fl, fr, rl, rr);
    Serial.println();
    Serial.println("Forward");
  }

  if (direction == 1) {
    backward(fl, fr, rl, rr);
    Serial.println("Backward");
  }

  Serial.print("Speed Front Left: ");
  Serial.println(fl);
  Serial.print("Speed Front Right: ");
  Serial.println(fr);
  Serial.print("Speed Rear Left: ");
  Serial.println(rr);
  Serial.print("Speed Rear Right: ");
  Serial.println(rl);
  
}

void forward(int fl, int fr, int rl, int rr) {
  // Direction
  ioExtendOne.digitalWrite(IN_LEFT_1, HIGH);
  ioExtendOne.digitalWrite(IN_RIGHT_1, HIGH);
  ioExtendOne.digitalWrite(IN_LEFT_2, LOW);
  ioExtendOne.digitalWrite(IN_RIGHT_2, LOW);

  // PWM
  analogWrite(ENA_LEFT, fl);
  analogWrite(ENA_RIGHT, fr);

  stopMotors();
}

void backward(int fl, int fr, int tl, int rr) {
 // Direction
  ioExtendOne.digitalWrite(IN_LEFT_1, LOW);
  ioExtendOne.digitalWrite(IN_RIGHT_1, LOW);
  ioExtendOne.digitalWrite(IN_LEFT_2, HIGH);
  ioExtendOne.digitalWrite(IN_RIGHT_2, HIGH);

  // PWM
  analogWrite(ENA_LEFT, fl);
  analogWrite(ENA_RIGHT, fr);

  stopMotors();
}

void stopMotors() {
   ioExtendOne.digitalWrite(IN_LEFT_1, LOW);
   ioExtendOne.digitalWrite(IN_RIGHT_1, LOW);
   ioExtendOne.digitalWrite(IN_LEFT_2, LOW);
   ioExtendOne.digitalWrite(IN_RIGHT_2, LOW);
   
   digitalWrite(ENA_LEFT, LOW);
   digitalWrite(ENA_RIGHT, LOW);

   Serial.println("Stop");
}
