#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>


int came(int n)
{
    return (int)(n / 3);
}

int die(int n)
{
    return (int)(n / 4);
}

int growth_calc_per_year(int total, int came, int die)
{
    return total + came - die;
}

int growth_calc(int start, int end)
{
    int growth;
    int years = 0;
    int tmp = start;

    if (start == end)
    {
        return years;
    }

    while (true)
    {
        growth = growth_calc_per_year(tmp, came(tmp), die(tmp));
        years++;
        tmp = growth;
        if (growth >= end)
        {
            break;
        }
    }
    return years;
}

int main(void)
{
    int start;
    int end;
    int years;

    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    years = growth_calc(start, end);

    printf("Years: %i", years);
}
