#include <stdio.h>



int main(void)
{
    int intArray[]  = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    printf("The array contin %d elements.\n",sizeof(intArray) / sizeof(intArray[0])); 
    // becuse int in c is 4 bits, the sizeof(intArray) = 52 we need to devide by 4 to get the real size!


    
    return 0;
}
