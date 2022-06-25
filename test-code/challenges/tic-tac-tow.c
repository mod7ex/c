#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define length 9

void toBinary(int n)
{
    char b[length];

    for(unsigned short i=0; i<length; i++)
    {
        b[i] = '0';
    }

    unsigned short j = 1;

    do
    {
        b[length-j] = n%2 + '0';
        n = n>>1;
        j++;
    } while (n!=0);

    printf("%s \n\n", b);
}

/*

    Game     ==> 0 0 0 0 0 0 0 0 0
                    1 0 0 -->
                    0 0 --> 1
                    0 <-- 0 0
                    <-- 0 0 1

              1 2 3                              1 2 3
    map ==>   4 5 6 & 1 2 3 4 5 6 7 8 9     ==>  8 9 4  &  1 2 3 8 9 4 7 6 5
              7 8 9                              7 6 5

    player A ==> 0 0 0 1 0 0 1 0 0
    player B ==> 0 1 0 0 0 0 0 1 0

    but we should map the user input so we can get the right bit

*/

char *pPlayerA;
char *pPlayerB;

static unsigned short map_keys[length] = { 1, 2, 3, 8, 9, 4, 7, 6, 5 };

static char game[length] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

unsigned short map(unsigned short i)
{
    return map_keys[i-1];
}

void display(char* arr)
{
    printf("\n");
    printf(" %c | %1c | %2c \n", arr[0], arr[1], arr[2]);
    printf("---|---|----\n");
    printf(" %c | %1c | %2c \n", arr[3], arr[4], arr[5]);
    printf("---|---|----\n");
    printf(" %c | %1c | %2c \n", arr[6], arr[7], arr[8]);
    printf("\n");
}

// ************************** Winning Combinations
static unsigned short WinningCombinations[8];

void init()
{
    for(int k=0; k<4; k++) {
        WinningCombinations[k] = (1<<((0+2*k)%8)) + (1<<((1+2*k)%8)) + (1<<((2+2*k)%8));
    }

    WinningCombinations[4] = (1<<0) + (1<<8) + (1<<4);
    WinningCombinations[5] = (1<<2) + (1<<8) + (1<<6);

    WinningCombinations[6] = (1<<3) + (1<<8) + (1<<7);
    WinningCombinations[7] = (1<<1) + (1<<8) + (1<<5);
}
// ************************** **************************

void markBoard(unsigned short turn, unsigned short position)
{
    // player 1 =======> 'x', player 2 =======> 'o'
    game[position-1] = (turn == 1) ? 'X' : 'O';
}

// ************************** **************************

bool isValidInput(unsigned short p)
{
    return p<10 && p > 0 && game[p-1] != 'X' && game[p-1] != 'O';
}

unsigned short play(unsigned short turn)
{
    unsigned short position = 0;
    unsigned short attemp = 0;
    char error[] = "Ops wrong input please pick an available number between 1 and 9;";

    do {
        if(attemp == 0) printf("Player %s's turn; ", turn == 1 ? pPlayerA : pPlayerB);
        else printf("%s Player %s's turn; ", error, turn == 1 ? pPlayerA : pPlayerB);

        scanf("%hu", &position);
        attemp++;
    } while (!isValidInput(position));

    markBoard(turn, position);
    display(game);

    return position;
}

bool isWinner(unsigned short result)
{
    for(unsigned short i=0; i<8; i++)
    {
        if((result & WinningCombinations[i]) == WinningCombinations[i]) return true;
    }

    return false;
}

bool canPlay(unsigned short resultA, unsigned short resultB)
{
    if(isWinner(resultA) || isWinner(resultB)) return false;

    for(int i=0; i<8; i++) {
        // Can you prove this to be true ? 'Well it is a strong intuition but ...'
        // still hopping for someone to win, block[i] still not touched by one of the players
        if(((resultA & WinningCombinations[i]) == 0) || ((resultB & WinningCombinations[i]) == 0)) return true;
    }

    return false;
}

void main()
{
    char *name = (char*)malloc(100*sizeof(char));

    printf("Let first player fill in his name;\n");
    scanf("%s", name);
    pPlayerA = (char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(pPlayerA, name);

    printf("Great! now let the second player fill in his name also;\n");
    scanf("%s", name);
    pPlayerB = (char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(pPlayerB, name);

    free(name);

    unsigned short resultPlayerA = 0;
    unsigned short resultPlayerB = 0;

    init();

    display(game);

    resultPlayerA |= 1<<(map(play(1)) - 1);
    resultPlayerB |= 1<<(map(play(2)) - 1);
    resultPlayerA |= 1<<(map(play(1)) - 1);
    resultPlayerB |= 1<<(map(play(2)) - 1);

    do {
        resultPlayerA |= 1<<(map(play(1)) - 1);
        if(!canPlay(resultPlayerA, resultPlayerB)) break;
        resultPlayerB |= 1<<(map(play(2)) - 1);
    } while (canPlay(resultPlayerA, resultPlayerB));

    if (isWinner(resultPlayerA)) {
        printf("Player %s won \n", pPlayerA);
    } else if(isWinner(resultPlayerB)) {
        printf("Player %s won \n", pPlayerB);
    } else {
        printf("There was no winner \n");
    }

    free(pPlayerA);
    free(pPlayerB);
}