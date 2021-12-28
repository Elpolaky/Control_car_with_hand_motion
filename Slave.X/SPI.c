#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include"SPI.h"


void Init_SPI() {
    DDRB |= (1 << MISO);
    DDRB &= ~(1 << SS);
    SPCR |= (1 << SPE);
}

unsigned char SPI_Transfer(unsigned char sendByte) {

    SPDR = sendByte;

    while (!(SPSR & (1 << SPIF)));
    return SPDR;

}
