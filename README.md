# IoT_smarthome ![image](https://github.com/user-attachments/assets/df6c359c-0b14-4367-8a18-9761a3c0fe7a)


## Description 
This project uses an Arduino R4 WiFi Board and ArduinoCloud to simulate a smarthome. It can be controlled via Arduino Clound dashboard , or on 
Arduino IoT Cloud Remote app for mobile devices.

## Functionality 

1) Remote light control [^1]
2) Dusk detection [^2]
3) Dimming light [^3]
4) Automatic curtains [^4]
5) Door/Window alarm sensor [^5]
6) Movement detection [^6]
7) Anti-theft alarm [^7] 
8) Measuring temperature & humidity [^8]
   
<center>                   Use footnotes for more information </center>

[^1]: Simulates turning the light on/off in front of the building. 
[^2]: If it's dark, and PIR sensor signals movement then outdoor light is turned on.
[^3]: Simulates indoor light, which can be turned on/off or dimmed
[^4]: Automatic curtain simulation (DC motors moves both ways  until signal from edge detector)
[^5]: Checks state of the door/window if its either opened or closed
[^6]: PIR sensor detects movement outside of the building.
[^7]: When unarmed nothing changes. When armed it sends audio-visual signals (blinking light outside of the building and noisy beeping) to "scare off an intruder". Can be triggered by movement detection (PIR) or via door/window alarm sensor.
[^8]: Real time readings of temperature [Celcius degrees] and humidity [%].
___ 
   

## Libraries
```
#include "thingProperties.h" 
#include "DHT.h"            
```
```DHT.h``` library handles humidity & temperature sensor *DHT11*. Whereas ```thingProperties.h``` handles validation, connection and data transmission between UnoR4 board and Arduino IoT Cloud. 

## Component list:
| Component name | Model name | Amount |
|---|:---:|---| 
| Arduino Uno | Uno R4 WiFi|  1 |
| Humidity & temperature sensor| DHT11  |1|
| PIR sensor | HC-SR505 |1|
| Magnetic Sensor| CMD1423| 1|
| Edge detector |WK601|2|
|Breadboard|-|2|
| LED diode white|-| 3|
|DC Motor driver|L298N|1|
| 4x AA Battery Case|-| 1|
| AA Battery| - | 4|
| 5V DC motor 48:1 gear ratio|-| 1 |
|5-10 kOhm Photoresistor| GL5616 | 1 | 
|Buzzer | any | 1| 

