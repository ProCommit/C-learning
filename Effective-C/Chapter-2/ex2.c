/*
Declare an array of three pointers to functions and invoke the appropriate function based on an index value passed in as an argument.
*/


#include <stdio.h>
#include <stdlib.h>



void greet1() { puts("Function 1"); }
void greet2() { puts("Function 2"); }
void greet3() { puts("Function 3"); }



void invokP(unsigned int index)
{
    void (*funcs[3])(void) = {greet1,greet2,greet3};
    funcs[index]();

}

int main()
{
    for (int i = 0; i < 3; i++)
    {
       invokP(i);
    }
    
    
    return 0;
}



/*
try 1
void invokP(int **arry)
{
    for (int i = 0; i < 3; i++)
    {
       arry[i] = i;
    }
    
    for (int t = 0; t < 3; t++)
    {
        printf("%d\n",arry[t]);
    }
    
}

int main()
{
    int *pArray[3];
    invokP(pArray);
    return 0;
}
*/