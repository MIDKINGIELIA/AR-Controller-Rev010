#include <Arduino.h>
#define BAT_CHECK 4
#define FLOW_485 5
#define POWER_CTR 7
#define LED_DATA 6
#define MOTOR_CTR 12

float battery_volt;
int SenseVolt;

void setup() {
  
  Serial.begin(115200);  
  pinMode(FLOW_485,OUTPUT);
  pinMode(POWER_CTR,OUTPUT);
  digitalWrite(POWER_CTR,HIGH);

}

void loop() {

  SenseVolt = analogRead(BAT_CHECK);
  battery_volt = (SenseVolt/4095)*3.286;

  Serial.println(battery_volt);
  delay(100);
}
