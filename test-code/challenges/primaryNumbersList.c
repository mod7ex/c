#include <stdio.h>
#include <stdbool.h>

void main()
{
    int primes[50] = {2, 3};

    short int index = 2;
    bool isPrimary;
    short int p ;

    for(int k = 2; k<49; k++){
        isPrimary = true;
        p = 2*k+1;

        for(int i = 0; isPrimary && p*primes[i]>primes[i]; i++){
            if((p) % primes[i] == 0) isPrimary = false;
        }
        
        if(isPrimary) primes[index++] = p;
    }

    for(int j = 0; j<50; j++) {
        printf("item %i \n", primes[j]);
    }
}