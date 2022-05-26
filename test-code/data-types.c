#include <stdio.h>
#include <stdbool.h>

/*

--> every data type takes a certain amount of memory that depends on system and hardware
    for example in most computers double takes 8 Bytes (64 bits)

--> mosct cases C compiler will conver or (consider) a float to a double 
    to indicate it's a float add f or F at the end

--> modifiers ==> unsigned ,long ,signed ,short

--> Expressions and statements (usually expression returns a result) statement ends with ';'
    Declaration statment: int x;
    Assignment statment: x = 3;
    Return statment: return 0;
    Function call statment: printf("me do");

--> Assignement operators https://www.tutorialspoint.com/cprogramming/c_assignment_operators.htm

*/

#define MONTHS 12

static int myGlobalVar = 36;

void main(void)
{
    // ********************************** Numeric data types

    static int myGlobalVarInFunc = 66;

    unsigned int i = 6; // %i
    long signed int ii = -36;
    short int iii = 5;

    double d = 1.66666666666666666666666666666885; // %lf
    double dd = 1.7e-4;
    double ddd = -1.7555555555555555e44L; // ...L means long

    float f = 1.3e41;
    float ff = 1.7e4f; // %f

    _Bool bb = 1; // or 0, include <stdbool.h> and use next line
    bool b = true;

    // ********************************** Enums

    enum color {red, yellow, blue};
    enum direction {up, down, left = 10, right}; // right => 11

    enum color cr;
    enum color myColor = red;

    enum gender {male, female};

    enum gender myGender = male;
    enum gender someOtherGender = female;

    bool isMale = (myGender == someOtherGender);

    // ********************************** Char


    char c;
    c = 'T'; // "T" invalide "" is for strings, '' is for characters
    char asciiVar = 65; // ok for ASCII

    // ---- Escape char

    char newLine = '\n';

    // ********************************** Format specifiers
    // https://www.tutorialspoint.com/format-specifiers-in-c

    printf("unsigned interger => %i \n", i);
    printf("signed interger => %d \n", ii);

    printf("floating => %f \n", ff);
    printf("floating precision 2 => %.2f \n", ff);

    printf("double => %lf \n", d);
    printf("double => %e \n", d);
    printf("double => %g \n", dd);

    printf("char => %c \n", c);
    
    printf("boolean => %i \n", b);
    printf("boolean isMale => %i \n", isMale);

    // ********************************** Type casting

    int x = (int)21.36 + (int)69.99;

    // ********************************** Arrays

    int a[5] = {1, 2, 3}; // a[i] will be empty if i is 3, 4 or 5

    // Designated initializers

    int a[5] = {[1] = 1,[3] = 2,[0] = 3}; 

    // -------------------------

    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;
    for(index = 0; index<MONTHS; index++) {
        printf("Month %i has %2i days. \n", index +1, days[index]);
    }

    int jours[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29, 30};
    // jours[1] will be 29, it was 28 but it has been overriten, same thing at position 4

    // ------------------------- Multi dimetional array

    int arr[2][3] = {
        {6, 9, 15},
        {1, 2, 3}
    };

    int matrix[3][3] = { [0][0] = 1, [1][1] = 5, [2][2] = 9 };
}


