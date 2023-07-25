#include <Arduino.h>
#define BAT_CHECK 4
#define FLOW_485 5
#define POWER_CTR 7
#define LED_DATA 6
#define MOTOR_CTR 12
#define Trig_SW 42
#define Check_SW 41

int Trig, Check =0;



void setup() {
  

  

  Serial.begin(115200); //USB가 사용하고 있음. -> F12에서 보면 

  pinMode(POWER_CTR,OUTPUT);
  pinMode(Trig_SW,INPUT);
  pinMode(Check_SW,INPUT);

  digitalWrite(POWER_CTR,HIGH);
  
  
}

void loop() {


  Trig = digitalRead(Trig_SW);
  Check =digitalRead(Check_SW);

  Serial.print(Trig);
  Serial.print(Check);

  delay(1000);
}


