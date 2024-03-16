/******************************************************************/
/******************************************************************/
/***************   		Author : Hossam Medhat		***************/
/***************   		Layer : HAL         		***************/
/***************   		SWC : KEYPAD            	 **************/
/***************   		Version : 1.00      		***************/
/******************************************************************/
/******************************************************************/

#include "../../Librares/STD_TYPES.h"

#include "../../MCAL/DIO_Driver/DIO_Interface.h"


#include "KPD_Cfg.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"

const u8 Local_u8KPDArr[4][4]={
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'o','0','=','+'}
};


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY, Local_u8ColumnIdx ,Local_u8RowIdx ,Local_u8PinState ;



	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for (Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx <COLUMN_NUM ; Local_u8ColumnIdx++)
	{
		/*Activate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx] ,DIO_LOW);

		for (Local_u8RowIdx = 0 ; Local_u8RowIdx <ROW_NUM ; Local_u8RowIdx++)
		{
			/*Read the current row*/
			Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx]);

			/*Check if switch is pressed*/
			if (DIO_LOW==Local_u8PinState)
			{

				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				/*pooling (busy waiting) until the key is released*/
				while(DIO_LOW==Local_u8PinState)
				{
					Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx]);
				}

				return Local_u8PressedKey;
			}
		}

		/*Deactivate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx] ,DIO_HIGH);
	}

	return Local_u8PressedKey;
}



