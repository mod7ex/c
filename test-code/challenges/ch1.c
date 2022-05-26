#include <stdio.h>
#include <stdbool.h>

int main()
{
    double height = 6;
    double width = 9;

    double area = width * height;
    double perimeter = (width + height) * 2;

    printf("perimeter: %.2lf \n", perimeter);
    printf("area: %.2lf \n", area);

    enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO };
    enum Company myCompany = GOOGLE;
    printf("My company: %d \n", myCompany);

    return 0;
}


