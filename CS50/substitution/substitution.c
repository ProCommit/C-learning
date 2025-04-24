#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void usegePrint(void);
void substitution(char text[], char key[], char flag[], int ziseOfText);

int main(int argc, char const *argv[])
{
    int lenText = 0;
    int i = 3;

    if (argc < 2)
    {
        usegePrint();
        exit(0);
    }
    else if (argc > 1 && strcmp(argv[1], "-h") == 0)
    {
        usegePrint();
        exit(0);
    }
    else if (strcmp(argv[1], "-e") == 0 && strcmp(argv[1], "-d") == 0 && argv[2] == '\0')
    {
        puts("-e or -d flag are missing!");
        exit(0);
    }

    else if (strcmp(argv[2], "-t") == 0 && argv[3] == '\0')
    {
        puts("text is empty!");
        exit(0);
    }

    while (argv[i] != NULL && strcmp(argv[i], "-k") != 0)
    {
        lenText += strlen(argv[i]) + 1;
        i++;
    }
    
    char *text = malloc(lenText + 1);
    char key[27] = "";
    text[0] = '\0';
    i = 3;
    int flag = 0;

    while (argv[i] != NULL)
    {

        if (strcmp(argv[i], "-k") == 0 && argv[i + 2] != NULL)
        {
            puts("key not valid enter key witout space!");
            exit(0);
        }
        else if (strcmp(argv[i], "-k") == 0 && argv[i + 2] == NULL)
        {
            if (strlen(argv[i + 1]) > 26)
            {
                puts("key not valid enter key with 26 letters!");
                exit(0);
            }

            for (int k = 0; k < 26; k++)
            {
                if (!isalpha(argv[i + 1][k]))
                {
                    puts("key not valid enter key need contain only letters!");
                    exit(0);
                }
                strcpy(key, argv[i + 1]);
            }
            flag = 1;
        }
        else if (flag == 0)
        {
            strcat(text, argv[i]);
            strcat(text, " ");
        }
        i++;
    }

    substitution(text, key, argv[1], lenText);

    return 0;
}

void substitution(char text[], char key[], char flag[], int ziseOfText)
{
    char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    char *encryptText = malloc(ziseOfText + 1);
    encryptText[ziseOfText] = '\0';
    int c = 0;

    if (strcmp(flag, "-e") == 0)
    {
        while (text[c] != '\0')
        {

            for (int i = 0; i < 26; i++)
            {
                if (tolower(text[c]) == abc[i])
                {
                    if (isupper(text[c]) != 0)
                    {
                        encryptText[c] = toupper(key[i]);
                        break;
                    }
                    else
                    {
                        encryptText[c] = tolower(key[i]);
                        break;
                    }
                }
                else
                {
                    encryptText[c] = text[c];
                }
            }

            c++;
        }

        printf("encrypt text = %s  \n", encryptText);
    }

    else if (strcmp(flag, "-d") == 0)
    {
        while (text[c] != '\0')
        {

            for (int i = 0; i < 26; i++)
            {
                if (tolower(text[c]) == tolower(key[i]))
                {
                    if (isupper(text[c]) != 0)
                    {
                        encryptText[c] = toupper(abc[i]);
                        break;
                    }
                    else
                    {
                        encryptText[c] = tolower(abc[i]);
                        break;
                    }
                }
                else
                {
                    encryptText[c] = text[c];
                }
            }

            c++;
        }

        printf("decrypt text = %s  \n", encryptText);
    }
}

void usegePrint(void)
{
    puts("usege:");
    puts("  for encryption substitution.exe -e -t <text> -k <key>");
    puts("  for encryption substitution.exe -d -t <text> -k <key>");
    puts("");
}