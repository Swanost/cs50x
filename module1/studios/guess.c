#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int guess;
    int s = 8;
    int number_guesses = 0;
    printf("I'm thinking of a number between 1 and 10! Can you guess what it is?\n");
    
    do
    {
        number_guesses++;
        printf("Guess #%i: ", number_guesses);
        guess = GetInt();
        
        if (guess != s)
        {
            printf("Wrong!\n");
        }
    }
    while (guess != s);
    printf("Affirmation statement!\n");
        
}