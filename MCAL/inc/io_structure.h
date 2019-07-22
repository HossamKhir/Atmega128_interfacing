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


typedef struct admux {
	INT8U MUX : 5;
	INT8U ADLAR_B : 1;
	INT8U REFS : 2;
	}ADMUX_BFD;

#define ADMUX_BF	((volatile ADMUX_BFD*)(0x27))

typedef struct adcsra {
	INT8U ADPS : 3;
	INT8U ADIE_B : 1;
	INT8U ADIF_B : 2;
	INT8U ADFR_B : 5;
	INT8U ADSC_B : 5;
	INT8U ADEN_B : 5;
}ADCSRA_BFD;

#define ADCSRA_BF	((volatile ADCSRA_BFD*)(0x26))

#define ADC_R	(*((volatile INT16U*)(0x24)))

typedef struct adc{
	INT16U		ADC_REG;
	ADCSRA_BFD	ADCSRA_REG;
	ADMUX_BFD	ADMUX_REG;
	}ADC_struct;
	
#define ADC_STRUCT ((volatile ADC_struct*)(0x24))

#endif /* IO_STURCTURE_H */
