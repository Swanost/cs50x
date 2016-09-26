#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure a command line argument is included
    if (argc != 4)
    {
        printf("Please include three strings.\n");
        return 1;
    }
    
    int str_len = (argc - 1);
    
    // Make sure strings are three characters long
    for (int i = 1; i <= str_len; i++)
    {
    
        if (strlen(argv[i]) != str_len)
        {
            printf("Strings must be three characters long.\n");
            return 1;
        }
    }

    for (int i = 0; i < str_len; i++)
    {
        for (int j = 1; j < argc; j++)
        {
            printf("%c", argv[j][i]);
        }
        
        printf("\n");
    }

}