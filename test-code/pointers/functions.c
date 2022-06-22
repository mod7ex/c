#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    return a+b;
}

void hello()
{
    printf("Hello");
}

void world(void (*cb)())
{
    cb(); // call-back
    printf(" world\n");
}

void main()
{
    int (*p)(int, int);

    // p = &add;
    p = add; // this is valid also, function name holds the address insid

    // int x = (*p)(1, 2); 
    int x = p(1, 2); // this is valid also
    printf("%d \n\n\n\n", x);

    world(hello);
}