// get_string and printf with %s

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Gets the name as a string
    string s = get_string("What's your name?\n");
    // Prints the greeting message including the name on the console
    printf("hello, %s\n", s);
}
