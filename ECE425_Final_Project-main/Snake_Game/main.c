/**
 * @file main.c
 *
 * @brief Main source code for the UART Snake Game program.
 *
 * This file contains the main entry point and function definitions for the UART Snake Game program.
 * It interfaces with the Tiva C Series TM4C123G LaunchPad and provides a display of a snake game
 * on the Tera Term terminal.
 *
 * @note For more information regarding the UART module, refer to the
 * Universal Asynchronous Receivers / Transmitters (UARTs) section
 * of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @author Samira Cordero-Morales
*/

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "UART0.h"
#include "Game_Display.h"
#include "Game_Logic.h"
#include "Game_Replay.h"
#include <stdbool.h>

int main(void)
{
	SysTick_Delay_Init();
	UART0_Init();
	
	while(1) // Outer while loop for replayability
	{
		UART0_Output_String("\x1B[2J"); // Clears TeraTerm screen
		UART0_Output_String("\x1B[H"); // Place cursor on top left before printing
		UART0_Output_String("UART Snake Game");
		UART0_Output_Newline();
		UART0_Output_String("Use W, A, S, and D keys to control the moving snake.");
		UART0_Output_Newline();
		UART0_Output_String("For every 10 points, the snake moves faster! Can you reach 50 points?!");
		UART0_Output_Newline();
		UART0_Output_String("Press the SPACEBAR to start the Snake Game! ");
		
		while(1) // Inner while loop to start the game
		{
			if (UART0_Char_Available())
			{
				char start_game = UART0_Input_Character();
				if (start_game == ' ')
				{
					break; // Start Snake Game
				}
			}
		}
		
		UART0_Output_String("\x1B[2J"); // Clears TeraTerm screen
		UART0_Output_String("\x1B[H"); // Place cursor on top left before printing
		Game_Init();
		uint32_t snake_delay_ms = 200;
		
		while(1) // Inner while loop for playing one game
		{
			if (UART0_Char_Available())
			{
				char input = UART0_Input_Character();
				switch (input)
				{
					case 'W':
					case 'w':
					{
						if (current_direction != DOWN)
						{
							current_direction = UP;						
						}
						break;
					}
					case 'S':
					case 's':
					{
						if (current_direction != UP)
						{
							current_direction = DOWN;
						}
						break;
					}
					case 'A':
					case 'a':
					{
						if (current_direction != RIGHT)
						{
							current_direction = LEFT;
						}
						break;
					}
					case 'D':
					case 'd':
					{
						if (current_direction != LEFT)
						{
							current_direction = RIGHT;
						}
						break;
					}
				}
			}
				
			Snake_Move();
				
			// If the snake catches the food
			if (snake[0].x == food.x && snake[0].y == food.y)
			{
				Snake_Grow();
				Food_Init();
					
				// For every 10 points, increase snake's speed
				snake_delay_ms = 200 - (game_score / 10) * 40;
				if (snake_delay_ms < 40)
				{
					snake_delay_ms = 40;
				}
			}
			
			if (Check_Collision())
			{
				UART0_Output_String("\nGAME OVER! Collision hit!");
				UART0_Output_Newline();
				UART0_Output_String("Your final score is ");
				UART0_Output_Unsigned_Decimal(game_score);
				UART0_Output_String(" points.");
				UART0_Output_Newline();
				break; // Exit inner while loop
			}
				
			// When the user reaches 50 points
			if (game_score >= 50)
			{
				UART0_Output_String("\x1B[2J"); // Clears TeraTerm screen
				UART0_Output_String("\x1B[H"); // Place cursor on top left before printing
				
				UART0_Output_Newline();				
				UART0_Output_String("CONGRATULATIONS! You won the UART Snake Game!");
				UART0_Output_Newline();
				UART0_Output_String("Final Score: ");
				UART0_Output_Unsigned_Decimal(game_score);
				UART0_Output_Newline();
				break; // Exit inner while loop
			}
			
			// Game display
			UART0_Output_String("\x1B[2J"); // Clears TeraTerm screen
			UART0_Output_String("\x1B[H"); // Place cursor on top left before printing
				
			UART0_Output_String("UART Snake Game");
			UART0_Output_Newline();
			UART0_Output_String("Use W, A, S, and D keys to control the moving snake.");
			UART0_Output_Newline();
			UART0_Output_String("For every 10 points, the snake moves faster! Can you reach 50 points?!");
			UART0_Output_Newline();
			UART0_Output_Newline();
			
			UART0_Output_String("Game Score: ");
			UART0_Output_Unsigned_Decimal(game_score);
			UART0_Output_Newline();
			UART0_Output_String("Delay Speed: ");
			UART0_Output_Unsigned_Decimal(snake_delay_ms);
			UART0_Output_String(" ms");
				
			Draw_Game();
			SysTick_Delay1ms(snake_delay_ms);
		}
		
		// After winnning or losing the game,
		if (!Play_Again())
		{
			UART0_Output_Newline();
			UART0_Output_String("\nThank you for playing! Exiting Snake Game...");
			break;
		}
	}
	return 0;
}

