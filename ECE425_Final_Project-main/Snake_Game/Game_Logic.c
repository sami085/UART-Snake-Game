/**
 * @file Game_Logic.c
 *
 * @brief Source code for the Game_Logic driver.
 *
 * This file contains the function definitions for the Game_Logic driver.
 * Food_Init initializes the placement of the food, Game_Init initializes the first placement
 * of the snake, the food, and the game score.
 * Snake_Move allows the snake to keep moving in its current direction, and Snake_Grow allows the snake
 * to "grow" when it "eats" one food.
 * The boolean function checks if the moving snake hits the wall or itself.
 *
 * @author Samira Cordero-Morales
*/

#include "Game_Logic.h"
#include <stdlib.h>
#include <stdbool.h>

Coord food;
Coord snake[MAX_SNAKE_LENGTH];
uint8_t snake_length = 3;
Direction current_direction = RIGHT;
uint32_t game_score = 0;

void Food_Init(void)
{
	food.x = rand() % GRID_WIDTH;
	food.y = rand() % GRID_HEIGHT;
}

void Game_Init(void)
{
	// Head of snake
	snake[0].x = GRID_WIDTH / 2;
	snake[0].y = GRID_HEIGHT / 2;
	
	// Body of snake
	snake[1].x = (GRID_WIDTH / 2) - 1;
	snake[1].y = (GRID_HEIGHT / 2) - 1;
	
	// Tail of snake
	snake[2].x = (GRID_WIDTH / 2) - 2;
	snake[2].y = (GRID_HEIGHT / 2) - 2;
	snake_length = INITIAL_SNAKE_LENGTH;
	current_direction = RIGHT;
	
	Food_Init();
	
	game_score = 0;
}

void Snake_Move(void)
{
	for (int i = snake_length - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}
	
	switch (current_direction)
	{
		case UP:
		{
			snake[0].y--; 
			break;
		}
		case DOWN:
		{
			snake[0].y++; 
			break;
		}
		case LEFT:
		{
			snake[0].x--; 
			break;
		}
		case RIGHT:
		{
			snake[0].x++; 
			break;
		}
	}
}

void Snake_Grow(void)
{
	if (snake_length < MAX_SNAKE_LENGTH)
	{
		snake[snake_length] = snake[snake_length - 1];
		snake_length++;
		game_score = snake_length - INITIAL_SNAKE_LENGTH;
	}
}

bool Check_Collision(void)
{
	if (snake[0].x >= GRID_WIDTH || snake[0].y >= GRID_HEIGHT || snake[0].x <0 || snake[0].y <0)
	{
		return true;
	}
	
	for (int i = 1; i < snake_length; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
		{
			return true;
		}
	}
	return false;
}