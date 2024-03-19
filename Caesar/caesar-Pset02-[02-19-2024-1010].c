#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//top up function so that main functions knows how to run this
bool check_digits(string str);
// chartacter to key conversion
char encypher(char plaintext, int key);

int main(int argc, string argv[])
{
    // argument count must be 2
    if (argc == 2)
    {
        // checking the digit in arg[]
        if (check_digits(argv[1]))
        { // converting string to int of arg[1]
            int key = atoi(argv[1]);

            // geting plain text from user
            string plaintext = get_string("Plaintext: ");
            // declaring char array to store cypher text
            char cipher[strlen(plaintext)];

            for (int i = 0; i < strlen(plaintext); i++)
            {
                // encypher function converts plain text to cypher
                char plainchr = encypher(plaintext[i], key);
                cipher[i] = plainchr;
            }
            // value of key is digit then print
            printf("ciphertext: %s\n", cipher);
        }
        else
        {
            // if value of key or argv[1] is not digit
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        // check if argc value is correct or not

        printf("Usage: ./caesar key\n");
        return 1;
    }
}
// this function encripting the text to cyphertext
char encypher(char plaintext, int key)
{
    if (plaintext >= 65 && plaintext <= 90)
    {
        plaintext = (plaintext - 65 + key) % 26 + 65;
    }
    else if (plaintext >= 97 && plaintext <= 122)
    {
        plaintext = (plaintext - 97 + key) % 26 + 97;
    }
    return plaintext;
}
// this function check the argument is digit or not
bool check_digits(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
