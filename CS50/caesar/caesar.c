#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char t[], int key);
void decrypt(char t[], int key);
void usegePrint(void);

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        usegePrint();
        exit(1);
    }

    else if (strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0)
    {
        usegePrint();
        exit(1);
    }

    else
    {
        int lenText = 0;
        int lenKey = 0;

        for (int i = 0; i < argc; i++)
        {
            if (strcmp(argv[i], "-k") == 0 && argv[i + 2] == NULL)
            {
                lenKey += strlen(argv[i + 1]);
                break;
            }
            else if (strcmp(argv[i], "-k") == 0 && argv[i + 2] != NULL)
            {
                puts("Key NOT valid only number without space!");
                exit(1);
                
            }  
            else if ((strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-e") == 0) && argv[i + 1] == NULL)
            {
                puts("Text is empty!");
                exit(1);
            }
            
            lenText += strlen(argv[i]);
        }


        char *plainText = malloc(lenText + 1);
        char *key = malloc(lenKey + 1);

        plainText[0] = '\0';
        key[0] = '\0';

        for (int i = 2; i < argc; i++)
        {
            if (strcmp(argv[i], "-k") == 0)
            {
                strcat(key, argv[i + 1]);
                break;
            }

            strcat(plainText, argv[i]);
            strcat(plainText, " ");
        }

        int intKey = atoi(key);

        if (intKey % 26 == 0)
        {
            puts("Key is not valid, no change will happen!");
            exit(1);
        }
        else if (intKey > 26)
        {
            puts("Key is too big or invalid, resulting in no shift!");
            exit(1);
        }
        
        else if (strcmp(argv[1], "-e") == 0)
        {
            encrypt(plainText, intKey);
        }
        else
        {
            decrypt(plainText, intKey);
        }
        return 0;
    }
}

void encrypt(char t[], int key)
{
    int len = strlen(t);

    char *encryptText = malloc(len + 1);
    int i = 0;

    while (t[i] != '\0')
    {
        if (t[i] == ' ')
        {
            encryptText[i] = ' ';
        }

        else if (t[i] >= 'a' && t[i] <= 'z')
        {
            encryptText[i] = (t[i] + key - 'a') % 26 + 'a';
        }

        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            encryptText[i] = (t[i] + key - 'A') % 26 + 'A';
        }

        else
        {
            encryptText[i] = t[i];
        }
        i++;
        encryptText[i] = '\0';
    }

    printf("encrypt text: %s\n", encryptText);
}

void decrypt(char t[], int key)

{
    int len = strlen(t);
    char *decryptText = malloc(len + 1);
    int i = 0;

    while (t[i] != '\0')
    {
        if (t[i] == ' ')
        {
            decryptText[i] = ' ';
        }

        else if (t[i] >= 'a' && t[i] <= 'z')
        {
            decryptText[i] = ((t[i] - 'a' - key + 26) % 26) + 'a';
        }

        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            decryptText[i] = ((t[i] - 'A' - key + 26) % 26) + 'A';
        }

        else
        {
            decryptText[i] = t[i];
        }
        i++;
        decryptText[i] = '\0';
    }

    printf("decrypt text: %s\n", decryptText);
}

void usegePrint(void)
{
    puts("usege:");
    puts("  for encryption caesar.exe -e <text> -k <key>");
    puts("  for encryption caesar.exe -d <text> -k <key>");
    puts("");
}