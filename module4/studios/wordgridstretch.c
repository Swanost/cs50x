#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 4)
    {
        printf("Please use three 4 letter words.\n");
        return 1;
    }
    
    int n;
    
    do
    {
        printf("How much should I stretch it by? ");
        n = GetInt();
    }
    while (n < 1);
    
    for(int b = 1; b < argc; b++)
    {
        for(int a = 0; a < n; a++)
        {
            for(int c = 0; c < argc; c++)
            {
                for (int d = 0; d < n; d++)
                {
                    printf("%c", argv[b][c]);
                }
            }
            printf("\n");
        }
    }
}