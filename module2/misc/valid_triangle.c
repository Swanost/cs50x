#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float x, float y, float z);

int main(void)

{
    printf("Input the length for each side:\n");
    
    printf("Side 1: ");
    float x = GetFloat();
    
    printf("Side 2: ");
    float y = GetFloat();
    
    printf("Side 3: ");
    float z = GetFloat();
    
    bool triangle = valid_triangle(x, y, z);
    if (triangle == true)
    {
        printf("That's a valid triangle!\n");
    }
    
    if (triangle == false)
    {
        printf("That's not a valid triangle.\n");
    }
}

bool valid_triangle(float x, float y, float z)
{
    if (x <= 0 || y <= 0 || z <=0)
    {
        return false;
    }
    
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }
    
    return true;
}