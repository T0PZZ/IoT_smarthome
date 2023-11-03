#define OUTDOOR_LIGHT_1 2    // Define the outdoor light 1 pin
#define OUTDOOR_LIGHT_2 3    // Define the outdoor light 2 pin
#define Magnetic_sensor 4    // Define the magnetic sensor pin
#define PIR_sensor 5         // Define the PIR sensor pin
#define Smoke_sensor 6       // Define the smoke sensor pin
#define Temperature_sensor 7 // Define the temperature sensor pin

////////////////////////////////

bool is_door_open = false; // Define the door state variable

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

////////////////////////////////

void setup()
{
    pinMode(OUTDOOR_LIGHT_1, OUTPUT); // Set outdoor lights as outputs
    pinMode(OUTDOOR_LIGHT_2, OUTPUT);
    pinMode(Magnetic_sensor, INPUT);    // Set magnetic sensor as input
    pinMode(PIR_sensor, INPUT);         // Set the PIR sensor as input
    pinMode(Smoke_sensor, INPUT);       // Set the smoke sensor as input
    pinMode(Temperature_sensor, INPUT); // Set the temperature sensor as input
}

////////////////////////////////

void loop()
{
    check_magnetic_sensor();
}