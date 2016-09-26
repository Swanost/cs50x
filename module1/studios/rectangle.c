#include <cs50.h>
#include <stdio.h>

int main(void)

{
    printf("Width: ");
    int width = GetInt();
    printf("Height: ");
    int height = GetInt();
    
    for (int h = 0; h <= height; h++)
    {
        for (int w = 0; w <= width; w++)
        {
            printf("<3");
        }
        printf("\n");
    }
}