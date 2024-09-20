#include <ArduinoJson.h>
#include <Wire.h>
#ifndef TOUCH_SENSOR
#define TOUCH_SENSOR T1
#endif

#include "IWC.h"  // Change here
IWC input;        // And here

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nJSON Test\n");

    if (input.begin()) {
        Serial.println("Input sensor initialized successfully.");
    } else {
        Serial.println("Failed to initialize input sensor!");
        while(1);
    }
}

void loop() {
    JsonDocument root;

    if (input.getJSON(root)) {
        serializeJsonPretty(root, Serial);
        Serial.println();
    } else {
        Serial.println("Failed to get input data.");
    }

    delay(1000);
}
