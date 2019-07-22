/*
 * keypad.c
 *
 * Created: 22/07/2019 11:28:55 
 *  Author: Hossam Khair
 */ 

#include "keypad.h"
#define F_CPU 8000000UL
#include "util/delay.h"

const INT8U keymap[4][4] =
{
	{'1', '2', '3', '+'},
	{'4', '5', '6', '-'},
	{'7', '8', '9', '*'},
	{'A', '0', 'B', '/'}
};

void key_init(void)
{
	// set directions of rows as output
	SET_BITS(KEYPAD_REG->DDR,0x0F);
	
	// set directions of columns as input
	CLR_BITS(KEYPAD_REG->DDR,0xF0);
	
	// activate pull up resistors
	SET_BITS(KEYPAD_REG->PORT,0xF0);
}

INT8U key_getKey(void)
{
	INT8U co = 0, ro = 0, i = 0;
	for(i = 0; i < 4; i++)
	{
		GPIO_write_pin(KEYPAD_REG,i,RESET);
	}
	for(ro = 0; ro < 4; ro++)
	{
		SET_BITS(KEYPAD_REG->PORT, 0x0F);
		CLR_BIT(KEYPAD_REG->PORT,ro);
		_delay_ms(1);
		for(co = 0; co < 4; co++)
		{
			if(!(GET_BIT(KEYPAD_REG->PIN,(co + 4))))
			{
				SET_BITS(KEYPAD_REG->PORT, 0x0F);
				return keymap[ro][co];
			}
		}
	}
	SET_BITS(KEYPAD_REG->PORT, 0x0F);
	return '\0';
}

INT16U key_scan(void)
{
	INT8U co = 0, ro = 0, i = 0;
	for(i = 0; i < 4; i++)
	{
		GPIO_write_pin(KEYPAD_REG,i,RESET);
	}
	for(ro = 0; ro < 4; ro++)
	{
		SET_BITS(KEYPAD_REG->PORT, 0x0F);
		CLR_BIT(KEYPAD_REG->PORT,ro);
		_delay_ms(1);
		for(co = 0; co < 4; co++)
		{
			if(!(GET_BIT(KEYPAD_REG->PIN,(co + 4))))
			{
				
			}
		}
	}
	SET_BITS(KEYPAD_REG->PORT, 0x0F);
	return 0;
}
