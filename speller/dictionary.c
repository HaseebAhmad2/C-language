// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <cs50.h>
#include <stdlib.h>
#include<stdio.h>
#include "dictionary.h"
#include<strings.h>
#include<string.h>

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
    // geting index from hash function
    int index = hash(word);
        //checking the word in file
        for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
        {
            //comparing words with words in file
            if (strcasecmp(tmp->word, word) == 0)
            {
                //if the word is present then return true
                return true;
            }

    }
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open the dictionary file
    FILE *fileread;
    fileread = fopen(dictionary,"r");
    //check if file is null
    if (fileread == NULL)
    {
        //closing the file 
        fclose(fileread);
        return false;
    }

    char word[LENGTH];

    while (fscanf(fileread, "%s", word) != EOF)
    {
        // creating new node
        node *n = malloc(sizeof(node));
        // check if n is null.
        if (n == NULL)
        {
            //close the file
            fclose(fileread);

            return false;
        }
        // assigning index to hash word
        int index = hash(word);

        strcpy(n->word, word);
        // Inserting node into Hash table

        n->next = table[index];
        table[index] = n;


    }
    fclose(fileread);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)

{
    // initailizing Countword from 0
    //count word variable is counting the words in the file

    int count_words = 0;
    for (int i = 0; i < 26; i++)
    {   //getting into the nodes of linked list and checking if there is any value in node
        for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            //incrementing the count_word
            count_words++;
        }
    }
    // TODO
    return count_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)

{   // loop for free up the nodes
    for (int i = 0; i < 26; i++)
    {   //initalizing cursor with table first value
        node *cursor=table[i];
        // getting into the linked list
        for (node *tmp = table[i]; cursor != NULL; tmp = cursor)
        {
        //moving cursor to cursor's next
        cursor=cursor->next;
        //free the temp
        free(tmp);
        }

    // TODO
}
    return true;

}
