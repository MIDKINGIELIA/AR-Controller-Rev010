#include <Arduino.h>
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#define BAT_CHECK 4
#define FLOW_485 5
#define POWER_CTR 7
#define LED_DATA 6
#define MOTOR_CTR 12
#include <esp_bt.h>
#include <esp_bt_main.h>
#include <esp_sleep.h>

#define WAKEUP_GPIO_PIN GPIO_NUM_2  // Choose any GPIO pin that supports ext0 wake-up

void setup() {
  Serial.begin(115200);
  SerialBT.begin("PARKGIBUM");

}

void loop() {
  // This code is not executed since the ESP32 is in deep sleep
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  if(SerialBT.available()){
    Serial.write(SerialBT.read());
  }
  delay(20);
}





  // Serial.begin(115200);

  // // Initialize Bluetooth
  // esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
  // esp_bt_controller_init(&bt_cfg);
  // esp_bt_controller_enable(ESP_BT_MODE_BTDM);

  // // Set the GPIO pin as an input for ext0 wake-up
  // pinMode(WAKEUP_GPIO_PIN, INPUT_PULLUP);

  // // Enable wake-up using Bluetooth connection
  // esp_sleep_enable_ext1_wakeup(BIT64(ESP_BT_GAP_WAKEUP_EXT1));

  // // Print message and go to sleep
  // Serial.println("Going to sleep, waiting for Bluetooth connection...");
  // Serial.flush();
  // esp_deep_sleep_start();
