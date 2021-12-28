
#include <xc.h>
#include <util/delay.h>
#define F_CPU 16000000
#include <avr/io.h>
#include"IO.h"
#include"Motor.h"
#include"SPI.h"
#include"mLCD_4bit.h"
#include"mTimer_1.h"

unsigned char rec;

int main(void) {



    Init_SPI();
    Motor_Init();
    init_LCD_4bit();
    init_Timer(FPWM, _PRE1024);
    setOC0(ClearOnComp);
    

    while (1) {
        
        rec = SPI_Transfer(0x00);
        LCD_CLEAR_4bit();
        
        
        if (rec == 1) {
            Timer_setCompValue(255);
            Motor_ClockWise();
            char str[] = "FORWARD";
            LCD_Write_Str_4bit(str);
            _delay_ms(200);


        }
        if (rec == 2) {
            Timer_setCompValue(255);
            Motor_Stop();
            char str[] = "STOP";
            LCD_Write_Str_4bit(str);
            _delay_ms(200);

        }
        if (rec == 3) {
            Timer_setCompValue(255);
            Motor_AntiClockWise();
            char str[] = "BACK";
            LCD_Write_Str_4bit(str);
            _delay_ms(200);

        }

        if(rec > 3){
            Timer_setCompValue(ADC_read());
            Motor_ClockWise();
            char str[] = "FORWARD WITH SPEED";
            LCD_Write_Str_4bit(str);
            _delay_ms(200);
        }


    }

    return 0;

}