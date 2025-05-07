#include <stdio.h>

int main(void)
{
    int scotes[4][5];

    int countPalys = 0;
    int countPalysPrint = 1;

    while (countPalys != 4)
    {
        printf("Game #%d\n",countPalysPrint);
        for (int i = 1; i <= 5; i++)
        {
            
            printf("Enter scoring total for Player #%d: ",i);
            scanf("%d",&scotes[countPalys][i]);
        }
        countPalys++;
        countPalysPrint++;
        
    }




    for (int j = 0; j < 4; j++)
    {
       for (int g = 0; g < 5; g++)
       {
        printf("list[%d][%d] = %d\n",j,g,scotes[j][g]);
       }
    
    }
    

    return 0;
}
