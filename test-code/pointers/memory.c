#include <stdio.h>
#include <stdlib.h>

int* add(int* a, int* b)
{
    // Call by refrence

    int *c = (int*)malloc(sizeof(int)); // we will store result in the heap
    *c = (*a) + (*b);
    return c;
}

void main()
{
    int a = 2;
    int b = 3;
    int *x = add(&a, &b);

    printf("%d \n", *x);

    // ************************* Memory ************************* //
/*
    int *p;
    p = (int*) malloc(20*sizeof(int));

    int *q;
    q = (int*) calloc(20, sizeof(int));

    int *r;
    r = (int*) calloc(20, sizeof(int));
    r = (int*) realloc((void*)r, 10*sizeof(int));

    printf("%d \n", *p);
    printf("%d \n", *q);
    printf("%d \n", *r);

    free((void*)p);
    free((void*)q);
    free((void*)r);  

    r = (int*)realloc(r, 0); // equivalent to free((void*)r);
    int *A = (int*)realloc(NULL, 7*sizeof(int)); // equivalent to malloc(7*sizeof(int));

    return 0;
*/
}