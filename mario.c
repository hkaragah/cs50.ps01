#include <stdio.h>
#include <cs50.h>

int get_positive_int(string prompt);
void print_hash(int rep);

int main(void)
{
    // Get the height of the pyramid
    //  the input must be between 1 and 8 inclusive
    int height = get_positive_int("Heihgt (1<=...<=8)?\n");
    // TODO: use positive.c to prompt for positive integer
    print_hash(height);
}

// Get a positive integer between 1 and 8 inclusive
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while ((n < 1) || (n > 8));
    return n;
}

// Display #-blocks with the height of "rep"
void print_hash(int rep)
{
    for (int i = 0; i < rep; i++)
    {
        for (int j = 1; j < (rep - i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
