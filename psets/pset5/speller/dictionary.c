// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 17577;

// giving wordcount to use in size();
unsigned int wordcount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashvalue = hash(word);

    // checking if word equals any stored string
    for (node *cursor = table[hashvalue]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // copying word
    char s[LENGTH+1];

    // converting to lowercase
    for (int i = 0; i < strlen(word) + 1; i++)
    {
        s[i] = tolower(word[i]);
    }

    // setting dummy value
    int a = 1;

    /* calculating hashvalue upto 3 words if given word
    has more than or equal to 3 letters, or else taking
    every letter if its sixe is less than three */

    for (int i = 0; (i < 3) && (i < strlen(s)); i++)
    {
        int b = 1;

        if (s[i] >= 97 && s[i] <= 122)
        {
            b = s[i] - 96;
            a = a * b;
        }
    }

    return a % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *file = fopen(dictionary, "r");

    // checking if file is opened properly
    if (file == NULL)
    {
        return false;
    }

    // allocating memory for word to store into
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        // checking if given storage is not NULL
        if (n == NULL)
        {
            unload();
            return false;
        }

        // copying word into node
        strcpy(n->word, word);

        // giving next value
        n->next = NULL;

        int hashvalue = hash(n->word);

        // applying accepted hashvalue
        node *head = table[hashvalue];

        if (head == NULL)
        {
            table[hashvalue] = n;
            wordcount++;
        }
        else
        {
            n->next = table[hashvalue];
            table[hashvalue] = n;
            wordcount++;
        }
    }

    // closing opened file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //return wordcount which were counted in load();
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // iterate through hashtable
    for (int i = 0; i < N; i++)
    {
        // set pointer to head of list
        node *cursor = table[i];

        // traverse list
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        free(cursor);
    }
    return true;
}
