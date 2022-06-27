#include <stdio.h>

void main()
{
    unsigned short choice;

    printf(" Welcome to the Game\n\n");
    
    printf("> Press 7 to start the game\n");
    printf("> Press 0 to quit the game\n");

    scanf("%hu", &choice);

    if(choice == 7)
    {
        printf("The game has started \n\n");
    }
    else if(choice == 0)
    {
        printf("The game has ended \n\n");
    }
    else
    {
        printf("Invalid \n\n");
    }

    unsigned short answer_1;

    if(choice == 7)
    {
        printf("1) What is the first search engine created \n\n");
        printf("--> 1 Google \n");
        printf("--> 2 Archie \n");
        printf("--> 3 Altavista \n");

        scanf("%hu", &answer_1);
    }
}