#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void start_game();

int win();

int lose();

char get_letter();

int is_valid();

void update_hangman();

void update_word(char letter, char *word);

#endif