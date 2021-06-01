/*
 * File:   main.c
 * Author: rahul
 *
 * Created on 1 June, 2021, 9:46 AM
 */


#include "config.h"

unsigned char data[20] = "Hello World!";

void main(void) {
    /*
     * Pin Configuration
     */
    
    TRISB = 0x00;   // Set PORTB pins as Output
    TRISC = 0x00;   // Set PORTC pins as Output
    PORTB = 0x00;   // Clear PORTB register value
    PORTC = 0x00;   // Clear PORTC register value
    
    lcd_init();     // LCD initialize
    
    /*
     * Main Loop
     */
    unsigned char i = 0;
    while(1){
        if(data[i] == '\0'){
            i = 0;
            __delay_ms(500);
            lcd_cmd(0x01);  // Clear display screen
        }
        lcd_data(data[i]);
        i++;
        __delay_ms(100);
    }
    return;
}


void lcd_init(){
    lcd_cmd(0x38);  //Configure the LCD in 8-bit mode,2 line and 5×7 font
    lcd_cmd(0x0C);  // Display On and Cursor Off
    lcd_cmd(0x01);  // Clear display screen
    lcd_cmd(0x06);  // Increment cursor
    lcd_cmd(0x80);  // Set cursor position to 1st line,1st column
}

void lcd_cmd(unsigned char cmd){
    LCDPORT = cmd;
    RS = 0;
    EN = 1;
    __delay_ms(10);
    EN = 0;
}

void lcd_data(unsigned char data){
    LCDPORT = data;
    RS = 1;
    EN = 1;
    __delay_ms(10);
    EN = 0;
}