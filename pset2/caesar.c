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
    
    string plaintext = GetString();
    int key = atoi(argv[1]);
    // int key = 13;
    int upper = 'A';
    int lower = 'a';
    int mod = 26;
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            int range = plaintext[i];
            range = range - upper;
            range = (range + key) % mod;
            char cipher = range + upper;
            printf("%c", cipher);
        }
    
        else if (islower(plaintext[i]))
        {
            int range = plaintext[i]; 
            range = range - lower;
            range = (range + key) % mod;
            char cipher = range + lower;
            printf("%c", cipher);
        }
        
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}