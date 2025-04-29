#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    char name[30];
    int votes;
} Contender;




int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        puts("usege: plurality.exe [candidate ...] ");
        exit(1);
    }

    int lenOfargv = 0;
    int numberOfVotes =0;
   
    while (argv[lenOfargv] != NULL)
    {
        lenOfargv++;
    }
    lenOfargv--;


    Contender *contenders = malloc(lenOfargv * sizeof(Contender));
    
    for (int i = 1; i < argc; i++)
    {
        strcpy(contenders[i - 1].name, argv[i]);
        contenders[i - 1].votes = 0;

    }
    printf("Number of voters:");
    scanf("%d", &numberOfVotes);


    int found = 0;

    for (int v = 0; v < numberOfVotes; v++)
    {
        char holdVotes[20];
        printf("Vote: ");
        scanf("%s",&holdVotes);
        
        for (int i = 0; i < lenOfargv; i++)
        {
            if (strcmp(contenders[i].name,holdVotes) == 0)
            {
                contenders[i].votes++;
                found = 1;
                break;
            }
            found = 0;
        }

        if (found == 0)
        {
            puts("Invalid vote.");
            v--;
        }

    }

    int flag = 1;

    for (int g = 0; g < lenOfargv; g++)
    {
        if (contenders[g].votes > contenders[flag].votes)
        {
            flag = g;
        }
    }

    printf("winner: %s, with score: %d\n",contenders[flag].name,contenders[flag].votes);
    
    
    return 0;
}
