#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int times;

    printf("How many times would you like to flip the coin? ");
    scanf("%d", &times);

    int heads = 0;
    int tails = 0;

    srand(time(NULL));
    for (int i = 0; i < times; i++)
    {
        int num = rand() % 100 + 1;

        if (num > 50)
        {
            heads++;
        }
        else
        {
            tails++;
        }
    }

    printf("After flipping the coin %d times, the results were\n",times);
    printf("%d heads\n",heads);
    printf("%d tails\n",tails);
    return 0;
}
