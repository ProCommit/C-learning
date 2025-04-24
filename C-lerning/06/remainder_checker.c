#include <stdio.h>




int main(void)
{   
    int x;
    int y;

    puts("Enter a numerator:");
    scanf("%i",&x);
    puts("Enter a denominator:");
    scanf("%i",&y);

    if (x % y == 0)
    {
        puts("There is NOT a remainder!");
    }
    else
    {
        puts("There is a remainder!");
    }
     
    return 0;
}
