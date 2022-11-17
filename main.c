#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "headers/hangman.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char secret_word[WORD_MAX_SIZE];
    char player_word[WORD_MAX_SIZE];
    char letter;
    int mistakes = 0;

    system("cls");
    start_game(letter, secret_word, player_word, mistakes);

    while (!endgame(player_word, mistakes))
    {
        get_letter(&letter);
        check_mistake(letter, secret_word, &mistakes);
        system("cls");
        update_hangman(mistakes);
        update_word(letter, secret_word, player_word);
    }

    return 0;
}
