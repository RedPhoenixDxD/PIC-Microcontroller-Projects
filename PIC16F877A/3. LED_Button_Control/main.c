/*
 * File:   main.c
 * Author: rahul
 *
 * Created on May 27, 2021, 1:06 PM
 */


#include "config.h"

void main(void) {
    /*
     * Pin Configuration
     */
    
    TRISBbits.TRISB0 = 0;
    TRISCbits.TRISC0 = 1;
    
    PORTBbits.RB0 = 0;
    
    /*
     * Main Loop
     */
    while(1){
        if(PORTCbits.RC0){
            while(PORTCbits.RC0);
            PORTBbits.RB0 = ~PORTBbits.RB0;
        }
    }
    return;
}
