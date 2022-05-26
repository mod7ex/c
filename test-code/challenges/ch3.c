#include <stdio.h>
#include <stdbool.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

void main(void)
{
    short int hours;
    double grossPay, taxes, netPay;

    printf("Please enter the number of hours worked this week: \n");

    scanf("%hu", &hours);

    if(hours > 40)
    {
        grossPay = 40 * PAYRATE;
        grossPay += (hours - 40) * (PAYRATE * 1.5);
    } else  grossPay = hours * PAYRATE;

    // taxes
    if(grossPay <= 300)
    {
        taxes = grossPay * TAXRATE_300;
    }
    else if (grossPay > 300 && grossPay <= 450)
    {
        taxes = 300 * TAXRATE_300;
        taxes += (grossPay - 300) * TAXRATE_150;
    }
    else 
    {
        taxes = 300 * TAXRATE_300;
        taxes += 150 * TAXRATE_150;
        taxes += (grossPay - 450) * TAXRATE_REST;
    }

    // NET PAY
    netPay = grossPay - taxes;

    printf("Your net pay is %.2lf \n", netPay);
}