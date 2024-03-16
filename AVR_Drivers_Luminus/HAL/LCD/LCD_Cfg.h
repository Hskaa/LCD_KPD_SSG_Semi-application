/*
 * LCD_Cfg.h
 *
 *  Created on: Mar 10, 2024
 *      Author: Computec
 */

#ifndef HAL_LCD_CFG_H_
#define HAL_LCD_CFG_H_

#define LCD_DATA_PORT			DIO_PORTA
#define LCD_CONTROL_PORT		DIO_PORTB

#define LCD_RS_PIN				DIO_PIN0
#define LCD_E_PIN				DIO_PIN2

#define LCD_8Bit_Mode_2Line		0b00111000
#define LCD_OFF_CURSOR			0b00001100
#define LCD_NO_SHIFT			0b00000110

#endif /* HAL_LCD_CFG_H_ */
