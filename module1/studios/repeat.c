#include <stdio.h>
#include <cs50.h>

int main(void)


{
    int times;

    printf("Give me a phrase: ");
    string phrase = GetString();
    
    do
    {
        printf("How many times should I say it? (Between 1 and 100): ");
        times = GetInt();
    }
    while ((times < 1) || (times > 100));
    
    for (int p = 1; p <= times; p++)
    {
        printf("%s\n", phrase);
    }
}