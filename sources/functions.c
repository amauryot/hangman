#include <stdio.h>
#include "headers/functions.h"

void start_game()
{
    // TODO
}

int win()
{
    // TODO
}

int lose()
{
    // TODO
}

char get_letter()
{
    char letter;

    printf("\nInsira uma letra: ");
    scanf("%c", &letter);

    return letter;
}

int is_valid()
{
    // TODO
}

void update_hangman()
{
    printf("   _________   \n");
    printf("   |/      |   \n");
    printf("   |       O   \n");
    printf("   |      /|\\ \n");
    printf("   |      / \\ \n");
    printf("   |           \n");
    printf(" __|__         \n");
    printf("\n");
}

void update_word(char letter, char *word)
{
    for (int i = 0; i < strlen(*word); i++)
    {
        printf("_ ");
    }
}