#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int main()
{
    srand(time(NULL));
    int num = rand() % 100 + 1;
    int userGuess;
    int gusses = 10;

    while (1)
    {
        printf("Guess the number, you have %d guess: ", gusses);
        gusses--;

        if (scanf(" %d", &userGuess) != 1)
        {
            printf("Unavailable character!\n");
            while (getchar() != '\n')
                ;

            continue;
        }
        else if (userGuess == num)
        {
            printf("You made it, the number is %d!\n", num);
            break;
        }
        else if (userGuess > num)
        {
            printf("The number is lower!\n");
        }
        else if (gusses == 0)
        {
            printf("You losse!, the number is %d!\n", num);
            break;
        }

        else
        {
            printf("The number is bigger!\n");
        }
    }
    return 0;
}