#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/* Ci = (Pi + K) % 26 */
char shift(char c, int offset)
{
    if (c >= 97 && c <= 122)
    {
        if ((c + offset % 26) > 122)
        {
            return c + offset % 26 - 26;
        }
        return c + offset % 26;
    }
    else if (c >= 65 &&  c <= 90)
    {
        if ((c + offset) > 90)
        {
            return c + offset % 26 - 26;
        }
        return c + offset % 26;
    }
}


void encrypt(char *text, int key, int text_len, char *cipher_text)
{

    for (int i=0; i < text_len; ++i)
    {
        if (isalpha(text[i]))
        {
            char c = shift(text[i], key);
            cipher_text[i] = c;
        }
        else
        {
            cipher_text[i] = text[i];
        }
    }
    cipher_text[text_len] = '\0';
}


int main(int argc, string argv[])
{
    /* command line parser */
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i=0, n=strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    /* get user text */
    char *plain_text = get_string("plaintext: ");
    int text_length = strlen(plain_text);
    char cipher_text[text_length];
    /* apply caesar cipher */
    encrypt(plain_text, key, text_length, (char*)cipher_text);
    printf("ciphertext: %s\n", cipher_text);
    return 0;
}
