#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


const char ascii_letters[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


int ord(char letter)
{
  int index = -1;

    if (isalpha(letter)) {
        for (int i=0; i < 52; i++) {
            if (ascii_letters[i] == letter) {
                index = i;
                break;
            }
        }
    }
  return index;
}


bool key_is_valid(string key)
{
    int key_len = strlen(key);

    if (key_len != 26)
    {
        return false;
    }
    for (int i=0; i < key_len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        for (int j=i+1; j < key_len; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
  return true;
}


int main (int argc, char *argv[], char *envp[])
{
    if (argc != 2) 
    {
        printf("Usage: %s key", argv[0]);
        return 1;
    }

    string key = argv[1];

    if (!key_is_valid(key))
    {
        return 1;
    }

    string message = get_string("Message: ");
    int array_length = strlen(message);
    char cipher_text[array_length + 1];

    for (int i=0; i < array_length; i++ )
    {
        int index = ord(message[i]) % 26;

        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                cipher_text[i] = toupper(key[index]);
            }
            else if (islower(message[i]))
            {
                cipher_text[i] = tolower(key[index]);
            }
        }
        else    
        {
            cipher_text[i] = message[i];
        }
    }
    cipher_text[array_length] = '\0';
    printf("ciphertext: %s\n", cipher_text);
    return 0;
}

