/*
 * GPIO.c
 *
 * Created: 18/07/2019 15:21:00
 *  Author: Hossam Khair
 */ 

#include "../inc/GPIO.h"

// PORT
void GPIO_write_pin(void* reg, pin P, pin_value PIN_VAL)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		struct gpiof* REG = GPIOF;
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
	}

	switch (PIN_VAL)
	{
		case SET:
//			SET_BIT(REG->PORT,P);
		break;
		case RESET:
//			CLR_BIT(REG->PORT,P);
		break;
	}
}

// DDR
void GPIO_set_pin_direction(void* reg, pin P, pin_direction PIN_DIR)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		struct gpiof* REG = GPIOF;
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
	}
	switch (PIN_DIR)
	{
		case IN:
//			CLR_BIT(REG->DDR,P);
		break;
		case OUT:
//			SET_BIT(REG->DDR,P);
		break;
	}
}

// PORT
void GPIO_enable_pullup(void* reg, pin P)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		struct gpiof* REG = GPIOF;
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
	}

//	SET_BIT(REG->PORT,P);
}

// PIN
INT8U GPIO_read_pin(void* reg, pin P)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		struct gpiof* REG = GPIOF;
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
	}

	return 0 /*GET_BIT(REG->PIN,P)*/;
}

// PORT
void GPIO_toggle_pin(void* reg, pin P)
{
	if(GPIOF == (struct gpiof*)reg)
	{
		struct gpiof* REG = GPIOF;
	}
	else
	{
		GPIO* REG = (GPIO*)reg;
	}
	
//	TOG_BIT(REG->PORT,P);
}
