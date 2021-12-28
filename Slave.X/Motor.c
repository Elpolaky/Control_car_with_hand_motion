#include <xc.h>
#include <avr/io.h>
#include"Motor.h"
#include <util/delay.h>

void Motor_Init() 
{
    PORTC=0x00;
    DDRC = 0xFF;
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);
    PORTD |= (1 << PD4);
    PORTD |= (1 << PD5);


}

void Motor_ClockWise() {
  
    PORTC |= (1 << PC4);
    PORTC |= (1 << PC6);
    PORTC &= ~(1 << PC3);
    PORTC &= ~(1 << PC5);
  
}

void Motor_AntiClockWise() {
    PORTC |= (1 << PC3);
    PORTC |= (1 << PC5);
    PORTC &= ~(1 << PC4);
    PORTC &= ~(1 << PC6);
    
}

void Motor_Stop() {
    PORTC = 0x00;
   
}