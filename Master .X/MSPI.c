#include"MSPI.h"
#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


void Init_SPI() {

    DDRB |= (1 << SCK) | (1 << MOSI) ;
    DDRC |= (1 << cs);
    SPCR |= (1 << MSTR) | (1 << SPE)|(1<<SPR0);
    

}

unsigned char SPI_Trasfer(unsigned char sendByte) {
    SPDR = sendByte;
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}