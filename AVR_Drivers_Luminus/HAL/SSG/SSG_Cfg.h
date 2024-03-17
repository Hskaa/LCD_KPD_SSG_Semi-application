/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : HAL         		***************/
/***************   		SWC : SSG            		***************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/
#ifndef HAL_SSG_SSG_CFG_H_
#define HAL_SSG_SSG_CFG_H_

#define SSG_PORT	3	/*1- PORTA
						  2- PORTB
						  3- PORTC
						  4- PORTD */

#define PORT_PINS	PORTA	/*1- PORTA
						  2- PORTB
						  3- PORTC
						  4- PORTD */

#define Copy_PinLeft	0
#define Copy_PinRight   1

#define CATHODE			1
#define ANODE			2


typedef struct SSG {
	u8 Copy_u8Port;
	u8 num;
	u8 Copy_u8PinLeft ;
	u8 Copy_u8PinRight;
}SSG;

#endif /* HAL_SSG_SSG_CFG_H_ */
