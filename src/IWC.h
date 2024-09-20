#ifndef IWC_H
#define IWC_H

#include <ArduinoJson.h>
#include <Wire.h>

class IWC {
   public:
    IWC();
    bool begin();
    bool getData(float &humidity);
    bool getJSON(JsonDocument &doc);
};

#endif  // IWC_H