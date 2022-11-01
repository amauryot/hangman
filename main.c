#include <locale.h>
#include <stdlib.h>
#include "headers/functions.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Variables
    char user_letter;
    char secret_word[20];
    char word_backup[20];
    int mistakes = 0;

    select_word(secret_word, word_backup);

    while (1)
    {
        system("cls");

        update_hangman();
        update_word(user_letter, secret_word, word_backup);

        user_letter = get_letter();
    }

    return 0;
}
