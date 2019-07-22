/*
 * LCD.c
 *
 * Created: 21/07/2019 13:17:09 
 *  Author: Hossam Khair
 */ 

#include "../inc/LCD.h"

void LCD_init(void)
{
	// Initialize IOs
	GPIO_set_pin_direction(LCD_CONTROL_GPIO, LCD_RS, OUT);
	GPIO_set_pin_direction(LCD_CONTROL_GPIO, LCD_RW, OUT);
	GPIO_set_pin_direction(LCD_CONTROL_GPIO, LCD_EN, OUT);
	SET_BITS(LCD_DATA_GPIO->DDR, LCD_DATA_MASK);
	_delay_ms(20);
	
	LCD_sendCMD(LCD_CMD_FN_SET);		// must always come first
	LCD_sendCMD(LCD_CMD_DISP_CONTROL);
	LCD_sendCMD(LCD_CMD_ENTRY_MODE);
	LCD_sendCMD(LCD_CMD_CLEAR);			// must always come last
	_delay_ms(5);
}
void LCD_sendCMD(INT8U cmd)
{
	// Set command mode
	CLR_BIT(LCD_CONTROL_GPIO->PORT,LCD_RS);
	CLR_BIT(LCD_CONTROL_GPIO->PORT,LCD_RW);
	
	// Sending high command
	//LCD_DATA_GPIO->PORT = ((cmd & 0xF0) | (LCD_DATA_GPIO->PORT & 0x0F));
	LCD_PORT->high = (cmd >> 4);
	SET_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	CLR_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	// Sending low command
	//LCD_DATA_GPIO->PORT = ((cmd << 4) | (LCD_DATA_GPIO->PORT & 0x0F));
	LCD_PORT->high = cmd;
	SET_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	CLR_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	_delay_us(40);
}
void LCD_sendDATA(INT8U data)
{
	// Set data mode
	SET_BIT(LCD_CONTROL_GPIO->PORT,LCD_RS);
	CLR_BIT(LCD_CONTROL_GPIO->PORT,LCD_RW);
	
	// Sending high data
	//LCD_DATA_GPIO->PORT = ((data & 0xF0) | (LCD_DATA_GPIO->PORT & 0x0F));
	LCD_PORT->high = (data >> 4);
	SET_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	CLR_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	// Sending low data
	//LCD_DATA_GPIO->PORT = ((data << 4) | (LCD_DATA_GPIO->PORT & 0x0F));
	LCD_PORT->high = data;
	SET_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	CLR_BIT(LCD_CONTROL_GPIO->PORT,LCD_EN);
	_delay_us(40);	
}
void LCD_go2RC(INT8U row, INT8U col)
{
	// line0 => add: 0x00
	// line1 => add: 0x40
	if(row == 1)
	{
		LCD_sendCMD(0x80 + col - 1);
	}
	else
	{
		LCD_sendCMD(0xC0 + col - 1);
	}
}
void LCD_display_character(INT8U data)
{
	LCD_sendDATA(data);
}
void LCD_display_character_RC(INT8U row, INT8U col, INT8U data)
{
	LCD_go2RC(row, col);
	LCD_display_character(data);	
}
void LCD_display_string(INT8U* str)
{
	while(*str)
	{
		LCD_sendDATA(*str);
		str++;
	}
}
void LCD_display_string_RC(INT8U row, INT8U col, INT8U* str)
{
	LCD_go2RC(row, col);
	LCD_display_string(str);
}
void LCD_display_integer(INT32U int_value)
{
	INT8U buffer[17] = {0};
	sprintf((char*)buffer, "Int = %d", (int)int_value);
	//itoa(buffer, int_value, 10);
	LCD_display_string(buffer);
}
void LCD_display_integer_RC(INT8U row, INT8U col, INT32U int_value)
{
	LCD_go2RC(row, col);
	LCD_display_integer(int_value);
}
