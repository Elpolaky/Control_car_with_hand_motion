
#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include"IO.h"







void init_Leds() {

    /*
        Led0 >>   PC2
        Led1 >>   PC7
        Led2 >>   PD3
     */
    DDRC |= (1 << Led0) | (1 << Led1);
    DDRD |= (1 << Led2);


}

void set_Led(int LedNumber, int state) {

    if (state) {

        switch (LedNumber) {
            case Led0:
                PORTC |= (1 << Led0);
                break;
            case Led1:
                PORTC |= (1 << Led1);
                break;
            case Led2:
                PORTD |= (1 << Led2);
                break;
        }

    } else {
        switch (LedNumber) {
            case Led0:
                PORTC &= ~(1 << Led0);
                break;
            case Led1:
                PORTC &= ~(1 << Led1);
                break;
            case Led2:
                PORTD &= ~(1 << Led2);
                break;
        }
    }


}



void _setPortDir(int portNum, int state) {
    if (state) {
        // as OUTPUT
        switch (portNum) {
            case _PA:
                DDRA = 0xFF;
                break;
            case _PB:
                DDRB = 0xFF;
                break;
            case _PC:
                DDRC = 0xFF;
                break;
            case _PD:
                DDRD = 0xFF;
                break;
            default:

                DDRA = 0;
                DDRB = 0;
                DDRC = 0;
                DDRD = 0;
        }
    } else {
        // as INPUT
        switch (portNum) {
            case _PA:
                DDRA = 0xFF;
                break;
            case _PB:
                DDRB = 0xFF;
                break;
            case _PC:
                DDRC = 0xFF;
                break;
            case _PD:
                DDRD = 0xFF;
                break;
            default:
                DDRA = 0;
                DDRB = 0;
                DDRC = 0;
                DDRD = 0;
        }
    }
}

void setPortDir(int portNum, int state) {
    switch (portNum) {
        case _PA:
            DDRA = state ? 0xFF : 0x00;
            break;
        case _PB:
            DDRB = state ? 0xFF : 0x00;
            break;
        case _PC:
            DDRC = state ? 0xFF : 0x00;
            break;
        case _PD:
            DDRD = state ? 0xFF : 0x00;
            break;
        default:
            DDRA = 0;
            DDRB = 0;
            DDRC = 0;
            DDRD = 0;
    }
}

void setPortData(int portNum, int dataOut) {
    switch (portNum) {
        case _PA:
            PORTA = dataOut;
            break;
        case _PB:
            PORTB = dataOut;
            break;
        case _PC:
            PORTC = dataOut;
            break;
        case _PD:
            PORTD = dataOut;
            break;
        default:
            DDRA = 0;
            DDRB = 0;
            DDRC = 0;
            DDRD = 0;
    }
}

void togglePortData(int portNum) {
    switch (portNum) {
        case _PA:
            PORTA ^= 0xFF;  
            break;
        case _PB:
            PORTB ^= 0xFF;  
            break;
        case _PC:
            PORTC ^= 0xFF;  
            break;
        case _PD:
            PORTD ^= 0xFF;  
            break;
        default:
            DDRA = 0;
            DDRB = 0;
            DDRC = 0;
            DDRD = 0;
    }
}
// Pin Level

void setPinDir(int portNum, int pinNum, int state) {
    if (state) {
        switch (portNum) {
            case _PA:
                DDRA |= (1 << pinNum);
                break;
            case _PB:
                DDRB |= (1 << pinNum);
                break;
            case _PC:
                DDRC |= (1 << pinNum);
                break;
            case _PD:
                DDRD |= (1 << pinNum);
                break;
        }
    } else {
        switch (portNum) {
            case _PA:
                DDRA &= ~(1 << pinNum);
                break;
            case _PB:
                DDRB &= ~(1 << pinNum);
                break;
            case _PC:
                DDRC &= ~(1 << pinNum);
                break;
            case _PD:
                DDRD &= ~(1 << pinNum);
                break;
        }
    }
}
void setPinData(int portNum, int pinNum, int data){
    if (data) {
        switch (portNum) {
            case _PA:
                PORTA |= (1 << pinNum);
                break;
            case _PB:
                PORTB |= (1 << pinNum);
                break;
            case _PC:
                PORTC |= (1 << pinNum);
                break;
            case _PD:
                PORTD |= (1 << pinNum);
                break;
        }
    } else {
        switch (portNum) {
            case _PA:
                PORTA &= ~(1 << pinNum);
                break;
            case _PB:
                PORTB &= ~(1 << pinNum);
                break;
            case _PC:
                PORTC &= ~(1 << pinNum);
                break;
            case _PD:
                PORTD &= ~(1 << pinNum);
                break;
        }
    }
}
void togglePinData(int portNum, int pinNum){
    
        switch (portNum) {
            case _PA:
                PORTA ^= (1 << pinNum);
                break;
            case _PB:
                PORTB ^= (1 << pinNum);
                break;
            case _PC:
                PORTC ^= (1 << pinNum);
                break;
            case _PD:
                PORTD ^= (1 << pinNum);
                break;
        }
    
        
    }