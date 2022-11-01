#include <locale.h>
#include <stdlib.h>
#include "headers/functions.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Variables
    char user_letter = '\0';
    char secret_word[WORD_MAX_SIZE];
    char word_backup[WORD_MAX_SIZE];
    int mistakes = 0;

    select_word(secret_word, word_backup);

    while (1)
    {
        system("cls");

        update_hangman(mistakes);
        update_word(user_letter, secret_word, word_backup);
        get_letter(&user_letter);
        check_mistake(user_letter, secret_word, &mistakes);
    }

    return 0;
}
