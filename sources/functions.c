#include <stdio.h>
#include <string.h>
#include "../headers/functions.h"

/**
 * Initialize the game.
 */
void start_game(char user_letter, char *secret_word, char *word_backup, int mistakes)
{
    select_word(secret_word, word_backup);
    update_hangman(mistakes);
    update_word(user_letter, secret_word, word_backup);
}

/**
 * Check if the user got all the letters right.
 */
int win(char *word_backup)
{
    for (int i = 0; i < strlen(word_backup); i++)
    {
        if (word_backup[i] == '_')
        {
            return 0;
        }
    }

    printf("\n\nParab�ns! Voc� venceu o jogo!!!\n\n");
    return 1;
}

/**
 * Check if the user mistake all chances.
 */
int lose(int mistakes)
{
    if (mistakes >= 6)
    {
        printf("\n\n Que pena! Voc� perdeu!!!\n\n");
        return 1;
    }

    return 0;
}

/**
 * Keep the typed letter.
 */
void get_letter(char *user_letter)
{
    printf("\n\nDigite uma letra: ");
    scanf(" %c", &(*user_letter));
}

/**
 * Check if a wrong letter was typed.
 */
void check_mistake(char user_letter, char *secret_word, int *mistakes)
{
    for (int i = 0; i < strlen(secret_word); i++)
    {
        int letter_belongs_word = (user_letter == secret_word[i]);

        if (letter_belongs_word)
        {
            return;
        }
    }

    (*mistakes)++;
}

/**
 * Draw the body parts if user make a mistake.
 */
void update_hangman(int mistakes)
{
    printf("  __________     \n");
    printf("  |/       |     \n");
    printf("  |        %c    \n", (mistakes >= 1 ? 'O' : ' '));
    printf("  |       %c%c%c \n", (mistakes >= 3 ? '/' : ' '), (mistakes >= 2 ? '|' : ' '), (mistakes >= 4 ? '\\' : ' '));
    printf("  |       %c %c  \n", (mistakes >= 5 ? '/' : ' '), (mistakes >= 6 ? '\\' : ' '));
    printf("  |              \n");
    printf(" /|\\          \n\n");
}

/**
 * Show the letters in correct position of the word.
 */
void update_word(char user_letter, char *secret_word, char *word_backup)
{
    for (int i = 0; i < strlen(secret_word); i++)
    {
        int letter_belongs_word = (user_letter == secret_word[i]);

        if (letter_belongs_word)
        {
            word_backup[i] = user_letter;
        }

        printf("%c ", word_backup[i]);
    }
}

/**
 * Select the secret word and define the default word backup.
 */
void select_word(char *secret_word, char *word_backup)
{
    strcpy(secret_word, "BANANA");

    for (int i = 0; i < strlen(secret_word); i++)
    {
        word_backup[i] = '_';
    }
}
