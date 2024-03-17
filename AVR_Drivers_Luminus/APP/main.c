#include "../Librares/BIT_MATH.h"
#include "../Librares/STD_TYPES.h"

#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "../HAL/SSG/SSG_Interface.h"
#include "../HAL/SSG/SSG_Cfg.h"

/*
int main()
{
	u8 Local_u8PinState = 0;
	DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN1 , DIO_INPUT);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN1 , DIO_HIGH);

	while(1)
	{
		Local_u8PinState = DIO_u8GetPinValue(DIO_PORTA , DIO_PIN1);
		if(Local_u8PinState == 1)
		{
			DIO_u8SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_LOW);
		}
		else if (Local_u8PinState == 0)
		{
			DIO_u8SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH);
		}
	}
}
*/
u8 SSG_Num[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
int main()
{
	PORT_voidInit();
	LCD_void_Init();

	u8 Local_u8PressedKey = 0XFF;

	while(1)
	{
		do
		{
			Local_u8PressedKey=KPD_u8GetPressedKey();
		}while(Local_u8PressedKey==0XFF);
		LCD_voidSendData(Local_u8PressedKey);

		SSG_ON(DIO_PORTC,DIO_PIN7,Local_u8PressedKey-48,CATHODE);
/*
		switch(Local_u8PressedKey)
		{
		case '0':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[0]);		break;
		case '1':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[1]);		break;
		case '2':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[2]);		break;
		case '3':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[3]);		break;
		case '4':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[4]);		break;
		case '5':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[5]);		break;
		case '6':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[6]);		break;
		case '7':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[7]);		break;
		case '8':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[8]);		break;
		case '9':	DIO_u8SetPortValue(DIO_PORTC,SSG_Num[9]);		break;
		}*/
	}
}
