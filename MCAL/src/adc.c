/*
 * adc.c
 *
 * Created: 22/07/2019 15:53:21 
 *  Author: Hossam Khair
 */ 

#include "adc.h"

void ADC_init(INT8U channel)
{
	ADC_STRUCT->ADMUX_REG.MUX = channel;
	ADC_STRUCT->ADMUX_REG.REFS = 1;
	ADC_STRUCT->ADCSRA_REG.ADEN_B = 1;
}

INT16U ADC_read(void)
{
	// starting conversion
	ADC_STRUCT->ADCSRA_REG.ADSC_B = 1;
	
	// wait for conversion end
	while(ADC_STRUCT->ADCSRA_REG.ADSC_B);
	
	return ADC_STRUCT->ADC_REG;
}