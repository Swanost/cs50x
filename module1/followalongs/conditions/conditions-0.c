#include<cs50.h>
#include<stdio.h>

int main(void)

{
    // ask user for an integer
    
    printf("I'd like an integer please: ");
    int n = GetInt();

    // analyze user input (somewhat inaccurately)
    
    if (n > 0)
    {
        printf("You picked a positive number!\n");
    }
    else
    {
        printf("You picked a negative number!\n");
    }
}