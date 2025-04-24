#include <stdio.h>
//  #include <string.h>
#include <ctype.h>

void checkAndScoreTheString(char strinG[]);

int main(void)
{

    char buff[1000] = "";
    printf("Enter a string: ");
    fgets(buff, 999, stdin);

    checkAndScoreTheString(buff);
    return 0;
}

void checkAndScoreTheString(char strinG[])
{
    int letters = 0;
    int words = 1;
    int sentences =0;

    int i = 0;

    while (strinG[i] != '\0')
    {
        if (isalpha(strinG[i]))
        {
            letters++;
        }
        else if (strinG[i] == ' ')
        {
            words++;
        }
        else if (strinG[i] == '.' || strinG[i] == '!' || strinG[i] == '?' )
        {
            sentences++;
        }

        i++;
    }


   
    

    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if ((int)index < 1)
    {
        puts("Before Grade 1");
    }
    else if ((int)index > 16)
    {
        puts("Before Grade 16+");
    }
    else
    {
        printf("Grade %d\n", (int)index);
    }
}