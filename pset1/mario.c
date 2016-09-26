#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    int height;
    int width;
    
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while ((height < 0) || (height > 23));
    width = height - 2;
    
        for (int h = 0; h < height; h++)
        {
            for (int b = width; b >= h; b--)
            {
                printf(" ");
                
            }
        for (int w = 1; w <= h; w++)
            {
                printf("#");
            }
            
            
                
            printf("##\n");
            
        }
    
}