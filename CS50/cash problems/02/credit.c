#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int crdidCardCompnyChack(char number[])
{
    int count = strlen(number);
    int flag = 0;
    for (int i = 0; i < count; i++)
    {
        if (!isdigit(number[i]))
        {
            flag++;
        }
    }
    if (flag != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkSum(char number[])
{
    // Array of the numbers that his index dvid by 2
    int listW[30];
    int lisC = 0;

    // Array of the numbers that his index not by 2
    int listN[30];
    int lisN = 0;

    int count = strlen(number);

    // Arrry of the numbers that dvided by 2 and multpliy by 2
    int listM[30];

    // sum of the  numbers that dvid by 2
    int sumlistM = 0;

    // // sum of the  numbers that not dvid by 2
    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 0)
        {
            listW[lisC] = number[i] - '0';
            lisC++;
        }
        else
        {
            listN[lisN] = number[i] - '0';
            lisN++;
        }
    }

    for (int g = 0; g < lisC; g++)
    {
        listM[g] = listW[g] * 2;
    }

    for (int j = 0; j < lisC; j++)
    {
        if (listM[j] < 10)
        {
            sumlistM += listM[j];
        }
        else
        {
            sumlistM += (listM[j] / 10) + (listM[j] % 10);
        }
    }

    for (int t = 0; t < lisN; t++)
    {
        sum += listN[t];
    }

    sum += sumlistM;

    if (sum % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void companyCack(char num[])
{
    char first[3];
    first[0] = num[0];
    first[1] = num[1];
    first[2] = '\0';

    if (strcmp(first, "34") == 0 || strcmp(first, "37") == 0)
    {
        printf("American Express\n");
    }
    else if (strcmp(first, "51") == 0 || strcmp(first, "52") == 0 || strcmp(first, "53") == 0 || strcmp(first, "54") == 0 || strcmp(first, "55") == 0 || strcmp(first, "22") == 0)
    {
        printf("MasterCard\n");
    }
    else if (first[0] == '4')
    {
        printf("Visa\n");
    }
}

int main(void)
{
    char cardNumber[150];

    while (1)
    {
        printf("Number: ");
        scanf("%s", cardNumber);
        int firstCheck = crdidCardCompnyChack(cardNumber);

        if (firstCheck == 0)
        {
            int algoCheck = checkSum(cardNumber);
            if (algoCheck == 0)
            {
                printf("Valid card by ");
                companyCack(cardNumber);
                break;

            }
            else
            {
                puts("Not Valid");
                break;
            }
        }
    }

    return 0;
}
