// Promp the user for the requested change
//  then return the minimum number of coins
//  using Greedy Algorithm
//  Available coins are {25c, 10c, 5c, 1c}

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(string prompt);
int get_change(int cents);

int main(void)
{
    float dollars = get_positive_float("Change owed (in dollars)?\n");
    int cents = round(dollars * 100);
    int coins = get_change(cents);
    printf("Return %i coins", coins);
}


float get_positive_float(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);
    }
    while (n < 0);
    return n;
}

int get_change(int cents)
{
    int coins = 0;
    if (cents >= 25)
    {
        coins = cents / 25;
        printf("%i x 25c\n", cents / 25);
        cents = cents % 25;
    }
    if (cents >= 10)
    {
        coins += cents / 10;
        printf("%i x 10c\n", cents / 10);
        cents = cents % 10;
    }
        if (cents >= 5)
    {
        coins += cents / 5;
        printf("%i x 5c\n", cents / 5);
        cents = cents % 5;
    }
        if (cents >= 1)
    {
        coins += cents;
        printf("%i x 1c\n", cents);
    }
    return coins;
}
