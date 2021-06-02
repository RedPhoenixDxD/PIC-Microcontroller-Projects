/*
 * File:   main.c
 * Author: Rahul Yadav
 *
 * Created on 2 June, 2021, 8:27 AM
 */

#include <stdint.h>
#include "config.h"


void main(void) {
    /*
     * Pin Configuration
     */
    TRISBbits.TRISB0 = 0;   // Set PORTB pin RB0 as Output
    
    /*
     * ADC Initialize
     */
    ADCON0 = 0x01;
    ADCON1 = 0x80;
    ADRESH = 0x00;
    ADRESL = 0x00;
    
    /*
     * Main Loop
     */
    unsigned char POT_CH = 0b000;
    uint16_t POT = 0, temp = 0, max = 0;
    uint16_t DutyCycle = 0, T_On = 0;
    unsigned char cnt = 0, delay = 0;
    while(1){
        POT= Get_ADCResult(POT_CH);
        DutyCycle = ((POT*10)/512)*5; // 0 to 1024 -> 0 to 100
        T_On = (DutyCycle*T_TOTAL)*10/100;
        if(delay <= T_On){
            PORTBbits.RB0 = 1;
        }
        else{
            PORTBbits.RB0 = 0;
        }
        if(delay>= (T_TOTAL*10))
            delay=0;       
        delay++;
    }
    return;
}


uint16_t Get_ADCResult(unsigned char Ch){
    ADCON0bits.CHS = Ch;    // Set ADC Channel
    __delay_us(ACQ_US_DELAY);
    ADCON0bits.GO_nDONE = 1;    // Start ADC Conversion

    while(ADCON0bits.GO_nDONE); // Wait for Conversion to complete
    
    return (uint16_t)((ADRESH<<8)+ADRESL);  // return result
}