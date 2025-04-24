#include <stdio.h>
#include <stdlib.h>

void cratePyramid(int high);



int main(void)
{
    int amount;
    
    puts("Enter the high of the pyramids: ");
    scanf("%i",&amount);
    system("cls");
    cratePyramid(amount);
    return 0;
}



void cratePyramid(int high)
{
    int bricks = 1;
    int space = high - 1;
    for (int i = 0; i < high; i++)
    {
        for (int g = 0; g < space; g++)
        {
            printf(" ");
        }
        space--;
        

        for (int j = 0; j < bricks; j++)
        {

            printf("#");
        }
        printf("\n");
        bricks++;
    }
}
