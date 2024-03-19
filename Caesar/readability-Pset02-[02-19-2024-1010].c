#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string str = get_string("Text: ");

    int i;
    int j;
    int k;
    int csentence = 0;
    int n = strlen(str);
    int count = 0;
    int cwords = 1;
    // this loop is for counting the letters
    for (i = 0; i < n; i++)
    {
        if isalpha (str[i])
        {

            count = count + 1;
        }
    }
    // this loop is for counting the words
    for (j = 0; j < n; j++)
    {
        if (str[j] == ' ')
        {
            cwords = cwords + 1;
        }
    }
    // this loop is for counting the no. of sentences
    for (k = 0; k < n; k++)
    {
        if (str[k] == '.' || str[k] == '!' || str[k] == '?')
        {
            csentence = csentence + 1;
        }
    }

    float L = (count / (float) cwords * 100);
    float S = (csentence / (float) cwords * 100);
    float M = 0.0588 * L;
    float N = 0.296 * S;
    int index = round(M - N - 15.8);
    //if value is less then 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    //if value is greater then 16
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    //if value is between 1 and 16
    if (index >= 1 && index <= 16)
    {

        printf("Grade %i\n", index);
    }
}
