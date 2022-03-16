#include "DHT.h"

#define DHTPIN D5
#define DHTTYPE DHT11
#define ULTRA_ECHO_PIN D6
#define ULTRA_TRIGGER_PIN D7

DHT dht(DHTPIN, DHTTYPE);

void sensorsSetup() {
  // Humadity and Temperature Sensors
  dht.begin();

  // Ultra Sonic Distance Sensor
  pinMode(ULTRA_TRIGGER_PIN, OUTPUT);
  pinMode(ULTRA_ECHO_PIN, INPUT);
}

void sensorsLoop() {
    
}

float getHumadity() {
  return dht.readHumidity();
}

float getTemperature() {
  return dht.readTemperature();
}

long getDistance() {
  long duration, jarak;
  digitalWrite(ULTRA_TRIGGER_PIN, LOW);
  delayMicroseconds(2); 
  digitalWrite(ULTRA_TRIGGER_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(ULTRA_TRIGGER_PIN, LOW);
  duration = pulseIn(ULTRA_ECHO_PIN, HIGH);
  jarak = (duration/2) / 29.1;
  
  return jarak;
}
