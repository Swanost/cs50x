#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int guess;
    int s = 8;
    int number_guesses = 1;
    printf("I'm thinking of a number between 1 and 10! Can you guess what it is?\n");
    
    do
    {
        printf("Guess #%i: ", number_guesses);
        guess = GetInt();
        number_guesses++;
        if (guess != s)
        {
            printf("Wrong!\n");
        }
        
        if(number_guesses == 6)
        {
            printf("You're out of guesses!\n");
        }
       
    }
    
    while (guess != s && number_guesses < 6);
   
    if (guess == s)
    {
    printf("Affirmation statement!\n");
    }
        
}