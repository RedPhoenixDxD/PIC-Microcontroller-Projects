/*
 * File:   main.c
 * Author: rahul
 *
 * Created on 30 May, 2021, 9:07 AM
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
    TRISB = 0x00;           // Set PORTB pins as output
    TRISCbits.TRISC0 = 0;   // Set PORTC pin C0 as output
    TRISCbits.TRISC1 = 0;   // Set PORTC pin C1 as output
    PORTB = 0x00;           // Clear PORTB register values
    DIGIT1 = 0;                // Turn Off 7seg Once Digit
    DIGIT2 = 0;                // Turn Off 7seg Tens Digit
    
    /*
     * Main Loop
     */
    unsigned char cnt=0, flag=0, units=0, tens=0;
    while(1){
        if(cnt > 99){
            cnt = 0;
        }
        units = cnt%10;
        Digit(units);
        DIGIT1 = 1;
        __delay_ms(10);
        DIGIT1 = 0;
        tens = (cnt/10)%10;
        Digit(tens);
        DIGIT2 = 1;
        __delay_ms(10);
        DIGIT2 = 0;
        if(flag == 100){
            cnt++;
            flag = 0;
        }
        flag++;
    }
    return;
}
