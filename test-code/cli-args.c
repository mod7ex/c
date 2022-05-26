#include <stdio.h>
#include <stdbool.h>

int main(int argCount, char *argv[])
{
    int numberOfArguments = argCount;
    char *arg1 = argv[0];
    char *arg2 = argv[1];

    printf("Number of arguments: %d \n", numberOfArguments);
    printf("Arg 1: %s \n", arg1);
    printf("Arg 2: %s \n", arg2);

    return 0;
}
