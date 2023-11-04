#include "DHT.h"

///////////////////////////////
#define OUTDOOR_LIGHT_1 2    // Define the outdoor light 1 pin
#define OUTDOOR_LIGHT_2 3    // Define the outdoor light 2 pin
#define Magnetic_sensor 4    // Define the magnetic sensor pin
#define PIR_sensor A0        // Define the PIR sensor pin
#define Smoke_sensor 6       // Define the smoke sensor pin
#define Temperature_sensor 7 // Define the temperature sensor pin
#define AlarmToggle_Button 8 // Define the Alarm Button pin
#define Buzzer 9             // Define the buzzer pin
///////////////////////////////

#include "DHT.h"
DHT dht;
bool is_door_open = false;      // Define the door state variable
bool alarm_is_armed = false;    // Define the alarm state variable
bool movement_detected = false; // Define the movement detection variable
int alarm_state = 0;            // alarm armed =1 , disarmed = 0
int pir_read = 0;               // read from pin sensor
int previous_temperature = 0;   // previous temperature value
int previous_humidity = 0;      // previous humidity value
int humidity = 0;               // current humidity value
int temperature = 0;            // current  temperature value

////////////////////////////////

// Function to turn on the outdoor light
void light_outdoor_on()
{
    digitalWrite(OUTDOOR_LIGHT_1, HIGH);
    digitalWrite(OUTDOOR_LIGHT_2, HIGH);
    Serial.println("Outdoor lights turned on. ");
    delay(50);
}
// Function to turn off the outdoor light
void light_outdoor_off()
{
    digitalWrite(OUTDOOR_LIGHT_1, LOW);
    digitalWrite(OUTDOOR_LIGHT_2, LOW);
    Serial.println("Outdoor lights turned off. ");
    delay(50);
}
// Function to check if the door is open
void check_magnetic_sensor()
{
    if (digitalRead(Magnetic_sensor) == HIGH)
    {
        delay(100);
        is_door_open = true;
        Serial.println("Door has been opened.");
    }
    if (digitalRead(Magnetic_sensor) == LOW)
    {
        delay(100);
        is_door_open = false;
    }
}
// Function to toggle the alarm
void alarm_toggle()
{
    if (digitalRead(AlarmToggle_Button) == LOW && alarm_state == 0)
    {
        alarm_is_armed = true;
        delay(200);
        alarm_state = alarm_state + 1;
        Serial.println("Alarm armed.");
    }
    if (digitalRead(AlarmToggle_Button) == LOW && alarm_state == 1)
    {
        alarm_is_armed = false;
        delay(200);
        alarm_state = alarm_state - 1;
        Serial.println("Alarm disarmed.");
    }
}
// Fuction to detect movement via PIR sensor
void detect_movement()
{
     pir_read = analogRead(PIR_sensor);
     Serial.println(pir_read);
     delay(500);
    if (pir_read > 10)
    {
        movement_detected = true;
        Serial.println("Movement detected outside! ");
        delay(500);
    }
    if (pir_read < 10)
    {
        movement_detected = false;
        delay(500);
    }
}

// Function to generate sound using buzzer
// void buzzer()
// Function to control components while alarm is armed
void alarm()
{
     check_magnetic_sensor();
     detect_movement();
    if (alarm_is_armed == true && (movement_detected == true || is_door_open == true))
    {
        light_outdoor_on();
        // Buzzer
        //  Window shutter
        //  inside lights
    }
}
// Function to read temperature and humidity from DHT11 sensor
void read_DHT()
{
    humidity = dht.getHumidity();
    temperature = dht.getTemperature();
    if (previous_humidity != humidity || previous_temperature != temperature)
    {
        previous_humidity = humidity;
        previous_temperature = temperature;
        Serial.print("Temperatura (C): ");
        Serial.print(previous_temperature);
        Serial.print("     Humidity (%): ");
        Serial.println(previous_humidity);
        delay(200);
    }
}
////////////////////////////////

void setup()
{
    pinMode(OUTDOOR_LIGHT_1, OUTPUT);          // Set outdoor light 1 as output
    pinMode(OUTDOOR_LIGHT_2, OUTPUT);          // Set outdoor light 2 as output
    pinMode(Magnetic_sensor, INPUT_PULLUP);           // Set magnetic sensor as input
    pinMode(PIR_sensor, INPUT);                // Set the PIR sensor as input
    pinMode(Smoke_sensor, INPUT);              // Set the smoke sensor as input
    pinMode(Temperature_sensor, INPUT);        // Set the temperature sensor as input
    pinMode(AlarmToggle_Button, INPUT_PULLUP); // Set the AlarmToggle_button as input with pullup resistor
    // pinMode(PIR_sensor, INPUT);                // Set the PIR_sensor as input
    digitalWrite(PIR_sensor, LOW);             // Set PIR state as LOW
    dht.setup(Temperature_sensor);             // Setup temperature & humidity sensor
    analogWrite(PIR_sensor,0);
    Serial.begin(9600);
}

////////////////////////////////

void loop()
{
    
     alarm();
    // read_DHT();
     alarm_toggle();
   // detect_movement();
   // check_magnetic_sensor();
}