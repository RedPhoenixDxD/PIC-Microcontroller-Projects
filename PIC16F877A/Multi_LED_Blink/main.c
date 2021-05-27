/*
 * File:   main.c
 * Author: rahul
 *
 * Created on May 27, 2021, 12:11 PM
 */


#include "config.h"

void main(void) {
    /*
     * Pin Configuration
     */
    
    TRISB = 0b00000000;  // Set all PORTB Pin as Output
    PORTB = 0x00;        // Clear all PORTB resister values
    
    /*
     * Main Loop
     */
     
    unsigned char cnt = 0x01;
    while(1){
        PORTB = cnt;
        __delay_ms(1000);
         cnt = cnt << 1;
        if(cnt == 0x00){
            cnt = 0x01;
        }
        
    }
    return;
}
