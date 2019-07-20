/*
 * main.c
 *
 * Created: 17/07/2019 13:56:04
 *  Author: Hossam Khair
 */ 

#define F_CPU	8000000UL
#include "util/delay.h"
#include "../MCAL/inc/io_structure.h"
#include "../Utility/bit_handle.h"

int main(void)
{
	// LEDs enable PF1 (AH), LEDs -> PORTA
	//GPIOF->DDR |= (1<<1);
	SET_BIT(GPIOF->DDR,1);
	//GPIOF->PORT |= (1<<1);
	SET_BIT(GPIOF->PORT,1);
	
	//GPIOA->DDR |= 0xFF;
	SET_BYTE(GPIOA->DDR);
	//GPIOA->PORT |= 0xFF;
	//SET_BYTE(GPIOA->PORT);
	
	int index = 0;
	
    while(1)
    {
		for(index = 0; index <= 7; index++)
		{
			(index == 4)? 0:_delay_ms(50);
			GPIOA->PORT = ((1 << index) | (1 << (7 - index)));
		}
		
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
