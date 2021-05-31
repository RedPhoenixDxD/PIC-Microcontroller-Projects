/*
 * File:   main.c
 * Author: Rahul Yadav
 *
 * Created on 30 May, 2021, 9:07 AM
 */

#include <stdint.h>

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

void ADC_init(){
    ADCON0 = 0x01;  // FOSC/2; CHS = RA0; GonDone = 0;ADON = 1;
    ADCON1 = 0x80;  // All PORTA pins to analog; ADFM =1 or Result is Right Justified
    
    ADRESH = 0x00;  // Clear ADC result ADRESH register
    ADRESL = 0x00;  // Clear ADC result ADRESL register
    
}

uint16_t Get_ADCResult(unsigned char Ch){
    ADCON0bits.CHS = Ch;
    __delay_ms(ACQ_DELAY);
    ADCON0bits.GO_nDONE = 1;
    while(ADCON0bits.GO_nDONE);
    
    return (uint16_t)((ADRESH<<8)+ADRESL); 
}

void main(void) {
    /*
     * Pin Configuration
     */
    TRISAbits.TRISA0 = 1;
    TRISB = 0x00;           // Set PORTB pins as output
    TRISCbits.TRISC0 = 0;   // Set PORTC pin C0 as output
    TRISCbits.TRISC1 = 0;   // Set PORTC pin C1 as output
    ADC_init();
    PORTB = 0x00;           // Clear PORTB register values
    DIGIT1 = 0;                // Turn Off 7seg Once Digit
    DIGIT2 = 0;                // Turn Off 7seg Tens Digit
    
    /*
     * Main Loop
     */
    unsigned char cnt=0, units=0, tens=0;
    uint16_t temp;
    while(1){
        temp = Get_ADCResult(0b000);
        if(temp <= 102){
            cnt = 00;
        }
        else if(temp <= 256){
            cnt = 25;
        }
        else if(temp <= 512){
            cnt = 50;
        }
        else if(temp <= 768){
            cnt = 75;
        }
        else if(temp <= 1024){
            cnt = 99;
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
    }
    return;
}
