// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>

#include "dictionary.h"

#define MAX_HASH_TABLE_SIZE 100000


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// const unsigned int N = 100000; // warning -> Variable length array folded to constant array as an extension


// Hash table
node * table[MAX_HASH_TABLE_SIZE];
unsigned int table_size = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i=0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    word_copy[n] = '\0';

    int index = hash(word_copy);

    node * cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        else 
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int _hash = 0;
    int i = 0;

    while (word && word[i])
    {
        _hash = (_hash + word[i]) % MAX_HASH_TABLE_SIZE;
        i++;
    }

    return _hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE * file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node * n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }
        n->next = NULL;

        strcpy(n->word, word);
        
        int index = hash(n->word);
        
        n->next = table[index];
        table[index] = n;
        table_size++;


    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return table_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    int i = 0;

    while (table_size > 0)
    {
        node * cursor = table[i];

        while (cursor != NULL)
        {
            node * tmp = cursor;
            cursor = cursor->next;
            free(tmp);
            table_size--;
        }

        i++;

    }

    return true;
}
