#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Make sure a command line argument is included
    if (argc != 2)
    {
        printf("Please include your key.\n");
        return 1;
    }
    
    // Make sure key is ALPHA characters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
    
        if (!isalpha(argv[1][i]))
        {
            printf("Key must be alphabetical.\n");
            return 1;
        }
    }
    
    string plaintext = GetString();
    int upper = 'A';
    int lower = 'a';
    int mod = 26;
    int j = 0;
    // Get c[i] = text[i] + key[j]
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
    
        int key = argv[1][j % strlen(argv[1])];
        key = toupper(key) - upper;
        
        if (isupper(plaintext[i]))
        {
            int range = (plaintext[i] - upper);
            range = (range + key) % mod;
            char cipher = range + upper;
            printf("%c", cipher);
            j++;
        }
    
        else if (islower(plaintext[i]))
        {
            int range = (plaintext[i] - lower);
            range = (range + key) % mod;
            char cipher = range + lower;
            printf("%c", cipher);
            j++;
        }
        
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}