#include <stdio.h>



void checks(int num)
{
    if (num < 0 || num > 500)
    {
        puts("Your number is not between 1 and 500!");
    }
    else if (num > 1 && num < 100)
    {
        puts("Your number is between 1 and 100!");
    }else if (num > 101 && num < 200)
    {
        puts("Your number is between 101 and 200!");
    }else if (num > 201 && num < 300)
    {
        puts("Your number is between 201 and 300!");
    }else if (num > 301 && num < 400)
    {
        puts("Your number is between 301 and 400!");
    }else{
        puts("Your number is between 401 and 500!");
    }
    
    
    
    
}



int main(void)
{
    int userInput;

    printf("Enter a number between 1 and 500:");
    scanf("%d",&userInput);
    checks(userInput);


    return 0;
}
