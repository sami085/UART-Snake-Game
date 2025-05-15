/**
 * @file Game_Display.c
 *
 * @brief Source code for the Game_Display driver.
 *
 * This file contains the function definitions for the Game_Display driver.
 * More information about the Draw_Game function is on the header code of the Game_Display driver.
 *
 * @author Samira Cordero-Morales
*/
 
#include "Game_Logic.h"
#include "Game_Display.h"
#include "UART0.h"
#include <stdbool.h>

void Draw_Game(void)
{
	UART0_Output_Newline();
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			bool printed = false;
			
			for (int l = 0; l < snake_length; l++)
			{
				if (snake[l].x == x && snake[l].y == y)
				{
					UART0_Output_Character('O');
					printed = true;
					break;
				}
			}
			
			if (food.x == x && food.y == y)
			{
				UART0_Output_Character('*');
				printed = true;
			}
			
			if (!printed)
			{
				UART0_Output_Character('.');
			}
		}
		UART0_Output_Newline();
	}
}