#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int n;
    do
    {
        printf("Please give me an even int: ");
        n = GetInt();
    }
    while( (n % 2) != 0);
    printf("Thanks for the even int!\n");
}