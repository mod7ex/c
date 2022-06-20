#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    * Make a difference between address of a variable and its pointer
      -> address is only a hex number pointer has a type that controls how
         arithmitics are done ...

    * For arrays pointer is the address of the first item
    * The type of the pointer is what determines how arithmitics will be
    * The name of an arrays holds the its pointer (the address of the first item A <==> &A[0])
    * If A is an array of ints of length n then &A is a pointer of type; int (*p)[n]

    * If A is an array then &A is same as &A[0] (not as pointers only as addresses)
      -> pointer &A is of type; <int (*p)[n]>, pointer &A[0] is of <type; int *p>
*/

void pointer_casting()
{
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

void array_pointers()
{
    int A[5] = {0, 1, 2, 3, 4};
    int *p = NULL;
    // p = &A[0];
    p = A; // name of the array is a pointer itself! (can be used as a pointer)
    // but we can't use it for arithmitics (A++, A = A+2 ...)
    
    // (p+i) <==> (A+i) <==> &A[i]
    // *(p+i) <==> *(A+i) <==> A[i]

    printf("%d \n", *(p + 1));
    printf("%d \n", *(A + 2)); // same as A[2]

    return 0;
}

void increment(int *p)
{
    (*p)++;
}

int array_sum(int A[]) // array_sum(int* A)
{
/*
    // in fact the array is passed to the function by refrence (address)
    // it's memory-expensive to copy an array everytime ... so only refrence is passed
    // passing an array is same as (int* A) --A is only the address-- Try 
    int x = 100;
    int *p = NULL;
    p = &x;
    printf("%d \n", p[0]); // pointers and array-names are almost the same
*/

    int i, sum = 0;
    int length = sizeof(A) / sizeof(int); // this will give 1 because A is only a pointer
    // size of the array should be the second argument of the function it should have been 
    // calculated in main array_sum(int *A, size)

    for(i=0; i<length; ++i)
    {
        sum += A[i];
    }

    return sum;
}

int array_double(int A[], int length) // array_sum(int* A)
{
    int i;

    for(i=0; i<length; ++i)
    {
        A[i] *= 2;
    }
}

void string_array()
{
    char C[5] = {'M', 'o', 'd', '\0'}; // '\0' should be added explicitly
    char B = "Mod"; // '\0' is added by default implicitly

}

// *****************************************************
void print_string(const char* C) // const ==> read-only
{
    unsigned short i = 0;

    while (*(C+i) != '\0')
    {
        printf("%c", *(C+i));
        ++i;
    }

    printf("\n");
}

void print_string_0(char* C)
{
    while (*C != '\0')
    {
        printf("%c", *C);
        C++;
    }

    printf("\n");
}

void multi_d_array()
{
/*

    A is an array
    calculations ==>
        &A[i] <==> A+i,
        A[i] <==> *(A+i),
        A[i][j] <==> *(*(A+i)+j)

*/
    int B[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int (*p)[3] = B;

/*

    A is an array
    calculations ==> A[i][j][k] <===> *(*(*(A+i)+j)+k)

*/
    int A[3][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} },
        { {13, 14, 15}, {16, 17, 18} } 
    };

    int (*p)[2][3] = A;
}

void pass_multi_d_array(const int (*A)[2][3])
{

}

// *****************************************************


void main(void)
{
    /*
        pointer has the same type as the variable (that we want to store the address for)
        this is really important why ?
        the pointer points (store) only to the address of the first byte
        so when derefrencing we need to know how many bytes to consider and also how to convert
        the binary value to get the original value (int != float != unsigned double ...)
    */

   /*
    char str[] = "Mourad";
    char c = 'o';
    char *p;

    p = strchr(str, c);
    */

   int a = 10;
   increment(&a);
   // printf("a = %d \n", a);

    int a[5] = {1, 2, 3, 4, 5};

    // ************************************
    int A[] = {1, 2, 3, 4, 5};
    array_sum(A); // only address is passed in fact

    /*

    char *C = "Hello"; // string is stored as a constant, most likely in the text segment in the application memory
    char S[] = "Hello"; // string is stored in the array ,memory stack frame

    C[0] = 'g'; // ==> error
    
    printf("%s \n", C);

    */
}
 