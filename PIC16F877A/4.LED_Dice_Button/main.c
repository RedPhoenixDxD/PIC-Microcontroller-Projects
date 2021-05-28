/*
 * File:   main.c
 * Author: Rahul Yadav
 *
 * Created on 28 May, 2021, 8:56 AM
 */


#include "config.h"

unsigned char Dice[6] = {0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00111111};  

void main(void) {
    /*
     * Pin Configuration
     */
    
    TRISB = 0x00;           // Set Port B as Output
    TRISDbits.TRISD7 = 1;   // Set PORTD pin D7 as Input
    PORTB = 0x00;           // Clear PORTB register values
    
    /*
     * Main Loop
     */
    unsigned char sel = 0;
    while(1){
        if(PORTDbits.RD7){
            while(PORTDbits.RD7);
            sel = rand()%6;
            PORTB = Dice[sel];
        }
        
    }
    return;
}
