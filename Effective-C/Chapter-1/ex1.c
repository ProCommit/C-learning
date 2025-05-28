/*
Add a retrieve function to the counting example from Listing 2-6 to retrieve the current value of counter.
 */ 
#include <stdio.h>
#include <stdlib.h>

static unsigned int counter = 0;

void incrment(void)
{
    counter++;
    printf("%d\n",counter);
}

unsigned int status()
{
    return counter;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        incrment();
    }
    
    printf("counter = %d\n",status());

    return EXIT_SUCCESS;
}
