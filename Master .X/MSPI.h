/* 
 * File:   SPI.h
 * Author: HELAL
 *
 * Created on December 22, 2021, 11:35 PM
 */

#ifndef SPI_H
#define	SPI_H


#define MOSI 5
#define MISO 6
#define SCK  7
#define cs   1
#define LED0  3
#define SS_Enable()    PORTC&=~(1<<cs)
#define SS_Disnable()  PORTC|=(1<<cs)

void Init_SPI();
unsigned char SPI_Trasfer(unsigned char );

#endif	/* SPI_H */

