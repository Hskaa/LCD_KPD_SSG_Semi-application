/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : MCAL         		***************/
/***************   		SWC : DIO            		***************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*Copy_u8Pin */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/*Copy_u8Pin_Dirc*/
#define OUTPUT			1
#define INPUT			0

/*Copy_u8Port */
#define DIO_PORTA		1
#define DIO_PORTB		2
#define DIO_PORTC		3
#define DIO_PORTD		4

/*COpy_u8Dirc*/
#define DIO_INPUT  0
#define DIO_OUTPUT 1

/*Copy_u8Port_Dirc*/
#define DIO_PORT_INPUT	0X00
#define DIO_PORT_OUTPUT	0XFF

/*Copy_u8PortVal*/
#define DIO_PORT_LOW 	 0x00
#define DIO_PORT_HIGH	 0xff

/*Copy_u8PinVal*/
#define DIO_HIGH  1
#define DIO_LOW   0

/* For pins */
u8 DIO_u8SetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dirc);
u8 DIO_u8SetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
u8 DIO_u8GetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin);



/* For port */
u8 DIO_u8SetPortDirection (u8 Copy_u8Port , u8 Copy_u8Dirc);
u8 DIO_u8SetPortValue (u8 Copy_u8Port , u8 Copy_u8Value);
u8 DIO_u8GetPortValue (u8 Copy_u8Port);

#endif /* 03_MCAL_01_DIO_DRIVER_DIO_INTERFACE_H_ */
