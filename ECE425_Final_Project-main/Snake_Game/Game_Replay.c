/**
 * @file Game_Replay.c
 *
 * @brief Source code for the Game_Replay driver.
 *
 * The boolean function Play_Again prompts the user to play the snake game again.
 * It then checks the user's input with possible 3 cases: Y/y, N/n, or other keys.
 *
 * @author Samira Cordero-Morales
*/

#include "UART0.h"
#include "Game_Replay.h"

bool Play_Again(void)
{
	char reply = 0;
	UART0_Output_Newline();
	UART0_Output_String("Would you like to play again? (Y/N): ");
	
	while(1)
	{
		if (UART0_Char_Available())
		{
			reply = UART0_Input_Character();
			UART0_Output_Character(reply);
			
			if (reply == 'Y' || reply == 'y')
			{
				return true;
			}
			else if (reply == 'N' || reply == 'n')
			{
				return false;
			}
			else
			{
				UART0_Output_Newline();
				UART0_Output_String("Invalid input. Press Y or N: ");
			}
		}
	}
}