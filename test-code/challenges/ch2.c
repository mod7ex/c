#include <stdio.h>
#include <stdbool.h>

int main()
{
    int mins;

    printf("Enter the number of mins; \n");

    scanf("%d", &mins);

    double days = mins / (60 * 24);
    double years = days / 365;

    printf("Days %.2lf; \n", days);
    printf("Years %.2lf; \n", years);

    printf("Size of type char occupy %zd Bytes; \n", sizeof(char));
    printf("Size of type short occupy %zd Bytes; \n", sizeof(short));
    printf("Size of type int occupy %zd Bytes; \n", sizeof(int));
    printf("Size of type long occupy %zd Bytes; \n", sizeof(long));
    printf("Size of type long long occupy %zd Bytes; \n", sizeof(long long));
    printf("Size of type float occupy %zd Bytes; \n", sizeof(float));
    printf("Size of type double occupy %zd Bytes; \n", sizeof(double));
    printf("Size of type long double occupy %zd Bytes; \n", sizeof(long double));

    return 0;
}