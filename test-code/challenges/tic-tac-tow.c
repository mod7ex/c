#include <stdio.h>
#include <stdbool.h>

/*
    here we're playing in a size of 3
    at any size we can imagine the game as a big binary number

    ===========
    || ====== ||
    ||||==>|| ||
    ||||   || ||
    ||=====|| ||
    ===========

    1 0 0 -->
    0 0 --> 1
    0 <-- 0 0
    <-- 0 0 1

    0 1 2
    7 8 3
    6 5 4
*/

// *********************************************************************************** Binary

// #define length sizeof(int) * 8
#define length 9

char b[length];

void toBinary(int n)
{
    for(short unsigned int i=0; i<length; i++)
    {
        b[i] = '0';
    }

    short unsigned int j = 1;

    do
    {
        b[length-j] = n%2 + '0';
        n = n>>1;
        j++;
    } while (n!=0);

    printf("%s \n\n", b);
}

// ***********************************************************************************

static char game[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void displayBoard()
{
    printf("\n");
    printf(" %c | %1c | %2c \n", game[0], game[1], game[2]);
    printf("---|---|----\n");
    printf(" %c | %1c | %2c \n", game[3], game[4], game[5]);
    printf("---|---|----\n");
    printf(" %c | %1c | %2c \n", game[6], game[7], game[8]);
    printf("\n");
}

void markBoard(short unsigned int turn, short unsigned int position)
{
    // player 1 =======> 'x', player 2 =======> 'o'
    game[position -1] = (turn == 1) ? 'x' : 'o';
}

bool isValidPosiontInput(short unsigned int p)
{
    return p<10 && p > 0 && game[p-1] != 'x' && game[p-1] != 'o';
}

short unsigned int play(short unsigned int turn)
{
    short unsigned int position = 0;
    short unsigned int attemp = 0;
    char error[] = "Invalid input; ";

    while (!isValidPosiontInput(position))
    {
        if(attemp == 0) printf("Player %hu turn; ", turn);
        else printf("%sPlayer %hu turn; ", error, turn);

        scanf("%hu", &position);
        attemp++;
    }

    markBoard(turn, position);
    displayBoard();

    return position - 1;
}

static short unsigned int blocks[8];

void init()
{
    for(int k=0; k<4; k++) {
        blocks[k] = (1<<((0+2*k)%8)) + (1<<((1+2*k)%8)) + (1<<((2+2*k)%8));
    }

    blocks[4] = (1<<0) + (1<<8) + (1<<4);
    blocks[5] = (1<<2) + (1<<8) + (1<<6);
    blocks[6] = (1<<3) + (1<<8) + (1<<7);
    blocks[7] = (1<<1) + (1<<8) + (1<<5);
}

bool isWinner(short unsigned int result)
{
    for(int i=0; i<8; i++) {
        toBinary(result & blocks[i]);
        toBinary(blocks[i]);
        if((result & blocks[i]) == blocks[i]) return true;
    }

    return false;
}

bool canPlay(short unsigned int resultA, short unsigned int resultB)
{
    if(isWinner(resultA) || isWinner(resultB)) return false;

    for(int i=0; i<8; i++) {
        if(((resultA & blocks[i]) == 0) || ((resultB & blocks[i]) == 0)) return true;
    }

    return false;
}

void main()
{
    short unsigned int resultPlayer1 = 0;
    short unsigned int resultPlayer2 = 0;

    init();

    displayBoard();
    
    do {
        resultPlayer1 |= 1<<play(1);
        if(!canPlay(resultPlayer1, resultPlayer2)) break;
        resultPlayer2 |= 1<<play(2);
    } while (canPlay(resultPlayer1, resultPlayer2))

    if (isWinner(resultPlayer1)) {
        printf("Player 1 won \n");
    } else if(isWinner(resultPlayer2)) {
        printf("Player 2 won \n");
    } else {
        printf("There was no winner \n");
    }
}