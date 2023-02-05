/*
  IOT Button
  Maxime MOREILLON

  Board type: Generic ESP8266
  SSL support: Basic

*/

#include "IotKernel.h"



// Information to identify the device
#define DEVICE_TYPE "button"
#define DEVICE_FIRMWARE_VERSION "0.2.2"

// IO
#define LED_PIN 2
#define BUTTON_PIN 0


IotKernel iot_kernel(DEVICE_TYPE, DEVICE_FIRMWARE_VERSION);

void setup() {

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  iot_kernel.init();


}



void loop() {
  iot_kernel.loop();
  if (readButtonDebounce(BUTTON_PIN)) mqtt_publish_pressed();
}
