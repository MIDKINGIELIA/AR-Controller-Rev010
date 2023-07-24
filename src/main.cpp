#include <Arduino.h>
#define BAT_CHECK 4
#define FLOW_485 5
#define POWER_CTR 7
#define LED_DATA 6
#define MOTOR_CTR 12


void setup() {
  
  // Serial.begin(115200); //USB가 사용하고 있음. -> F12에서 보면 
  Serial1.begin(115200,SERIAL_8N1,44,43); //PIN Rx 36, TX 37 아니면 IO = Rx 44,Tx 43 

  pinMode(FLOW_485,OUTPUT);
  pinMode(POWER_CTR,OUTPUT);
  digitalWrite(POWER_CTR,HIGH);
  
}

void loop() {
  
  // if(Serial1.available()){
  //   Serial.println("ok");
  //   delay(100);    
  // }

  // else {
  //   Serial.println("no");
  //   delay(100);
  // }

  Serial1.print('A');

  delay(100);

}
