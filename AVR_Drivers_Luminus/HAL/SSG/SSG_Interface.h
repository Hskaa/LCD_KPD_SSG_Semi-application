/*
 * SSG_Interface.h
 *
 *  Created on: Mar 17, 2024
 *      Author: Computec
 */

#ifndef HAL_SSG_SSG_INTERFACE_H_
#define HAL_SSG_SSG_INTERFACE_H_
#include "SSG_Cfg.h"



void Sev_Multi(u8 Copy_u8Port  , u8 Copy_u8PinLeft , u8 Copy_u8PinRight , u8 num);
void SSG_ON (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8num , u8 Copy_u8Kind);
void SSG_Mult(SSG *SSG_t);

#endif /* HAL_SSG_SSG_INTERFACE_H_ */
