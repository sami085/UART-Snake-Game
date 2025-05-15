/**
 * @file Game_Display.h
 *
 * @brief Header code for the Game_Display driver.
 *
 * This file contains the function definitions for the Game_Display driver.
 * The #ifndef & #define preprocessor directives helps avoid complier errors due to other files 
 * containing Game_Display.h. This suggestion was made by ChatGPT.
 *
 * @author Samira Cordero-Morales
 */
 
#ifndef game_display_header
#define game_display_header
/**
 * @brief The Draw_Function function draws the grid of the snake game, the snake, and the food.
 * 
 * Boolean is used to check if a cell is filled with a 'O' or '*'. If neither, the program
 * fills the empty cell with a '.'.
 *
 * @param None
 *
 * @return None
 */
void Draw_Game(void);
#endif