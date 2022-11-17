#include <locale.h>
#include <stdlib.h>
#include "headers/hangman.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Variables
    char user_letter = '\0';
    char secret_word[WORD_MAX_SIZE];
    char word_backup[WORD_MAX_SIZE];
    int mistakes = 0;

    system("cls");
    start_game(user_letter, secret_word, word_backup, mistakes);

    while (!win(word_backup) && !lose(mistakes))
    {
        get_letter(&user_letter);
        check_mistake(user_letter, secret_word, &mistakes);

        system("cls");
        update_hangman(mistakes);
        update_word(user_letter, secret_word, word_backup);
    }

    return 0;
}
