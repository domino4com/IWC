#include <ArduinoJson.h>
#include <Wire.h>
#ifndef TOUCH_SENSOR
#define TOUCH_SENSOR T1
#endif

#include <IWC.h>

IWC IWC;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nIWC Test\n");

    if (IWC.begin()) {
        Serial.println("IWC sensor initialized successfully.");
    } else {
        Serial.println("Failed to initialize IWC sensor!");
        while(1);
    }
}

void loop() {
    float soil_moisture;

    if (IWC.getData(soil_moisture)) {
        Serial.printf("Soil Moisture: %.2f%%\n", soil_moisture);
    } else {
        Serial.println("Failed to IWC data.");
    }

    delay(1000);
}