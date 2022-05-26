#include <stdio.h>
#include <time.h>


void main()
{
    // time_t t;
    
    // srand((unsigned) time(&t));

    // int gussedNumber = rand() % 21;

    int gussedNumber = 17;
    
    int attemp = 0;
    
    while(attemp != 5){
        int enteredNumber;
        
        printf("Enter number between 0 and 20.\n");
        
        scanf("%i", &enteredNumber);
        
        if(enteredNumber == gussedNumber) {
            printf("you won.\n");
            break;
        }
        
        if(enteredNumber > gussedNumber) printf("too high.\n");
        if(enteredNumber < gussedNumber) printf("too low.\n");

        attemp++;
    }
}