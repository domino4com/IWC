#include "IWC.h"
#include "driver/touch_sensor.h"
#ifndef TOUCH_SENSOR
#define TOUCH_SENSOR T1
#endif

#define MINIMUM_TOUCH_VALUE 3E4
#define START_TOUCH_VALUE 2E4
#define END_TOUCH_VALUE 23E5

IWC::IWC() {
}

bool IWC::begin() {
    touch_value_t h = touchRead(TOUCH_SENSOR);
    if (h < MINIMUM_TOUCH_VALUE) return false;
    return true;
}

bool IWC::getData(float &humidity) {
    touch_value_t h = touchRead(TOUCH_SENSOR);
    if (h < MINIMUM_TOUCH_VALUE) return false;
    humidity = map(h, START_TOUCH_VALUE, END_TOUCH_VALUE, 0, 100);
    return true;  // Return true for successful read (add error handling if needed)
}

bool IWC::getJSON(JsonDocument &doc) {
    float humidity;
    if (!getData(humidity)) return false;

    JsonArray dataArray = doc["IWC"].to<JsonArray>();

    JsonObject dataSet = dataArray.add<JsonObject>();  // First data set
    dataSet["name"] = "Soil Moisture";
    dataSet["value"] = humidity;
    dataSet["unit"] = "%";

    return true;
}
