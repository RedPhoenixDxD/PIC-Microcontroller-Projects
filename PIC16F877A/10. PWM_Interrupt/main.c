/*
 * File:   main.c
 * Author: rahul
 *
 * Created on 3 June, 2021, 8:50 AM
 */


#include "config.h"

void __interrupt() ISR(){
    if(INTCONbits.TMR0IF){
        if(cnt <= T_On)
            PORTBbits.RB0 = 1;
        else
            PORTBbits.RB0 = 0;
        if(cnt >= T_TOTAL*10)
            cnt = 0;
        cnt++;
        TMR0= 224;
        INTCONbits.T0IF = 0;
    }
}

void main(void) {
    /*
     * Pin Configuration
     */
    TRISBbits.TRISB0 = 0;   // Set PORTB pin RB0 as Output
    PORTBbits.RB0 = 0;      // Clear PORTB RB0 register value
    
    /*
     * ADC Initialize
     */
    ADCON0 = 0x01;          // ADON enable
    ADCON1 = 0x80;          // Set all PORTA pins as Analog
    ADRESH = 0;             // Clear ADRESH register 
    ADRESL = 0;             // Clear ADRESL register
    
    /*
     *  TMR0 initialize
     */
    OPTION_REG = 0x05;
    TMR0 = 224;               // Pre-load TMR0 register
    INTCONbits.TMR0IE = 1;  // Enable TMR0 Interrupt
    INTCONbits.TMR0IF = 0;  // Clear TMR0 overflow Interrupt Flag
    INTCONbits.GIE = 1;     // Enable Global Interrupt
    INTCONbits.PEIE = 1;    // Enable Peripheral Interrupt
    
    
    /*
     * Main Loop
     */
    while(1){
        Pot = ADC_Read(Pot_Ch);
        DutyCycle = ((Pot*10)/512)*5;
        T_On = ((DutyCycle*T_TOTAL)*10)/100;
        __delay_ms(100);

    }
    return;
}

uint16_t ADC_Read(unsigned char Ch){
    ADCON0bits.CHS = Ch;    // Set ADC Channel
    __delay_us(ACQ_US_DELAY);
    ADCON0bits.GO_nDONE = 1;    // Start ADC Conversion

    while(ADCON0bits.GO_nDONE); // Wait for Conversion to complete
    
    return (uint16_t)((ADRESH<<8)+ADRESL);  // return result
}
