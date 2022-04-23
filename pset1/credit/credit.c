#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>


int sum_digits(int number)
{
    if (number > 9)
    {
        return number % 10 + 1;
    }
    return number;
}


bool check_luhn(long cc_number)
{
    long number = cc_number;
    long remainder = 0;
    int even_pos_sum = 0;
    int odd_pos_sum = 0;

    int idx = 1;

    while (number != 0)
    {
        remainder = number % 10;
        if (idx % 2 == 0)
        {
            even_pos_sum += sum_digits(remainder * 2);
        }
        else
        {
            odd_pos_sum += remainder;
        }
        number = number / 10;
        idx++;
    }

    if ((even_pos_sum + odd_pos_sum) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const char* check_credit_card_brand(long cc_number)
{
    // America Express 15 digitos, começam com 34 e 37 -> AMEX\n
    if ((cc_number / 10000000000000) == 34 || (cc_number / 10000000000000) == 37)
    {
        /* printf("AMEX\n"); */
        return "AMEX";
    }
    // Master Card 16 digitos, começam com 51 a 55 -> MASTERCARD\n
    else if ((cc_number / 100000000000000) == 51 || (cc_number / 100000000000000) == 52 || (cc_number / 100000000000000) == 53 || (cc_number / 100000000000000) == 54 || (cc_number / 100000000000000) == 55)
    {
        /* printf("MASTERCARD\n"); */
        return "MASTERCARD";
    }
    // Visa usa 13 e 16 Digitos, começam com 4 -> VISA\n
    else if ((cc_number / 1000000000000) == 4 || (cc_number / 1000000000000000) == 4 )
    {
        /* printf("VISA\n"); */
        return "VISA";
    }
    return "INVALID";
}


int main(void)
{
    long cc_number = get_long("CC number: ");
    bool cc_number_is_valid = check_luhn(cc_number);

    if ( cc_number_is_valid)
    {
        printf("%s\n", check_credit_card_brand(cc_number));
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
