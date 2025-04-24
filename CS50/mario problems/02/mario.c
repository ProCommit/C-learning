#include <stdio.h>
#include <stdlib.h>

void cratePyramids(int high);



int main(void)
{
    int amount;

    puts("Enter the high of the pyramids: ");
    scanf("%i",&amount);
    system("cls");
    cratePyramids(amount);
    return 0;
}




void cratePyramids(int high)
{

    int bricks = 1;
    int space = high -1;

    for (int i = 0; i < high; i++)
    {
        for (int j = 0;j < space ; j++)
        {
            printf(" ");
        }
        space--;
        
        for (int k = 0; k < bricks; k++)
        {
            printf("#");
            
        }
        printf("   ");

        for (int l = 0; l < bricks; l++)
        {
            printf("#");  
        }


        printf("\n");
        bricks++;
    }
    
}
