#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)

{
    printf("How was your day? ");
    string day = GetString();
    
    if (strlen(day) <= 20)
    {
        printf("Not much of a talker, I see. Maybe elaborate a little more next time.\n");
    }
    
    if ((strlen(day) > 20) && (strlen(day) <= 50))
    {
        printf("Nice! Mine's going well, thanks for asking.\n");
    }
    
    if (strlen(day) > 50)
    {
        printf("zzzzzz... Huh? Oh yeah, totally. I know what you mean...\n");
    }
}