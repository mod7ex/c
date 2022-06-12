#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pointer_casting(){
    unsigned  int x = 126;
    unsigned int *p = NULL;
    p = &x;
    
    char *q = NULL;
    
    q = (char*) p;

    printf("%d \n", p);
    printf("%d \n", q);
    
    printf("%d \n", *p);
    printf("%c \n", *q); // ==> '~'
}

void main(void)
{
    /*
        pointer has the same type as the variable (that we want to store the address for)
        this is really important why ?
        the pointer points (store) only to the address of the first byte
        so when derefrencing we need to know how many bytes to consider and also how to convert
        the binary value to get the original value (int != float != unsigned double ...)
    */

    char str[] = "Mourad";
    char c = 'o';
    char *p;

    p = strchr(str, c);

    printf("hello \n");
}
