#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>


typedef uint8_t BYTE;

int main(int argc, char const *argv[])
{
    if (argc < 4)
    {
        puts("Usage: ./volume input.wav output.wav factor ");
        exit(0);
    }
    else if (argc > 4)
    {
        puts("Usage: ./volume input.wav output.wav factor ");
        exit(0);
    }
    

    FILE *fileInput = fopen(argv[1], "rb");
    FILE *fileOutput = fopen(argv[2], "wb");
    float factor = atof(argv[3]);


    if (fileInput == NULL || fileOutput == NULL)
    {
        puts("File not exsist try agin!");
        exit(1);
    }

    BYTE b;
    BYTE temp[4];
    int c = 0;

    for (int i = 0; i <= 27; i++)
    {
        fread(&b, sizeof(b), 1, fileInput);

        if (i >= 24 && i <= 27)
        {
            temp[c] = b;
            c++;
        }
    }

    

    uint32_t sampleRate = temp[0] | (temp[1] << 8) | (temp[2] << 16) | (temp[3] << 24);
    sampleRate = (uint32_t)(sampleRate * factor);

    temp[0] = sampleRate & 0xFF;
    temp[1] = (sampleRate >> 8) & 0xFF;
    temp[2] = (sampleRate >> 16) & 0xFF;
    temp[3] = (sampleRate >> 24) & 0xFF;


    fseek(fileInput, 0, SEEK_SET);
    int count = 0;
    int f =0;



    while (fread(&b, sizeof(b), 1, fileInput) == 1)
    {

        if (count >= 24 && count <= 27)
        {
            fwrite(&temp[f], sizeof(b), 1, fileOutput);
            f++;
        }
        else
        {
            fwrite(&b, sizeof(b), 1, fileOutput);
        }
        
        count++;
    }
    

    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}
