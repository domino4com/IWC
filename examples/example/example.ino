#include <ArduinoJson.h>
#include <Wire.h>
#ifndef TOUCH_SENSOR
#define TOUCH_SENSOR T1
#endif

#include <IWC.h>

IWC input;
float var1;
char s[] = "Soil Moisture: %.0f %%\n";

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nSensor Test\n");

    if (input.begin()) {
        Serial.println("Sensor initialized successfully.");
    } else {
        Serial.println("Failed to initialize sensor!");
        while (1);
    }
}

void loop() {
    float soil_moisture;

    if (input.getData(var1)) {
        Serial.printf(s, var1);
    } else {
        Serial.println("Failed to get data.");
    }

    delay(1000);
}