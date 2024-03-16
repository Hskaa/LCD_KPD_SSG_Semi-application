/*Including libraries*/
#include "../../Librares/BIT_MATH.h"
#include "../../Librares/STD_TYPES.h"

/*Including DIO Files*/
#include "../DIO_Driver/DIO_Interface.h"
#include "../DIO_Driver/DIO_Reg.h"

/****************************************** PORT_Functions ****************************************/

u8 DIO_u8SetPortDirection (u8 Copy_u8Port , u8 Copy_u8Dirc)
{
	u8 Local_u8StateError = 0;

	switch (Copy_u8Port)
	{
	case DIO_PORTA : DDRA = Copy_u8Dirc ; break;
	case DIO_PORTB : DDRB = Copy_u8Dirc ; break;
	case DIO_PORTC : DDRC = Copy_u8Dirc ; break;
	case DIO_PORTD : DDRD = Copy_u8Dirc ; break;
	default: Local_u8StateError = 1;      break;
	}
	return Local_u8StateError ;

}

u8 DIO_u8SetPortValue (u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_u8StateError = 0;

	switch(Copy_u8Port)
	{
	case DIO_PORTA : PORTA = Copy_u8Value ; break;
	case DIO_PORTB : PORTB = Copy_u8Value ; break;
	case DIO_PORTC : PORTC = Copy_u8Value ; break;
	case DIO_PORTD : PORTD = Copy_u8Value ; break;
	default: Local_u8StateError = 1;        break;
	}

	return Local_u8StateError;
}

u8 DIO_u8GetPortValue (u8 Copy_u8Port)
{
	u8 Local_u8InValue = 0 ;

	switch(Copy_u8Port)
	{
	case DIO_PORTA : Local_u8InValue = PINA	 ; break;
	case DIO_PORTB : Local_u8InValue = PINB	 ; break;
	case DIO_PORTC : Local_u8InValue = PINC	 ; break;
	case DIO_PORTD : Local_u8InValue = PIND	 ; break;
	}

	return Local_u8InValue;
}

/****************************************** PIN_Functions ****************************************/
u8 DIO_u8SetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dirc)
{
	u8 Local_u8StateError = 0;

	if(Copy_u8Pin <= DIO_PIN7)
	{
		if(Copy_u8Dirc == DIO_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : CLR_BIT(DDRA ,Copy_u8Pin);	break;
			case DIO_PORTB : CLR_BIT(DDRB ,Copy_u8Pin);	break;
			case DIO_PORTC : CLR_BIT(DDRC ,Copy_u8Pin);	break;
			case DIO_PORTD : CLR_BIT(DDRD ,Copy_u8Pin);	break;
			default : Local_u8StateError = 1;
			}
		}
		else if(Copy_u8Dirc == DIO_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(DDRA ,Copy_u8Pin);	break;
			case DIO_PORTB : SET_BIT(DDRB ,Copy_u8Pin);	break;
			case DIO_PORTC : SET_BIT(DDRC ,Copy_u8Pin);	break;
			case DIO_PORTD : SET_BIT(DDRD ,Copy_u8Pin);	break;
			default : Local_u8StateError = 1;
			}
		}
		else
		{
			Local_u8StateError = 1;
		}
	}
	else
	{
		Local_u8StateError = 1;
	}

	return Local_u8StateError;
}

u8 DIO_u8SetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8StateError = 0;

	if(Copy_u8Pin <= DIO_PIN7)
	{
		if(Copy_u8Value == DIO_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : CLR_BIT(PORTA ,Copy_u8Pin);	break;
			case DIO_PORTB : CLR_BIT(PORTB ,Copy_u8Pin);	break;
			case DIO_PORTC : CLR_BIT(PORTC ,Copy_u8Pin);	break;
			case DIO_PORTD : CLR_BIT(PORTD ,Copy_u8Pin);	break;
			default : Local_u8StateError = 1;
			}
		}
		else if(Copy_u8Value == DIO_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(PORTA ,Copy_u8Pin);	break;
			case DIO_PORTB : SET_BIT(PORTB ,Copy_u8Pin);	break;
			case DIO_PORTC : SET_BIT(PORTC ,Copy_u8Pin);	break;
			case DIO_PORTD : SET_BIT(PORTD ,Copy_u8Pin);	break;
			default : Local_u8StateError = 1;
			}
		}
		else
		{
			Local_u8StateError = 1;
		}
	}
	else
	{
		Local_u8StateError = 1;
	}

	return Local_u8StateError;
}

u8 DIO_u8GetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8InValue = 0;

	switch(Copy_u8Port)
	{
	case DIO_PORTA : Local_u8InValue = GET_BIT(PINA,Copy_u8Pin); 	break;
	case DIO_PORTB : Local_u8InValue = GET_BIT(PINB,Copy_u8Pin); 	break;
	case DIO_PORTC : Local_u8InValue = GET_BIT(PINC,Copy_u8Pin); 	break;
	case DIO_PORTD : Local_u8InValue = GET_BIT(PIND,Copy_u8Pin); 	break;
	}

	return Local_u8InValue;
}
