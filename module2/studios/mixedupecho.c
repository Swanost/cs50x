#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < strlen(argv[0]); i++)
    {
       printf("%c", argv[0][i]);
       
       printf("%c", argv[1][i % strlen(argv[1])]);
    }
    printf("\n");
    
}