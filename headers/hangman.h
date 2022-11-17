#ifndef _HANGMAN_H_
#define _HANGMAN_H_

#define WORD_MAX_SIZE 20

// Initialize the game.
void start_game(char user_letter, char *secret_word, char *word_backup, int mistakes);

// Check if the user got all the letters right.
int win(char *word_backup);

// Check if the user mistake all chances.
int lose(int mistakes);

// Keep the typed letter.
void get_letter(char *user_letter);

// Check if a wrong letter was typed.
void check_mistake(char user_letter, char *secret_word, int *mistakes);

// Draw the body parts if user make a mistake.
void update_hangman(int mistakes);

// Show the letters in correct position of the word.
void update_word(char user_letter, char *secret_word, char *word_backup);

// Select the secret word and define the standard word backup
void select_word(char *secret_word, char *word_backup);

#endif
