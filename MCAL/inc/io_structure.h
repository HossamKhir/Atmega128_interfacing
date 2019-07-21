/*
 * io_structure.h
 *
 * Created: 17/07/2019 14:59:36
 *  Author: Hossam Khair
 */ 


#ifndef IO_STURCTURE_H
#define IO_STURCTURE_H

#include "avr/io.h"
#include "../../Utility/data_types.h"


typedef struct gpio {
	INT8U PIN;
	INT8U DDR;
	INT8U PORT;
	}GPIO;
	
struct gpiof {
	INT8U PIN;
	const INT8U reserved[64];
	INT8U DDR;
	INT8U PORT;
	};

#define GPIOA	((volatile GPIO*)(0x39))
#define GPIOB	((volatile GPIO*)(0x36))
#define GPIOC	((volatile GPIO*)(0x33))
#define GPIOD	((volatile GPIO*)(0x30))
#define GPIOE	((volatile GPIO*)(0x21))
#define GPIOF	((volatile struct gpiof*)(0x20))
#define GPIOG	((volatile GPIO*)(0x63))


#endif /* IO_STURCTURE_H */
