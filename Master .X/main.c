


#include <xc.h>
#include <util/delay.h>
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include"MSPI.h"
#include"ADC.h"
#include"mTimer.h"

unsigned char duty = 0;

int main(void) {

    Init_SPI();
    init_ADC(ADC1, _AVCC, _PS128);
    
    




    while (1) {
        SS_Enable();
        ADC_StartConv();
                
        if ((PINA & (1 << PA4))) {
            unsigned char rec = SPI_Trasfer(1);

        }
        if ((PINA & (1 << PA5))) {
            unsigned char rec = SPI_Trasfer(2);


        }
        if ((PINA & (1 << PA6))) {
            unsigned char rec = SPI_Trasfer(3);
        }
        if (ADC_read() ||!(PINA & (1 << PA6)) || !(PINA & (1 << PA6))|| !(PINA & (1 << PA4)) ){
            SPI_Trasfer((ADC_read()/4)+4);
            
        }


        SS_Disnable();
        _delay_ms(500);


    }

    return 0;

}
