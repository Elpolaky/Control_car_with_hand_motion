
#include "mTimer.h"
#include <avr/io.h>
#include"IO.h"


void init_Timer(int mode, int ClockSelect){
    
    TCCR0 &= ~((1<<WGM00)|(1<<WGM01));
    TCCR0 &= ~((1<<CS02)|(1<<CS01)|(1<<CS00));
    
    TCCR0 |= mode;
    TCCR0 |= ClockSelect;

}

void Timer_interrupt_enable(int INT_selector){
    TIMSK |= (1<<INT_selector);
}

void Timer_setCompValue(unsigned char compValue){
    OCR0 =  compValue;
}


void setOC0(int OC0_mode ){
    TCCR0 &= ~((1<<COM01)|(1<<COM00));
    setPinDir(_PB, PIN3, OUT);
    TCCR0 |= (OC0_mode<<COM00);

}