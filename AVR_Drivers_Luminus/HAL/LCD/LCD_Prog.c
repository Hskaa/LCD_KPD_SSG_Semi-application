#include "../../Librares/BIT_MATH.h"
#include "../../Librares/STD_TYPES.h"
#include <util/delay.h>

#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "LCD_Cfg.h"
void LCD_voidSendCommand(u8 Command)
{
	/*Send Command RS = 0*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

	/*Send the command*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Command);

	/*Send Enable */
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(5);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(5);
}

void LCD_voidSendData(u8 Data)
{
	/*Send Command RS = 1*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);

	/*Send the Data*/
	DIO_u8SetPortValue(LCD_DATA_PORT,Data);

	/*Send Enable : Put Pulse High then delay >39 Ms then low */
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(5);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
	_delay_ms(5);

}

void LCD_void_Init(void)
{
	/*Set Data Port as OUTPUT*/
	DIO_u8SetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);

	/*Set RS as Output*/
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_OUTPUT);

	/*Set E as Output*/
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,DIO_OUTPUT);

	/*Delay more than 30 ms*/
	_delay_ms(50);

	/*Make Function Set */
	LCD_voidSendCommand(LCD_8Bit_Mode_2Line);

	/*Display ON OFF CONTROL*/
	LCD_voidSendCommand(LCD_OFF_CURSOR);

	/*Display clear*/
	LCD_voidSendCommand(1);

	/*Wait more than 1.53ms*/
	_delay_ms(2);

	/*Entry Mode Set*/
	LCD_voidSendCommand(LCD_NO_SHIFT);
}


void LCD_voidSendString(char *Data)
{
	u8 Local_u8Counter =0;
	while(Data[Local_u8Counter]!='\0')
	{
		LCD_voidSendData(Data[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void LCD_voidGoToXY(u8 X , u8 Y)
{
	u8 Adress = 0;
	if(X == 0)
	{
		Adress = Y;
	}
	else if (X == 1)
	{
		Adress = 0x40 + Y ;
	}
	else
	{
		//error
	}
	/*Set DD RAM Address */
	LCD_voidSendCommand(Adress+128);	//+128 Set 0b(1)DB6 DB5 DB4 DB3 DB2 DB1 DB0 ,This (1) is 128
}

void LCD_voidClearLCD(void){
	LCD_voidSendCommand(0b00000001);

}

void LCD_voidWriteNumber(s32 Copy_s32Number)
{
	s32 Local_s32Revserved=1;
	if(Copy_s32Number == 0)
	{
		LCD_voidSendData('0');
	}
	if(Copy_s32Number < 0)
	{
		LCD_voidSendData('-');
		Copy_s32Number = Copy_s32Number *-1 ;
	}
	while(Copy_s32Number != 0)
	{
		Local_s32Revserved = (Local_s32Revserved *10) + (Copy_s32Number%10);
		Copy_s32Number = Copy_s32Number / 10;
	}
	while(Local_s32Revserved != 1)
	{
		u8 Local_u8Reminder=Local_s32Revserved %10;
		LCD_voidSendData(48+Local_u8Reminder);
		Local_s32Revserved = Local_s32Revserved / 10;
	}
}


