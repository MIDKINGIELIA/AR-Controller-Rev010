#include <Arduino.h>
#define BAT_CHECK 4
#define FLOW_485 5
#define POWER_CTR 7
#define LED_DATA 6
#define MOTOR_CTR 12
#define Trig_SW 42
#define Check_SW 41




int Trig, Check =0;


RTC_DATA_ATTR int bootCount = 0;




void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason)
  {
    case 1  : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case 2  : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case 3  : Serial.println("Wakeup caused by timer"); break;
    case 4  : Serial.println("Wakeup caused by touchpad"); break;
    case 5  : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.println("Wakeup was not caused by deep sleep"); break;
  }
}



void setup() {
  

  

  Serial.begin(115200); //USB가 사용하고 있음. -> F12에서 보면 
  pinMode(POWER_CTR,OUTPUT);
  pinMode(Trig_SW,INPUT);
  pinMode(Check_SW,INPUT);

  digitalWrite(POWER_CTR,HIGH);

  delay(1000); 

  //Increment boot number and print it every reboot
  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));

  //Print the wakeup reason for ESP32
  print_wakeup_reason();

  //Configure GPIO33 as ext0 wake up source for HIGH logic level
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_0,0); //BootPin.으로 Test 진행 누르면 Sleep Mode에서 빠져나오게 됨.

  //Go to sleep now
    esp_deep_sleep_start();
  
  
  
}
void loop() {}

