#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int hour;
    
    do
    {
        printf("What is the hour? ");
        hour = GetInt();
    }
    while (hour > 12 || hour < 1);
    
    printf("How far into the future shall I cast my eye? ");
    int future = GetInt();
    
    printf("My prediction: %i hours hence, the clock shall strike %i!\n", future, (hour + future) % 12);
    
}