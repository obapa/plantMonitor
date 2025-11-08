#include "include/WiFi/WiFi.h"
#include <WiFi.h>
#include "include/esp32/Arduino.h"

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"


const char* ssid = "aaa";
const char* password = "sss";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //clear
  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  //Serial.println(WiFi.localIP());
  Serial.print("Gateway (Router IP): ");
  //Serial.println(WiFi.gatewayIP()); // Get router's IP address
}

// app_main must use C linkage so the C startup code can find it.
extern "C" void app_main(void) {
    setup();
}