#main

idf_component_register(
    SRCS
        "main.cpp"
        #"include/WiFi/WiFi.cpp"
        #"include/esp32/Arduino.cpp"
    INCLUDE_DIRS 
        #"include"
        #"include/WiFi"
        "."
        "include"
    REQUIRES 
        WiFi 
        esp32
)