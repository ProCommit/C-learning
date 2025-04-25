#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
    if (argc <= 2 || argc > 3 )
    {
       puts("Usage: ./sayHello.exe Firstname Lastname ");
        exit(0);
    }
    else
    {
        printf("Hello, %s %s!\n",argv[1],argv[2]);
        exit(0);
    }

    return 0;
}
