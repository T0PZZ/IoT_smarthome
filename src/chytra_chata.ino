#include "DHT.h"

///////////////////////////////
#define OUTDOOR_LIGHT_1 2    // Define the outdoor light 1 pin
#define OUTDOOR_LIGHT_2 3    // Define the outdoor light 2 pin
#define Magnetic_sensor 4    // Define the magnetic sensor pin
#define PIR_sensor 5         // Define the PIR sensor pin
#define Smoke_sensor 6       // Define the smoke sensor pin
#define Temperature_sensor 7 // Define the temperature sensor pin
#define AlarmToggle_Button 8 // Define the Alarm Button pin
#define Buzzer 9             // Define the buzzer pin
///////////////////////////////

#include "DHT.h"
DHT dht;
bool is_door_open = false;   // Define the door state variable
bool alarm_is_armed = false; // Define the alarm state variable
bool movement_detected = false;
int alarm_state = 0;
int pir_read = 0;

////////////////////////////////

// Function to turn on the outdoor light
void light_outdoor_on()
{
    digitalWrite(OUTDOOR_LIGHT_1, HIGH);
    digitalWrite(OUTDOOR_LIGHT_2, HIGH);
}
// Function to turn off the outdoor light
void light_outdoor_off()
{
    digitalWrite(OUTDOOR_LIGHT_1, LOW);
    digitalWrite(OUTDOOR_LIGHT_2, LOW);
}
// Function to check if the door is open
void check_magnetic_sensor()
{
    if (digitalRead(Magnetic_sensor) == HIGH)
    {
        is_door_open = true;
    }
    if (digitalRead(Magnetic_sensor) == LOW)
    {
        is_door_open = false;
    }
}
// Function to toggle the alarm
void alarm_toggle()
{
    if (digitalRead(AlarmToggle_Button) == HIGH && alarm_state == 0)
    {
        alarm_is_armed = true;
        delay(50);
        alarm_state = alarm_state + 1;
    }
    if (digitalRead(AlarmToggle_Button) == HIGH && alarm_state == 1)
    {
        alarm_is_armed = false;
        delay(50);
        alarm_state = alarm_state - 1;
    }
}
// Fuction to detect movement via PIR sensor
void detect_movement()
{
    pir_read = analogRead(PIR_sensor);
    if (pir_read > 700)
    {
        movement_detected = true;
    }
    if (pir_read < 700)
    {
        movement_detected = false;
    }
}

// Function to generate sound using buzzer
// void buzzer()
// Function to control components while alarm is armed
void alarm()
{
    check_magnetic_sensor();
    // check_pir() ? xd
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
    int humidity = dht.getHumidity();
    int temperature = dht.getTemperature();
}
////////////////////////////////

void setup()
{
    pinMode(OUTDOOR_LIGHT_1, OUTPUT);          // Set outdoor light 1 as output
    pinMode(OUTDOOR_LIGHT_2, OUTPUT);          // Set outdoor light 2 as output
    pinMode(Magnetic_sensor, INPUT);           // Set magnetic sensor as input
    pinMode(PIR_sensor, INPUT);                // Set the PIR sensor as input
    pinMode(Smoke_sensor, INPUT);              // Set the smoke sensor as input
    pinMode(Temperature_sensor, INPUT);        // Set the temperature sensor as input
    pinMode(AlarmToggle_Button, INPUT_PULLUP); // Set the AlarmToggle_button as input with pullup resistor
    pinMode(PIR_sensor, INPUT);                // Set the PIR_sensor as input
    digitalWrite(PIR_sensor, LOW);             // Set PIR state as LOW
    dht.setup(Temperature_sensor);             // Setup temperature & humidity sensor
}

////////////////////////////////

void loop()
{
    alarm_toggle();
    alarm();
}