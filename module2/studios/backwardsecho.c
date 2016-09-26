#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    
    for (int i = 0; i < argc; i++)
    {
        for (int j = strlen(argv[i]); j > -1; j--)
        {
            printf("%c", argv[i][j]);
        }
        
    }

    printf("\n");
}



// ./backwardsecho test
// argc = 2
// argv[0] = ./backwardsecho
// argv[1] = test
// argv[x][y] = x is word, y is letter