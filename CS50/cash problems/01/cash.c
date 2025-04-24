#include <stdio.h>
#include <math.h>

typedef struct {
    int quarters;
    int dimes;
    int nickels;
    int pennies;
} CoinChange;


CoinChange getChange(double amount);
int main(void)
{
    double user;

    do
    {
        printf("Change owed: ");
        scanf("%lf",&user);
    } while (user < 0);
    
    CoinChange ch = getChange(user);
    printf("quarters: %i, dimes: %i, nickels: %i, pennies: %i\n", ch.quarters,ch.dimes,ch.nickels,ch.pennies);
    return 0;
}

CoinChange getChange(double amount)
{
    int cent = round(amount * 100);

    CoinChange change ={0};

    change.quarters += cent / 25;
    cent %= 25;

    change.dimes += cent / 10;
    cent %= 10;

    change.nickels += cent / 5;
    cent %= 5;

    change.pennies = cent;
   

    return change;
}
