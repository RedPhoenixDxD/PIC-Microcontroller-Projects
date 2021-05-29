/*
 * File:   main.c
 * Author: rahul
 *
 * Created on 29 May, 2021, 9:39 AM
 */


#include "config.h"

void Digit(char AA){
    switch(AA){
        case 0:
            A = 1;
            B = 1;
            C = 1;
            D = 1;
            E = 1;
            F = 1;
            G = 0;
            break;
        case 1:
            A = 0;
            B = 1;
            C = 1;
            D = 0;
            E = 0;
            F = 0;
            G = 0;
            break;
        case 2:
            A = 1;
            B = 1;
            C = 0;
            D = 1;
            E = 1;
            F = 0;
            G = 1;
            break;
        case 3:
            A = 1;
            B = 1;
            C = 1;
            D = 1;
            E = 0;
            F = 0;
            G = 1;
            break;
        case 4:
            A = 0;
            B = 1;
            C = 1;
            D = 0;
            E = 0;
            F = 1;
            G = 1;
            break;
        case 5:
            A = 1;
            B = 0;
            C = 1;
            D = 1;
            E = 0;
            F = 1;
            G = 1;
            break;
        case 6:
            A = 1;
            B = 0;
            C = 1;
            D = 1;
            E = 1;
            F = 1;
            G = 1;
            break;
        case 7: 
            A = 1;
            B = 1;
            C = 1;
            D = 0;
            E = 0;
            F = 0;
            G = 0;
            break;
        case 8:
            A = 1;
            B = 1;
            C = 1;
            D = 1;
            E = 1;
            F = 1;
            G = 1;
            break;
        case 9:
            A = 1;
            B = 1;
            C = 1;
            D = 1;
            E = 0;
            F = 1;
            G = 1;
            break;
        default:
            break;
    }
}

void main(void) {
    /*
     * Pin Configuration
     */
    
    TRISB = 0x00;           // Set all pins of PORTB as outputs
    PORTB = 0x00;           // Clear all PORTB register Values
    
    /*
     * Main Loop
     */
    unsigned char i = 0 , cnt = 0;
    while(1){
        if(cnt > 9){
            cnt = 0;
        }
        Digit(cnt);
        cnt++;
        __delay_ms(1000);
    }
    return;
}
