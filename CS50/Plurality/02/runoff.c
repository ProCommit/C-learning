#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    char name[30];
    int votes;
} Contender;

int addScore(char name[],Contender array[],int len,int score);



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





   
    for (int v = 0; v < numberOfVotes; v++)
    {

        for (int g = 0; g < lenOfargv; g++)
        {
            char holdVotes[20];
            printf("Rank %d:",g+1);
            scanf("%s",&holdVotes);
            if (addScore(holdVotes,contenders,lenOfargv,g) == 1)
            {
                puts("Invalid vote.");
                g--;
            }

        }
        puts("");
    }




    int flag = 1;

    for (int g = 0; g < lenOfargv; g++)
    {
        if (contenders[g].votes < contenders[flag].votes)
        {
            flag = g;
        }
        
    }

    printf("winner: %s",contenders[flag].name);
    
    
    return 0;
}




int addScore(char name[],Contender array[],int len,int score)
{
    for (int i = 0; i < len; i++)
        {
            if (strcmp(array[i].name,name) == 0)
            {
                array[i].votes += score;
                return 0;
            }
        }
        return 1;
};
