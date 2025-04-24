#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>




int main(void)
{
    char player1[90] = "";
    char player2[90] = "";

    printf("Player 1: ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = '\0';

    printf("Player 2: ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = '\0';


    if (player1[0] == '\0' && player2[0] == '\0') {
        puts("Pleyer 1 Not enter and plyer 2 not enter string!");
        exit(1);
    } 
    else if (player1[0] == '\0')
    {
        puts("Pleyer 1 Not enter string plyer 2 WINS!");
        exit(1);
    }
    else if (player2[0] == '\0')
    {
        puts("Pleyer 2 Not enter string plyer 1 WINS!");
        exit(1);
    }
    
    


    int i = 0;

    int sumPlayer1 = 0;
    int sumPlayer2 = 0;

    if (player1[0]   == '\0')
    {
        puts("Player 1 not enter work player 2 WINS!");
    }
    



    
    while (player1[i] != '\0')
    {
        if (toupper(player1[i]) == 'A' || toupper(player1[i]) == 'E' ||toupper(player1[i]) == 'I' ||toupper(player1[i]) == 'L' ||toupper(player1[i]) == 'N' ||toupper(player1[i]) == 'O' ||toupper(player1[i]) == 'R' || toupper(player1[i]) == 'S' || toupper(player1[i]) == 'T' || toupper(player1[i]) == 'U')
        {
            sumPlayer1 ++;
        }
        else if (toupper(player1[i]) == 'D' || toupper(player1[i]) == 'G')
        {
            sumPlayer1 += 2;
        }
        else if (toupper(player1[i]) == 'B' || toupper(player1[i]) == 'C' ||toupper(player1[i]) == 'M' ||toupper(player1[i]) == 'P')
        {
            sumPlayer1 += 3;
        }
        else if (toupper(player1[i]) == 'F' || toupper(player1[i]) == 'H' ||toupper(player1[i]) == 'V' ||toupper(player1[i]) == 'W' ||toupper(player1[i]) == 'Y' )
        {
            sumPlayer1 += 4;
        }
        else if (toupper(player1[i]) == 'K')
        {
            sumPlayer1 += 5;
        }
        else if (toupper(player1[i]) == 'J' || toupper(player1[i]) == 'X' )
        {
            sumPlayer1 += 8;
        }
        else if (toupper(player1[i]) == 'Q' || toupper(player1[i]) == 'Z' )
        {
            sumPlayer1 += 10;
        }
       
        

        i++;
    }

    i = 0;

    while (player2[i] != '\0')
    {
        if (toupper(player2[i]) == 'A' || toupper(player2[i]) == 'E' ||toupper(player2[i]) == 'I' ||toupper(player2[i]) == 'L' ||toupper(player2[i]) == 'N' ||toupper(player2[i]) == 'O' ||toupper(player2[i]) == 'R' || toupper(player2[i]) == 'S' || toupper(player2[i]) == 'T' || toupper(player2[i]) == 'U')
        {
            sumPlayer2 ++;
        }
        else if (toupper(player2[i]) == 'D' || toupper(player2[i]) == 'G')
        {
            sumPlayer2 += 2;
        }
        else if (toupper(player2[i]) == 'B' || toupper(player2[i]) == 'C' ||toupper(player2[i]) == 'M' ||toupper(player2[i]) == 'P')
        {
            sumPlayer2 += 3;
        }
        else if (toupper(player2[i]) == 'F' || toupper(player2[i]) == 'H' ||toupper(player2[i]) == 'V' ||toupper(player2[i]) == 'W' ||toupper(player2[i]) == 'Y' )
        {
            sumPlayer2 += 4;
        }
        else if (toupper(player2[i]) == 'K')
        {
            sumPlayer2 += 5;
        }
        else if (toupper(player2[i]) == 'J' || toupper(player2[i]) == 'X' )
        {
            sumPlayer2 += 8;
        }
        else if (toupper(player2[i]) == 'Q' || toupper(player2[i]) == 'Z' )
        {
            sumPlayer2 += 10;
        }

        i++;
    }

    if (sumPlayer1 == sumPlayer2)
    {
        puts("Tilt!");
        exit(0);
    }
    else if (sumPlayer1 > sumPlayer2)
    {
        puts("Pleyer 1 WIN!");
        exit(0);
    }
    else
    {
        puts("Pleyer 2 WIN!");
        exit(0);

    }
    return 0;
}
