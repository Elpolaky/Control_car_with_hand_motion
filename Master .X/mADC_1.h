
#ifndef MADC_H
#define	MADC_H

#define _AREF             0
#define _AVCC             1
#define _INERNAL_REF      3


#define ADC0    0    
#define ADC1    1
#define ADC2    2
#define ADC3    3
#define ADC4    4
#define ADC5    5
#define ADC6    6
#define ADC7    7



#define _PS64   6
#define _PS128  7


void init_ADC(int ch, int ref, int prescaler);

void ADC_init_INTERRUPT();
void ADC_StartConv();

int ADC_read();



#endif	/* MADC_H */

