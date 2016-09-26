#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int n;
    do
    {
        printf("Countdown from: ");
        n = GetInt();
    }
    while (n < 1);
    
    do
    {
        printf("%i....\n", n);
        n--;
    }
    while (n > 0);
    printf("Blast off!\n");
    
}