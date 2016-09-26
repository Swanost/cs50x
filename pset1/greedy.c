#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    float money;
    
    do
    {
        printf("How much change is owed?: ");
        money = GetFloat();
    }
    while (money < 0);
    
    int coins = round(100 * money);
    int quarters = coins / 25;
    int dimes = (coins % 25) / 10;
    int nickels = ((coins % 25) % 10) / 5;
    int pennies = ((coins % 25) % 10) % 5;
    int total = quarters + dimes + nickels + pennies;
    
    printf("%i\n", total);
}