#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("What is your favorite book? ");
    string book = GetString();
    printf("I love %s!\n", book);
    printf("...actually, %s is kind of meh.\n", book);
}