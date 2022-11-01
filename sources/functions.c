#include <stdio.h>
#include <string.h>
#include "../headers/functions.h"

void update_hangman()
{
    printf("  __________   \n");
    printf("  |/       |   \n");
    printf("  |        O   \n");
    printf("  |       /|\\ \n");
    printf("  |       / \\ \n");
    printf("  |            \n");
    printf(" /|\\          \n\n");
}

void update_word(char letter, char *word, char *word_backup)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (letter == word[i])
        {
            word_backup[i] = letter;
        }

        printf("%c ", word_backup[i]);
    }
}

char get_letter()
{
    char letter;

    printf("\n\nDigite uma letra: ");
    scanf(" %c", &letter);

    return letter;
}

void select_word(char *secret_word, char *word_backup)
{
    strcpy(secret_word, "MELANCIA");
    strcpy(word_backup, "________");
}
