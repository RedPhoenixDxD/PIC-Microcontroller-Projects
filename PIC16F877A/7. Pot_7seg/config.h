
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 8000000  // 8MHz Frequcy Crystal Used
#define ACQ_DELAY 5         // Time to charge Hold capacitor
/*
 * 7Seg Pins
 */
#define A   PORTBbits.RB0
#define B   PORTBbits.RB1
#define C   PORTBbits.RB2
#define D   PORTBbits.RB3
#define E   PORTBbits.RB4
#define F   PORTBbits.RB5
#define G   PORTBbits.RB6
#define DP   PORTBbits.RB7

/*
 * 7Seg Digit Select
 */
#define DIGIT1 PORTCbits.RC1
#define DIGIT2 PORTCbits.RC0
