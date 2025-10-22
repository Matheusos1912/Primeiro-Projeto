#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amount;
    do
    {
        amount = get_float("Troco devido: ");
    }
    while (amount < 0);
    int cents = (int) roundf(amount * 100);
    int coins = 0;
    int values[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        coins += cents / values[i];
        cents %= values[i];
    }
    printf("%i\n", coins);

    return 0;
}
