#include <locale.h>
#include "headers/functions.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Variables
    char secret_word[20] = "MELANCIA";
    char user_letter = ' ';
    int mistakes = 0;

    start_game();

    while (!win() && !lose())
    {
        user_letter = get_letter();

        if (!is_valid(user_letter))
        {
            mistakes++;
        }

        update_hangman();
        update_word(user_letter, secret_word);
    }

    return 0;
}