#include <stdio.h>
#include <stdlib.h>

int foo()
{
    // static int b = 0;
    int b = 0;

    printf("%i \n", b);

    b++;
}

void main(void)
{
    foo();
    foo();
    foo();
    foo();

    int i;
    char str[100];

    printf("inter some data : ");

    scanf("%d %s", &i, str);

    printf("\nHello %s %d !\n", i, str);

    // *****************************

    /*
        // infinit loop
        
        for(;;){
            whatever code ...
        }
    */
}
