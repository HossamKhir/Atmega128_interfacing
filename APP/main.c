/*
 * main.c
 *
 * Created: 17/07/2019 13:56:04
 *  Author: Hossam Khair
 */ 

#define F_CPU	8000000UL
#include "util/delay.h"
#include "../MCAL/inc/GPIO.h"
#include "../HAL/inc/LCD.h"
#include "keypad.h"
#include "adc.h"

int main(void)
{
	// LED application
	/************************************/
	// LEDs enable PF1 (AH), LEDs -> PORTA
	//GPIOF->DDR |= (1<<1);
	//SET_BIT(GPIOF->DDR,1);
	GPIO_set_pin_direction(GPIOF,1,OUT);
	//GPIOF->PORT |= (1<<1);
	//SET_BIT(GPIOF->PORT,1);
	GPIO_write_pin(GPIOF,1,SET);
	
	//GPIOA->DDR |= 0xFF;
	SET_BYTE(GPIOA->DDR);
	//GPIOA->PORT |= 0xFF;
	//SET_BYTE(GPIOA->PORT);
	GPIO_write_pin(GPIOA,5,SET);
	
	//int index = 0;
	/***********************************/
	
	// LCD application
	/***********************************/
	LCD_init();
	//LCD_display_character('1');
	//LCD_display_character_RC(1,16,'2');
	//LCD_display_string_RC(2,1,"NTI");
	//LCD_display_integer_RC(2,6,12345);
	/***********************************/
	key_init();
	INT8U key = '\0';
	key = key_getKey();
	if(key)
	{
		LCD_display_character(key);
	}
	/**********************************/
	long long i = 0;
	INT16U read = 0;
    /**********************************/
	ADC_init(0);
	while(1)
    {
		LCD_display_integer_RC(1,1,i++);
		//read = ADC_read();
		//LCD_display_string_RC(2,2,"     ");
		
		//LCD_display_integer_RC(2,2, read);
		
		_delay_ms(200);
		/*for(index = 0; index <= 7; index++)
		{
			(index == 4)? 0:_delay_ms(50);
			GPIOA->PORT = ((1 << index) | (1 << (7 - index)));
		}*/
		
        //YOLO:: You Only Live Once
		/*
		SET_BIT(GPIOA->PORT,index);
		SET_BIT(GPIOA->PORT,(7-index));
		
		(index == 4)? index:_delay_ms(50);
		
		CLR_BIT(GPIOA->PORT,index);
		CLR_BIT(GPIOA->PORT,(7-index));
		
		// Reset condition: index == 8
		index = (index == 7)? 0 : index + 1;
		*/
    }
}
