#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* **************** how to create constants **************** */
const char message[] = "The end of the program"; 

#define TAXE_RATE 1.5;
// in C90 we can use 'const' keyword
const double TAXE_RATE_MA = 1.6; // readonly

/* ******************************************************** */

int strLengthInMemory(char str[])
{
    // use strlen instead, from <string.h>
    return sizeof(str) -1;
}

int lengthOfVisibleString(char str[])
{
    // use strlen instead from <string.h>
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }

    return i;
}

void copyString(char dist[], char src[])
{
    short unsigned int length = sizeof(dist);
    short unsigned int i = 0;

    while (i<length)
    {
        dist[i] = src[i];
        ++i;
    }
}

short unsigned int strCompair(char a[], char b[])
{
    short unsigned int a_length = sizeof(a);
    short unsigned int b_length = sizeof(b);

    short unsigned int i = 0;

    while(i<a_length && i<b_length) {
        if(a[i]<b[i]) return 1;
        if(a[i]>b[i]) return -1;
        ++i;
    }

    return 0;
}


void main(void)
{
    printf("The character \0 is used to terminate a string.");

    /*
        if you want to store n characters always choose
        n+1 as a length the last character will be '\0'

        char s[3] = {'a', 'b', 'c'}; // this will create bugs , it should be 4
        printf("%s", s);
    */

    char s[3] = {'a', 'b'};
    // char s[3] = "ab"; // or this
    printf("%i", s[2] == '\0'); // true

    /*
        best practises is don't pick a number (length)
        let the compiler do it for you, unless for some need
    */

    char str[] = {'a', 'b', 'c'};
    // or
    char str[] = {"Hello"};

    /*
        assign after declaration is wrong ==> error

        char ss[100];
        ss = "Mourad"; // error

        or use strcpy()
    */
    char ss[] = "Modex";
    char aa[6];
    strcpy(aa, ss);
    // aa = "Modex"; // is an error

    // dtrcpy doesn't care about length of dist, but with strncpy we can limit the number of characters
    char src[] = "Modex";
    char dist[3];
    strncpy(dist, src, sizeof(dist) -1);
    printf("%s \n", dist); // "Mo"

    char sss[6] = "ab";
    char ccc[4] = "abc";
    strcat(sss, ccc); // sss will change
    strncat(sss, ccc, sizeof(sss)-1-strlen(sss)); // sss will change

    strcmp("hi", "hello");

    return 0;
}
