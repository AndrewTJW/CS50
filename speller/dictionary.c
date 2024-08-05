// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
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
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashed_value = hash(word);
    node * cursor = table[hashed_value];
    while (cursor != NULL) {
        if (strcasecmp(word,cursor->word) == 0) {
            return true;
        }
        else {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function (leave it as it is cause idk how)
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++) {
        table[i]= NULL;
    }
    //create a space to store the node aka memory to store dictionary
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL) {
        printf("File %s could not be opened\n", dictionary);
        return 1;
    }

    char buffer[LENGTH];
    while (fscanf(infile, "%s", buffer) != EOF) {
        node *node_dictionary = malloc(sizeof(node));
        if (node_dictionary == NULL) {
            printf("Error allocating memory for node");
            return 1;
        }
        strcpy(node_dictionary->word, buffer);
        int hashed_value = hash(node_dictionary->word);
        node_dictionary->next = table[hashed_value];
        table[hashed_value] = node_dictionary;
    }
    // TODO
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //create temporary varaible to hold the table[N] value
    int counter = 0;
    for (int i = 0; i < N; i++) {
        node * helper = table[i];
        while (helper != NULL) {
            counter++;
            helper = helper->next;
        }
    }
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) {
        node * helper = table[i];
        node * tmp = helper;
        while (helper != NULL) {
            helper = helper->next;
            free(tmp);
            tmp = helper;
        }
    }
    return true;
}
