#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>


int change_calc(float change, int *denomination)
{
    int total = 0;
    int idx = 0;

    while (true)
    {
        if (change < denomination[idx])
        {
            idx++;
            continue;
        }

        int remain = (int)change % denomination[idx];
        int coins = trunc(change / denomination[idx]);

        while (true)
        {
            total++;
            coins--;

            if (coins == 0)
            {
                break;
            }
        }

        if (remain == 0)
        {
            break;
        }

        change = remain;
        idx += 1;
    }
    return total;
}


int main(void)
{
    int denomination[4] = {25, 10, 5, 1};
    float change;

    do
    {
        change = get_float(": ");
    }
    while (change < 0);

    change = (change + .0001) * 100;

    printf("%i\n", change_calc(change, denomination));
}
