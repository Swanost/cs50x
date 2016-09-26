#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("float please: ");
    float x = GetFloat();
    printf("float please: ");
    float y = GetFloat();
    printf("%.5f percent\n", (x / y) * 100);
}