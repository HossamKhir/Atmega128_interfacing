/*
 * LCD.h
 *
 * Created: 21/07/2019 13:17:48 
 *  Author: Hossam Khair
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU	8000000UL

#include "util/delay.h"
#include "../../MCAL/inc/GPIO.h"
#include "stdlib.h"
#include "string.h"
#include <stdio.h>

// Control signals 
#define LCD_CONTROL_GPIO	GPIOB
#define LCD_RS				5
#define LCD_RW				6
#define LCD_EN				7

// Data signals
#define LCD_DATA_GPIO	GPIOC
#define LCD_DATA_MASK	0xF0

struct lcd_port{
	const INT8U low	:4;
	INT8U high	:4;
	};

#define LCD_PORT	((volatile struct lcd_port*)(&LCD_DATA_GPIO->PORT))

// LCD commands
#define LCD_CMD_FN_SET			0x28
#define LCD_CMD_ENTRY_MODE		0x06
#define LCD_CMD_DISP_CONTROL	0x0C
#define LCD_CMD_CLEAR			0x01

// Basic
void LCD_init(void);
void LCD_sendCMD(INT8U cmd);
void LCD_sendDATA(INT8U data);
void LCD_go2RC(INT8U row, INT8U col);	//RC: Row Column
/***********************************/
void LCD_display_character(INT8U data);
void LCD_display_character_RC(INT8U row, INT8U col, INT8U data);
void LCD_display_string(INT8U* str);
void LCD_display_string_RC(INT8U row, INT8U col, INT8U* str);
void LCD_display_integer(INT32U int_value);
void LCD_display_integer_RC(INT8U row, INT8U col, INT32U int_value);


#endif /* LCD_H_ */
