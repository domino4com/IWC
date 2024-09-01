<img src="assets/IWC.svg" width=200 align="right">

# IWC - Input Weather C - Soil Moisture Sensor
This is a Weather Sensor measuring Soil Moisture
| Specifications | |
| --: | :--: |
| Communication | Analog |
| Type | [Capacitive](https://en.wikipedia.org/wiki/Capacitive_sensing) |
| [CWA V1 pin](https://github.com/domino4com/CWA) | T2 (GPIO2) |
| [CWA V2 pin](https://github.com/domino4com/CWA) | T1 (GPIO1) |
| [CWV V1-V4 pin](https://github.com/domino4com/CWV) | T8 (GPIO33) |

## Arduino Code Example
### Generic, such as CWA v1 and CWV
```c
    int soilmoisture = map(touchRead(T2), 0, 25, 100, 0);
```
### CWA v2
```c
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nIWC");
}

void loop() {
  touch_value_t h = touchRead(T1);
  if (h > 3E4) {
    int p = map(h, 2E4, 23E5, 0, 100);
    Serial.print(p);
    Serial.print("%");
    if (p > 100) Serial.print(" - IWC inserted above the limit line!");
  } else {
    Serial.print("No IWC!");
  }
  Serial.println();
  delay(100);
}
```


## MicroPython Code Example
```Python
from machine import TouchPad, Pin
import time

touch_pin = TouchPad(Pin(2, mode=Pin.IN))
while True:
    touch_value = touch_pin.read()
    print(touch_value)
    time.sleep_ms(500)
```

### Links
- [map](https://www.arduino.cc/reference/en/language/functions/math/map/)
- [touchRead](https://randomnerdtutorials.com/esp32-touch-pins-arduino-ide/)
- [Espressif](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/touch.html)

# License: 
<img src="assets/CC-BY-NC-SA.png" width=200 align="right">
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

[View License Deed](https://creativecommons.org/licenses/by-nc-sa/4.0/) | [View Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
