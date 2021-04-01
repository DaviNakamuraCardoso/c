int DELAY_TIME = 1000;

// Defining three different status for a plant
typedef enum status {DRY, BORDERLINE, GOOD};

// PIN struct that represents a LED
typedef struct _pin
{
    unsigned int on:1;
    int number;
    long counter;

} PIN;

// Declaring the main pin in the global scope
PIN p = {0, 13, 0};

// The previous status is set initially to good
enum status prev = GOOD;

void setup()
{
    // Initialize the serial
    Serial.begin(9600);

    // Set the LED pinmode to output
    pinMode(p.number, OUTPUT);

}

void loop()
{
    // Get the voltage from analog input 1
    int voltage = analogRead(1);

    // Current status
    enum status current = get_status(voltage);

    // Analise the status
    switch (current)
    {
        // If dry, turn on the LED
        case DRY:
        {
            turnon();
            break;
        }
        // If borderline, start to blink
        case BORDERLINE:
        {
            blink();
            break;
        }
        // If good, turn off
        case GOOD:
        {
            turnoff();
            // If the previous status wasn't good, says thank you
            if (prev != GOOD)
            {
                Serial.println("Thank you, Seymour!");
            }
            break;
        }
    }

    // Apply pin changes
    digitalWrite(p.number, p.on);

    // Update the current status
    prev = current;

    // One sec delay between updates
    delay(DELAY_TIME);
}


enum status get_status(int a)
{
    /* Given the small size of the plant,
        it is dry when the current is below 400 */
    if (a <= 400)
    {
        return DRY;
    }
    // Borderline between 400 and 550
    else if (a <= 550)
    {
        return BORDERLINE;
    }

    return GOOD;
}


// Set the on variable to false
void turnoff()
{
    p.on = 0;
    return;
}

// Set the on variable to true
void turnon()
{
    p.on = 1;

    Serial.println("Feed Me!\n");
    return;
}

// Switch the on variable each iteration
void blink()
{
    p.counter++;

    // Reset the counter to prevent buffer overflow
    if (p.counter >= 30000)
    {
        p.counter = 1;
    }

    // Turn on if counter is divisible by 2
    if (p.counter % 2 == 0)
    {
        turnon();
        return;
    }

    // Else, turn off
    turnoff();

    return;
}
