/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Sevastyan Che
Student ID#: 181071218
Email      : sche5@myseneca.ca
Section    : NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define min 3
#define max 26
#define minlives 1
#define maxlives 10
#define minpath 10
#define maxpath 70

struct playerstats
{
    char ch;
    int lives;
};

struct gamestats
{
    int path;
    int route[maxpath];
    int bomb[maxpath];
    int treasure[maxpath];
    int exp;
};


int main(void)
{
    int expect1; 
    int expect2;
    int flag = 0;
    int i = 0;
    int j;

    struct playerstats player;
    struct gamestats game;


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.ch);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives < minlives || player.lives > maxlives)

            printf("     Must be between 1 and 10!\n");

        else
            flag = 1;

    } while (flag == 0);

    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        printf("Set the path length(a multiple of 5 between 10 - 70) :");
        scanf("%d", &game.path);
        if (game.path % 5 != 0 || game.path < minpath || game.path > maxpath)
            printf("     Must be a multiple of 5 and between 10 - 70!!!\n");

        else
            flag = 0;

    } while (flag == 1);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.exp);

        if (game.exp < min || game.exp > max)
            printf("    Value must be between 3 and 26\n");
        else
            flag = 1;

    } while (flag == 0);


    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");


    expect1 = game.path / 5;

    for (i = 0; i < expect1; i++) {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.bomb[(i * 5 + j)]);
        }

    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    expect2 = game.path / 5;
    for (i = 0; i < expect2; i++) {

        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);

        for (j = 0; j < 5; j++) {

            scanf("%d", &game.treasure[(i * 5 + j)]);

        }

    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.ch);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path length: %d\n", game.path);
    printf("   Bombs      : ");

    for (i = 0; i < game.path; i++) {
        printf("%d", game.bomb[i]);
    }

    printf("\n   Treasure   : ");

    for (i = 0; i < game.path; i++) {
        printf("%d", game.treasure[i]);
    }


    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}