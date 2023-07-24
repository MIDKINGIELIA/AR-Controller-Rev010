#include <Arduino.h>
#define BAT_CHECK 4
#define FLOW_485 5
#define POWER_CTR 7
#define LED_DATA 6
#define MOTOR_CTR 12


void setup() {
  
  pinMode(FLOW_485,OUTPUT);
  pinMode(POWER_CTR,OUTPUT);
  digitalWrite(POWER_CTR,HIGH);

}

void loop() {

  tone(MOTOR_CTR,500,500);
  delay(500);
  tone(MOTOR_CTR,600,500);
  delay(500);
  tone(MOTOR_CTR,700,500);
  delay(500);
  tone(MOTOR_CTR,800,500);
  delay(500);
}
