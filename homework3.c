#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

#define UNPRESSED   0xff
#define PRESSED     0x00

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonhistory = UNPRESSED;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if (timer0Expired())
        {
            count0++;
        }
        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired())
        {
            buttonhistory = checkStatus_BoosterpackS1();
        }

        fsmBoosterpackButtonS1(buttonhistory);

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        if ((checkStatus_BoosterpackS1()) == PRESSED && (fsmBoosterpackButtonS1(buttonhistory) == true))
        {
            changeBoosterpackLED(count1);
        }
        // TODO: If a completed, debounced button press has occurred, increment count1.
        if (fsmBoosterpackButtonS1(buttonhistory) == true)
            count1++;

    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    switch(count & 7)
    {
        case 0:
            turnOn_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;
        case 1:
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;
        case 2:
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;
        case 3:
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 4:
            turnOn_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 5:
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 6:
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 7:
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;
        default:
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    switch(count & 7)
    {
        case 0:
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 1:
            turnOn_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 2:
            turnOff_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 3:
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
            break;
        case 4:
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        case 5:
            turnOn_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        case 6:
            turnOff_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        case 7:
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();
            break;
        default:
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;
    typedef enum {s0, s1, s2, s3} buttonState;
    static buttonState currentState = s0;
    unsigned char test1;
    unsigned char test2;

    switch(currentState)
    {
        case s0:
            test1 = buttonhistory;
            currentState = s1;
            break;
        case s1:
            test2 = buttonhistory;
            currentState = s2;
            break;
        case s2:
            if(test1 != test2 )
                pressed = true;
            currentState = s3;
            break;
        case s3:
            currentState = s0;
            break;
        default:
            break;
    }

    return pressed;
}
