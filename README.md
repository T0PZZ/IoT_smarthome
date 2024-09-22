# IoT_smarthome  <img src="https://github.com/user-attachments/assets/df6c359c-0b14-4367-8a18-9761a3c0fe7a" width="100" height="100" align="right"> <img src="https://github.com/user-attachments/assets/181d8b14-c1d6-434c-a54f-86b5f8392630" width="100" height="100" align="right">
## Description 

This project uses an Arduino R4 WiFi Board and ArduinoCloud to simulate a smarthome. It can be controlled via Arduino Clound dashboard , or on 
Arduino IoT Cloud Remote app for mobile devices.

## Functionality 
<img src="https://github.com/user-attachments/assets/14d9953c-b391-4bb6-9357-d4eea15f8fed" width="100" height="100" align="right">
<img src="https://github.com/user-attachments/assets/09c51f34-3add-48a0-9a37-54ff7c9f834b" width="100" height="100" align="right">
<img src="https://github.com/user-attachments/assets/c845df46-6956-42ca-ad27-3f714f57903e" width="100" height="100" align="right">
<img src="https://github.com/user-attachments/assets/fe90af9d-39ee-4749-a26d-ca0868e09273" width="100" height="100" align="right">

1) Remote light control [^1]  
2) Dusk detection [^2] 
3) Dimming light [^3]
4) Automatic curtains [^4]
5) Door/Window alarm sensor [^5] 
6) Movement detection [^6]    
7) Anti-theft alarm [^7]  
8) Measuring temperature & humidity [^8]



---

   
 Use footnotes for more information 

[^1]: Simulates turning the light on/off in front of the building. 
[^2]: If it's dark, and PIR sensor signals movement then outdoor light is turned on.
[^3]: Simulates indoor light, which can be turned on/off or dimmed
[^4]: Automatic curtain simulation (DC motors moves both ways  until signal from edge detector)
[^5]: Checks state of the door/window if its either opened or closed
[^6]: PIR sensor detects movement outside of the building.
[^7]: When unarmed nothing changes. When armed it sends audio-visual signals (blinking light outside of the building and noisy beeping) to "scare off an intruder". Can be triggered by movement detection (PIR) or via door/window alarm sensor.
[^8]: Real time readings of temperature [Celcius degrees] and humidity [%].
___ 
### Dashboard 
<img src="https://github.com/user-attachments/assets/8f030152-c42f-45f5-97db-8d0630098eb7"  align="center">



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

<a href="https://www.flaticon.com/free-icons/motion-sensor" title="motion sensor icons">Motion sensor icons created by Freepik - Flaticon</a>
