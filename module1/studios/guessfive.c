#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int guess;
    int s = 8;
    int number_guesses = 1;
    
    printf("I'm thinking of a number between 1 and 10! Can you guess what it is?\n");
    
 
        for (int n = number_guesses; (n < 6) && (guess != s); n++)
        {
            printf("Guess #%i: ", n);
            guess = GetInt();
                if (guess != s)
                {
                    printf("Wrong!\n");
                }
                else
                {
                    printf("You're right!\n");
                }
        }
    
    if (guess != s) 
    {
        printf("You're out of guesses!\n");

    }
    
}