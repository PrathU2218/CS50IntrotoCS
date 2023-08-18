#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_input(string s);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int check = check_input(argv[1]);

    if (check != 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);

    string s = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(s); i++)
    {

        if ((s[i] >= 65) && (s[i] <= 90))
        {
            int q = s[i] - 65;
            int r = q % 26;

            r = (r + k) % 26;

            s[i] = 65 + r;

            printf("%c", s[i]);
        }
        else if ((s[i] >= 97) && (s[i] <= 122))
        {
            int q = s[i] - 97;
            int r = q % 26;

            r = (r + k) % 26;

            s[i] = 97 + r;

            printf("%c", s[i]);
        }
        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");
}

int check_input(string s)
{

    int k = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        k = 0;
        if ((s[i] >= 48) && (s[i] <= 57))
        {
            k = 1;
        }
    }
    return k;
}
