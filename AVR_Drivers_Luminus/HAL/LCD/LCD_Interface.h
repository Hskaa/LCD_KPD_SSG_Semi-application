/*
 * LCD_Interface.h
 *
 *  Created on: Mar 10, 2024
 *      Author: Computec
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

void LCD_voidSendCommand(u8 Command);
void LCD_voidSendData(u8 Data);
void LCD_void_Init(void);
void LCD_voidSendString(char *Data);
void LCD_voidClearLCD(void);
void LCD_voidWriteNumber(u32 Copy_u32Number);


#endif /* HAL_LCD_INTERFACE_H_ */
