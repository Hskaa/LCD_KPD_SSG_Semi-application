/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : HAL         		***************/
/***************   		SWC : SSG            		***************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/

#include "../../Librares/STD_TYPES.h"
#include "../../Librares/BIT_MATH.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "../../MCAL/DIO_Driver/DIO_Reg.h"

#include "SSG_Interface.h"
#include "SSG_Cfg.h"
#include "util/delay.h"


u8 ones=0 , tens=0 ;


u8 SevenSegCath[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
u8 SevenSegAnode[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
u8 Arr_DecToSeg[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

void Sev_Multi(u8 Copy_u8Port  , u8 Copy_u8PinLeft , u8 Copy_u8PinRight , u8 num)
{
	tens = num / 10;
	ones = num % 10;

	switch (Copy_u8Port)
	{
	case 1 :
		DIO_u8SetPortDirection(DIO_PORTA,DIO_PORT_HIGH);
		DIO_u8SetPortValue(DIO_PORTA,Arr_DecToSeg[tens]);
		CLR_BIT(PORT_PINS,Copy_u8PinLeft);
		SET_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		DIO_u8SetPortValue(DIO_PORTA,Arr_DecToSeg[ones]);
		SET_BIT(PORT_PINS,Copy_u8PinLeft);
		CLR_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		break;
	case 2 :
		DIO_u8SetPortDirection(DIO_PORTB,DIO_PORT_HIGH);
		DIO_u8SetPortValue(DIO_PORTB,Arr_DecToSeg[tens]);
		CLR_BIT(PORT_PINS,Copy_u8PinLeft);
		SET_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		DIO_u8SetPortValue(DIO_PORTB,Arr_DecToSeg[ones]);
		SET_BIT(PORT_PINS,Copy_u8PinLeft);
		CLR_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		break;
	case 3 :
		DIO_u8SetPortDirection(DIO_PORTC,DIO_PORT_HIGH);
		DIO_u8SetPortValue(DIO_PORTC,Arr_DecToSeg[tens]);
		CLR_BIT(PORT_PINS,Copy_u8PinLeft);
		SET_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		DIO_u8SetPortValue(DIO_PORTC,Arr_DecToSeg[ones]);
		SET_BIT(PORT_PINS,Copy_u8PinLeft);
		CLR_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		break;
	case 4 :
		DIO_u8SetPortDirection(DIO_PORTD,DIO_PORT_HIGH);
		DIO_u8SetPortValue(DIO_PORTD,Arr_DecToSeg[tens]);
		CLR_BIT(PORT_PINS,Copy_u8PinLeft);
		SET_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		DIO_u8SetPortValue(DIO_PORTD,Arr_DecToSeg[ones]);
		SET_BIT(PORT_PINS,Copy_u8PinLeft);
		CLR_BIT(PORT_PINS,Copy_u8PinRight);
		_delay_ms(10);
		break;

	default:
		break;
	}
}

void SSG_ON (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8num , u8 Copy_u8Kind)
{
	switch(Copy_u8Kind)
	{
	case 1 :
		switch(Copy_u8Port)
		{
		case 1 :
			DIO_u8SetPortDirection(DIO_PORTA,DIO_PORT_HIGH);
			DIO_u8SetPortValue(DIO_PORTA,Arr_DecToSeg[Copy_u8num]);
			CLR_BIT(PORT_PINS,Copy_u8Pin);
			break;
		case 2 :
			DIO_u8SetPortDirection(DIO_PORTB,DIO_PORT_HIGH);
			DIO_u8SetPortValue(DIO_PORTB,Arr_DecToSeg[Copy_u8num]);
			CLR_BIT(PORT_PINS,Copy_u8Pin);
			break;
		case 3 :
			DIO_u8SetPortDirection(DIO_PORTC,DIO_PORT_HIGH);
			DIO_u8SetPortValue(DIO_PORTC,Arr_DecToSeg[Copy_u8num]);
			CLR_BIT(PORT_PINS,Copy_u8Pin);
			break;
		case 4 :
			DIO_u8SetPortDirection(DIO_PORTD,DIO_PORT_HIGH);
			DIO_u8SetPortValue(DIO_PORTD,Arr_DecToSeg[Copy_u8num]);
			CLR_BIT(PORT_PINS,Copy_u8Pin);
			break;

		default:
			break;
		}
		break;
		case 2 :
			switch(Copy_u8Port)
			{
			case 1 :
				DIO_u8SetPortDirection(DIO_PORTA,DIO_PORT_HIGH);
				DIO_u8SetPortValue(DIO_PORTA,SevenSegAnode[Copy_u8num]);
				SET_BIT(PORT_PINS,Copy_u8Pin);
				break;
			case 2 :
				DIO_u8SetPortDirection(DIO_PORTB,DIO_PORT_HIGH);
				DIO_u8SetPortValue(DIO_PORTB,SevenSegAnode[Copy_u8num]);
				SET_BIT(PORT_PINS,Copy_u8Pin);
				break;
			case 3 :
				DIO_u8SetPortDirection(DIO_PORTC,DIO_PORT_HIGH);
				DIO_u8SetPortValue(DIO_PORTC,SevenSegAnode[Copy_u8num]);
				SET_BIT(PORT_PINS,Copy_u8Pin);
				break;
			case 4 :
				DIO_u8SetPortDirection(DIO_PORTD,DIO_PORT_HIGH);
				DIO_u8SetPortValue(DIO_PORTD,SevenSegAnode[Copy_u8num]);
				SET_BIT(PORT_PINS,Copy_u8Pin);
				break;

			default:
				break;
			}
			break;
			default:
				break;
	}
}



