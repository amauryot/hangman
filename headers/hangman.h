#ifndef _HANGMAN_H_
#define _HANGMAN_H_

#define WORD_MAX_SIZE 20
#define DATABASE_ADDRESS "resources/database.txt"

/**
 * Check if the file is in the ../resources/database.txt.
 */
//void check_file(FILE *file);

/**
 * Generate a random number between 0 and the number of words in the data base (../resources/database.txt).
 */
int random_number(int number_words);

/**
 * Create the default player word.
 */
void default_player_word(char secret_word[], char player_word[]);

/**
 * Select the secret word in the database (../resources/database.txt) and define the default player word.
 */
void select_word(char secret_word[], char player_word[]);

/**
 * Draw the body parts if user make a mistake.
 */
void update_hangman(int mistakes);

/**
 * Show the letters in correct position of the word.
 */
void update_word(char letter, char secret_word[], char player_word[]);

/**
 * Initialize the game.
 */
void start_game(char letter, char secret_word[], char player_word[], int mistakes);

/**
 * Check if the player got all the letters right.
 */
int win(char player_word[]);

/**
 * Check if the player mistake all chances.
 */
int lose(int mistakes);

/**
 * Save the typed letter.
 */
void get_letter(char *letter);

/**
 * Check if a wrong letter was typed.
 */
void check_mistake(char letter, char secret_word[], int *mistakes);

#endif
