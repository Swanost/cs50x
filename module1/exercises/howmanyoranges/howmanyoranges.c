#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    printf("How many orange slices do you want to eat? ");
    float x = GetFloat();
    
    if (x > 0)
    {
       float oranges = ceil (x / 8);
        printf("You should buy %.1f oranges!\n", oranges);
    }
    
    else
    {
        printf("Don't buy any oranges then!\n");
    }
}