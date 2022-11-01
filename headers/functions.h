#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define WORD_MAX_SIZE 20

// Select the secret word and define the standard word backup
void select_word(char *secret_word, char *word_backup);

// Draw the body parts if user make a mistake.
void update_hangman(int mistakes);

// Show the letters in correct position of the word.
void update_word(char user_letter, char *secret_word, char *word_backup);

// Keep the typed letter.
void get_letter(char *user_letter);

// Check if a wrong letter was typed.
void check_mistake(char user_letter, char *secret_word, int *mistakes);

#endif
