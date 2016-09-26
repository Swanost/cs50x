// ask how many minutes in the shower
//    convert minutes into bottles
//    show end result in bottles //
    
#include <cs50.h>
#include <stdio.h>

int main(void)

{
    printf("How many minutes did your shower take? ");
    float minutes = GetFloat();
    float bottles = (minutes * 192) / 16;
    printf ("You used %.2f bottles of water!\n", bottles);
    
}