#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("How many people want to vote: ");
        n = GetInt();
    }
    while (n < 1);
    
    int ages[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Age of person #%i: ", i + 1);
        ages[i] = GetInt();
    }
    
    for (int i = 0; i < n; i++)
    {
        if (ages[i] >= 18)
        {
            printf("Person %i can vote!\n", i + 1);
        }
        
        else
        {
            printf("Person %i cannot vote! Loser!\n", i + 1);
        }
    }
}