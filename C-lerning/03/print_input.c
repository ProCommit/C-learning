#include <stdio.h>


int main(void)
{
    char name[15];
    char last_name[15];

    printf("Enter Your First Name:\n");
    scanf("%s",&name);
    printf("Enter Your Last Name:\n");
    scanf("%s",&last_name);

    printf("Wellcome %s %s!",name,last_name);
    return 0;
}
