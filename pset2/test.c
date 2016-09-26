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
        return 1;
    }
    
    string plaintext = GetString();
    // int key = atoi(argv[1]);
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
        
    }
        
    for (int j = 0, n = strlen(argv[1]); j <= n; j++)
    {
        j = j % strlen(argv[1]);
        key = atoi(argv[1][j]);
        return key;
    }
    
}

int keychange(key, plaintext)
{
    int key = toupper(key) - upper
    key = plaintext + key
    return key;
}

./vigenere bacon
argv[1][0] = b
argv[1][1] = a
argv[1][2] = c
argv[1][4] = n

b - 'a' == 1
a - 'a' == 0
c - 'a' == 2
n - 'a' == 13


key0 == 1
key1 == 0
key2 == 2
key4 == 13
key5 == 1
key6 == 0

key will continue until > strlen(plaintext)


argv[1][j] = b = 1
argv[1][j] - 'a' = 1
key(++) = argv[1][j] - a

j = j % strlen(argv[1])
b a c o n
0 1 2 3 4 0 1 2 3 4 0 1 2 3 4
j = (strlen(argv[1]) % strlen(argv[1]))

key = toupper(argv[1][j]) - upper