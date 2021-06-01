
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


#define _XTAL_FREQ 8000000

#define RS PORTCbits.RC0        // Register Select
#define EN PORTCbits.RC1        // Enable

// Data / Command Pins
#define D0  PORTBbtis.RB0
#define D1  PORTBbtis.RB1
#define D2  PORTBbtis.RB2
#define D3  PORTBbtis.RB3
#define D4  PORTBbtis.RB4
#define D5  PORTBbtis.RB5
#define D6  PORTBbtis.RB6
#define D7  PORTBbtis.RB7

#define LCDPORT PORTB

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

