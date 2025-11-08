//#include "include/WiFi/WiFi.h"
//#include "include/esp32/Arduino.h"

// FreeRTOS API needed for vTaskDelay used in app_main
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

const char* ssid = "";
const char* password = "";

void setup() {
 /* Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }lear
  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Gateway (Router IP): ");
  Serial.println(WiFi.gatewayIP()); // Get router's IP address*/
}

/*void app_main(void) {
  // Empty loop
}*/

// app_main must use C linkage so the C startup code can find it.
extern "C" void app_main(void) {
  // Call Arduino-style setup once, then repeatedly call loop()
  /*setup();

  while (true) {
    loop();
    // Give other tasks CPU time
    vTaskDelay(pdMS_TO_TICKS(10));
  }*/
}