/* 
 * File:   SPI.h
 * Author: HELAL
 *
 * Created on December 22, 2021, 11:14 PM
 */

#ifndef SPI_H
#define	SPI_H



#define MOSI 5
#define MISO 6
#define SCK  7
#define SS   4

void Init_SPI();
unsigned char SPI_Transfer(unsigned char );

#endif	/* SPI_H */

