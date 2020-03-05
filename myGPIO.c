/*
 * GPIO.c
 *
 *  Created on: 3/5/20
 *      Author: Kennith Matney
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

/* Defining the bits associated with the Pushbuttons and LED's */
#define LAUNCHPAD_S1 BIT1
#define LAUNCHPAD_S2 BIT4
#define BOOSTERPACK_S1 BIT1
#define BOOSTERPACK_S2 BIT5

#define LED1 BIT0

#define LED2_RED BIT0
#define LED2_GREEN BIT1
#define LED2_BLUE BIT2

#define BLED_RED BIT6
#define BLED_GREEN BIT4
#define BLED_BLUE BIT6

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    P1DIR &= ~LAUNCHPAD_S2; //makes bit 4 of pin 1 an input
    P1REN |= LAUNCHPAD_S2; //makes bit 4 of pin 1 able to use a pull up/down resistor
    P1OUT |= LAUNCHPAD_S2; //makes bit 4 of pin 1 use a pull up resistor

    P1DIR &= ~LAUNCHPAD_S1; //makes bit 1 of pin 1 an input
    P1REN |= LAUNCHPAD_S1; //makes bit 1 of pin 1 able to use a pull up/down resistor
    P1OUT |= LAUNCHPAD_S1; //makes bit 1 of pin 1 use a pull up resistor

    P3DIR &= ~BOOSTERPACK_S2; //makes bit 5 of pin 3 an input
    P3REN |= BOOSTERPACK_S2; //makes bit 5 of pin 3 able to use a pull up/down resistor
    P3OUT |= BOOSTERPACK_S2; //makes bit 5 of pin 3 use a pull up resistor

    P5DIR &= ~BOOSTERPACK_S1; //makes bit 1 of pin 5 an input
    P5REN |= BOOSTERPACK_S1; //makes bit 1 of pin 5 able to use a pull up/down resistor
    P5OUT |= BOOSTERPACK_S1; //makes bit 1 of pin 5 use a pull up resistor

    P1DIR |= LED1; //makes bit 0 of pin 1 as an LED output
    P2DIR |= BLED_RED; //makes bit 6 of pin 2 as an LED output
    P2DIR |= BLED_GREEN; //makes bit 4 of pin 2 as an LED output
    P5DIR |= BLED_BLUE; //makes bit 6 of pin 5 as an LED output
    P2DIR |= LED2_RED; //makes bit 0 of pin 2 as an LED output
    P2DIR |= LED2_GREEN; //makes bit 1 of pin 2 as an LED output
    P2DIR |= LED2_BLUE; //makes bit 2 of pin 2 as an LED output

    // Initializing all LED's to be turned off
    P1OUT &= ~LED1;
    P2OUT &= ~BLED_RED;
    P2OUT &= ~BLED_GREEN;
    P5OUT &= ~BLED_BLUE;
    P2OUT &= ~LED2_RED;
    P2OUT &= ~LED2_GREEN;
    P2OUT &= ~LED2_BLUE;

}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LAUNCHPAD_S1) == LAUNCHPAD_S1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LAUNCHPAD_S2) == LAUNCHPAD_S2);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BOOSTERPACK_S1) == BOOSTERPACK_S1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOOSTERPACK_S2) == BOOSTERPACK_S2);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT |= LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT &= ~LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT |= LED2_RED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT &= ~LED2_RED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT |= LED2_GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT &= ~LED2_GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT |= LED2_BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT &= ~LED2_BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT |= BLED_RED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT &= ~BLED_RED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT |= BLED_GREEN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT &= ~BLED_GREEN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT |= BLED_BLUE;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT &= ~BLED_BLUE;
}
