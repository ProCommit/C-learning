#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(void)
{
    char choice;
    while (1)
    {
        double number;
        double number2;
        double sum;
        char op;
        printf("Enter number: ");
        scanf(" %lf", &number);

        printf("Enter operator: ");
        scanf(" %c", &op);

        printf("Enter number: ");
        scanf(" %lf", &number2);

        switch (op)
        {
        case '+': sum = number + number2;
            break;
        case '-': sum = number - number2;
            break;
        case '*': sum = number * number2;
            break; 
        case '/':
            sum = number / number2;
            break;
        default:
            printf("error: %c\n", op);
            break;
        }
        printf("resulte: %.2f\n", sum);
        number = 0;
        number2 = 0;
        sum = 0;
        op = ' ';

        printf("press 'q' to quit or press Enter to continue: ");

        
        while (getchar() != '\n');              
        choice = getchar();

        if (choice == 'q' || choice == 'Q')
        {
            printf("Bye Bye\n");
            break;
        }
        else if (choice == '\n')
        {                  
            clearScreen(); 
        }
    }

    return 0;
}

