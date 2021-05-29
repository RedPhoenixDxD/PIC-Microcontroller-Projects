/*
 * File:   main.c
 * Author: Rahul Yadav
 *
 * Created on May 27, 2021, 9:25 AM
 */


#include "config.h"

void main(void) {
    /*
     * Pin Configuration
     */
    
    TRISBbits.TRISB0 = 0;   // Set RB0 pin as Output
    PORTBbits.RB0 = 0;      // Set RB0 register value to 0
    
    while(1){
        PORTBbits.RB0 = ~PORTBbits.RB0; // Toggle RB0 register Value
        __delay_ms(1000);                // at every 1sec
    }
    return;
}
