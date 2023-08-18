#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if(!input || input == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }

    BYTE buffer[512];
    int imgcount = 0;

    char filename[8];
    FILE* output = NULL;

    while(true)
    {
        int bytesread = fread(buffer, sizeof(BYTE), 512, input);

        if(bytesread == 0 && feof(input))
        {
            break;
        }

        bool JPEGheader = (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0);

        if(JPEGheader && output != NULL)
        {
            fclose(output);
            imgcount++;
        }

        if(JPEGheader)
        {
            sprintf(filename, "%03i.jpg", imgcount);
            output = fopen(filename, "w");
        }

        if(output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesread, output);
        }
    }

    fclose(output);
    fclose(input);

    return 0;

}