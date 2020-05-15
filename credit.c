// Prompt the user for a credit card number
//  and check its ligitamacy

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>


long get_credit_number(string prompt);
int get_length(long number);
string get_creditor(long number);
int get_checksum(long number);
bool ligit_card(long number);
bool eval_creditor(string creditor);



int main(void)
{
    long number = get_credit_number("Credit card number?\n");
    string creditor = get_creditor(number);
    if (strcmp(creditor , "INVALID") == 0)
    {
        printf("INVALID\n");
    }
    else if (ligit_card(number))
    {
        printf("%s\n", creditor);
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_credit_number(string prompt)
// Prompts the user for a credit card number
//  and checks its validity
{
    long number;
    string creditor;

    do
    {
        number = get_long("%s", prompt);
        creditor = get_creditor(number);
    }
    while (!(eval_creditor(creditor)));
    return number;
}


int get_length(long number)
// Returns number of decimals in the number
{
    int length = 0;
    while (number >= 10)
    {
        number = number / 10;
        length += 1;
    }
    length += 1;
    return length;
}


string get_creditor(long number)
// Returns the type of credit card number
//  [AMEX, MASTERCARD, VISA, or INVALID]
{
    int length = get_length(number);
    long first2digits;
    long first_digit;
    string creditor;

    if (length == 15)
    {
        first2digits = number / powl(10, 13);
        if ((first2digits == 34) || (first2digits == 37))
        {
            return "AMEX";
        }
    }
    else if (length == 16)
    {
        first2digits = number / powl(10, 14);
        first_digit = number / powl(10, 15);
        if (first2digits == 51 || first2digits == 52 || first2digits == 53 || first2digits == 54 || first2digits == 55)
        {
            return "MASTERCARD";
        }
        else if (first_digit == 4)
        {
            return "VISA";
        }
    }
    else if (length == 13)
    {
        first_digit = number / powl(10, 12);
        if (first_digit == 4)
        {
            return "VISA";
        }
    }
    return "INVALID";
}


int get_checksum(long number)
// Returns the checksum of the number
//  Checksum equals sum of the followings:
//  1 - sum of every other digit,
//      starting with the number’s second-to-last digit
//      multiplied by two
//  2 - sum of the remaining digits
{
    long checksum = 0;
    int length = get_length(number);

    for (int i = 1; i < length; i += 2)
    {
        checksum += (long)(number / powl(10, i)) % (long)10;
    }
    checksum *= 2;

    for (int i = 0; i < length; i += 2)
    {
        checksum += (long)(number / powl(10, i)) % (long)10;
    }
    return (int)checksum;
}


bool ligit_card(long number)
// Returns True if the checksum modulo 10 is congruent to 0
//  (the checksum's last digit is 0)
{
    int checksum = get_checksum(number);
    if ((checksum % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool eval_creditor(string creditor)
{
    if (strcmp(creditor, "AMEX") == 0)
    {
        return true;
    }
    else if (strcmp(creditor, "MASTERCARD") == 0)
    {
        return true;
    }
    else if (strcmp(creditor, "VISA") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
