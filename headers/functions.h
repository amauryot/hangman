#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void update_hangman();
void update_word(char letter, char *word, char *word_backup);
char get_letter();
void select_word(char *secret_word, char *word_backup);

#endif
