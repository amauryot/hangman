#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/hangman.h"

/**
 * Check if the file is in the resources/database.txt.
 */
void check_file(FILE *file)
{
    if (file == NULL)
    {
        printf("+-------------------------------------------------------------+\n");
        printf("|                        *** ERRO ***                         |\n");
        printf("| Desculpe, banco de dados não disponível.                    |\n");
        printf("| Verifique se o arquivo está na pasta %s |\n", DATABASE_ADDRESS);
        printf("+-------------------------------------------------------------+\n");
        exit(1);
    }
}

/**
 * Generate a random number between 0 and the number of words in the data base (resources/database.txt).
 */
int random_number(int number_words)
{
    srand(time(0));

    return rand() % number_words;
}

/**
 * Create the default player word.
 */
void default_player_word(char secret_word[], char player_word[])
{
    for (int i = 0; i < strlen(secret_word); i++)
    {
        player_word[i] = '_';
    }
}

/**
 * Select the secret word in the database (resources/database.txt) and define the default player word.
 */
void select_word(char secret_word[], char player_word[])
{
    FILE *file = fopen(DATABASE_ADDRESS, "r");

    check_file(file);

    int number_words;
    fscanf(file, "%d", &number_words);

    int random = random_number(number_words);

    for (int i = 0; i <= random; i++)
    {
        fscanf(file, "%s", secret_word);
    }

    fclose(file);

    default_player_word(secret_word, player_word);
}

/**
 * Draw the body parts if user make a mistake.
 */
void update_hangman(int mistakes)
{
    printf("+----------------+\n");
    printf("| H A N G  M A N |\n");
    printf("+----------------+\n");
    printf("  __________       \n");
    printf("  |/       |       \n");
    printf("  |        %c      \n", (mistakes >= 1) ? 'O' : ' ');
    printf("  |       %c%c%c   \n", (mistakes >= 3) ? '/' : ' ', (mistakes >= 2) ? '|' : ' ', (mistakes >= 4) ? '\\' : ' ');
    printf("  |       %c %c    \n", (mistakes >= 5) ? '/' : ' ', (mistakes >= 6) ? '\\' : ' ');
    printf("  |                \n");
    printf("__|__            \n\n");
}

/**
 * Show the letters in correct position of the word.
 */
void update_word(char letter, char secret_word[], char player_word[])
{
    for (int i = 0; i < strlen(secret_word); i++)
    {
        if (letter == secret_word[i])
        {
            player_word[i] = letter;
        }

        printf("%c ", player_word[i]);
    }
}

/**
 * Initialize the game.
 */
void start_game(char letter, char secret_word[], char player_word[], int mistakes)
{
    select_word(secret_word, player_word);
    update_hangman(mistakes);
    update_word(letter, secret_word, player_word);
}

/**
 * Check if the player got all the letters right.
 */
int win(char player_word[])
{
    for (int i = 0; i < strlen(player_word); i++)
    {
        if (player_word[i] == '_')
        {
            return 0;
        }
    }

    printf("\n\nParabéns! Você venceu o jogo!!!\n\n");

    return 1;
}

/**
 * Check if the player mistake all chances.
 */
int lose(int mistakes)
{
    if (mistakes >= 6)
    {
        printf("\n\n Que pena! Você perdeu!!!\n\n");

        return 1;
    }

    return 0;
}

/**
 * Save the typed letter.
 */
void get_letter(char *letter)
{
    printf("\n\nDigite uma letra: ");
    scanf(" %c", &(*letter));
}

/**
 * Check if a wrong letter was typed.
 */
void check_mistake(char letter, char secret_word[], int *mistakes)
{
    for (int i = 0; i < strlen(secret_word); i++)
    {
        if (letter == secret_word[i])
        {
            return;
        }
    }

    (*mistakes)++;
}
