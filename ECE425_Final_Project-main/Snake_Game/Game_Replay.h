/**
 * @file Game_Replay.h
 *
 * @brief Header code for the Game_Replay driver.
 *
 * Adds the protoype of the Play_Again function.
 * The #ifndef & #define preprocessor directives helps avoid complier errors due
 * to other files containing Game_Replay.h.
 *
 * @author Samira Cordero-Morales
 */
 
 #ifndef game_replay_header
#define game_replay_header
#include <stdbool.h>

/**
 * @brief The Play_Again function displays a prompt asking if the user wants to play again
 * and checks the user's response.
 * 
 * If the user enters an invalid input, the function prompts the user again.
 * 
 * @param None
 *
 * @return False if the user entered "N/n"; true if the user entered "Y/y".
 */
bool Play_Again(void);
#endif