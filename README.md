<img src="assets/IWC.svg" width=200 align="right">

# IWC - Input Weather C - Soil Moisture Sensor
This is a Weather Sensor measuring Soil Moisture
| Specifications | |
| --: | :--: |
| Communication | Analog |
| Type | [Capacitive](https://en.wikipedia.org/wiki/Capacitive_sensing) |
| [CWS pin](https://github.com/domino4com/CWS) | T2 (GPIO2) |

## Arduino Code Example
```c
    int soilmoisture = map(touchRead(T2), 0, 25, 100, 0);
```
### Links
- [map](https://www.arduino.cc/reference/en/language/functions/math/map/)
- [touchRead](https://randomnerdtutorials.com/esp32-touch-pins-arduino-ide/)

# License: 
<img src="assets/CC-BY-NC-SA.png" width=200 align="right">
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

[View License Deed](https://creativecommons.org/licenses/by-nc-sa/4.0/) | [View Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
