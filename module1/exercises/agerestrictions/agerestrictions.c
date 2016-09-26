#include <cs50.h>
#include <stdio.h>

int main(void)

{
    printf("How old are you? ");
    int age = GetInt();
    
    if (age >= 21)
    {
        printf("You can drink!\n");
    }
    
    if (age >= 18)
    {
        printf("You can vote!\n");
    }
    
    if (age >= 16)
    {
        printf("You can drive!\n");
    }
    
    else
    {
        printf("You can't do much. Sorry kid.\n");
    }
}