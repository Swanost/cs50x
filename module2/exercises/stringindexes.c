#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = GetString();
    
    if (s != NULL)
    {
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("The character at index %i is %c\n", i, s[i]);
    }
    }
    
}