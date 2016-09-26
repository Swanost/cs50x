#include <stdio.h>
#include <cs50.h>

int mult(int a, int b)
{
    bool toggle = false;
    
    
    if (a == 0 || b == 0)
        return 0;
 
    if (b < 0)
    {    
        b = -b;
        toggle = true;
    }
        
 if (b == 1)
    return a;
 if (toggle == true)
 {
     return -mult(a, b + 1) + a;
 }
 
 else
 {
     return mult(a, b - 1) + a;
 }
}