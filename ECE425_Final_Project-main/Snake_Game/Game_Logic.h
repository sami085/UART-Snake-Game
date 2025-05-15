/**
 * @file Game_Logic.h
 *
 * @brief Header code for the Game_Logic driver.
 *
 * This file contains the function definitions for the Game_Logic driver.
 * The #ifndef & #define preprocessor directives helps avoid complier errors due to other files 
 * containing Game_Logic.h. This suggestion was made by ChatGPT.
 *
 * @author Samira Cordero-Morales
 */
 
// game_logic.h
#ifndef game_logic_header
#define game_logic_header
#include <stdint.h>
#include <stdbool.h>

#define GRID_WIDTH	20
#define GRID_HEIGHT 10
#define MAX_SNAKE_LENGTH 50
#define INITIAL_SNAKE_LENGTH 3

typedef enum 
{
	UP,
	DOWN,
	LEFT,
	RIGHT
} Direction;

typedef struct
{
	uint8_t x;
	uint8_t y;
} Coord;

extern Coord food;
extern Coord snake[MAX_SNAKE_LENGTH];
extern uint8_t snake_length;
extern Direction current_direction;
extern uint32_t game_score;

/**
 * @brief The Food_Init function initializes the placement of the food.
 * 
 * The coordinates of the food were determined by a random number, a modulo operator, 
 * and the grid's width/length.
 *
 * @param None
 *
 * @return None
 */
void Food_Init(void);

/**
 * @brief The Game_Init function initializes the game state, snake, food, and game score.
 * 
 * The coordinates of the food were determined by a random number, a modulo operator, 
 * and the grid's width/length.
 *
 * @param None
 *
 * @return None
 */
void Game_Init(void);

/**
 * @brief The Snake_Move function updates the snake's position and movement based on its
 * current direction.
 * 
 * @param None
 *
 * @return None
 */
void Snake_Move(void);

/**
 * @brief The Snake_Grow function increments the snake's length and game score.
 * 
 * @param None
 *
 * @return None
 */
void Snake_Grow(void);

/**
 * @brief The Check_Collision function checks if the snake hits a wall or itself.
 * 
 * @param None
 *
 * @return False if a collision has NOT occurred; true if a collision has occurred.
 */
bool Check_Collision(void);
#endif