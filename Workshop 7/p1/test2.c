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

#define _CRT_SECURE_NO_WARNINGS
#define maxpath 70
#define minpath 10
#define maxlives 10
#define minlives 1
#define ex 5

#include <stdio.h>

struct playerinfo
{
    int lives;        
    char symbol;                
    int treasures;       
    int history[maxpath];  
};

struct gameinfo
{
    int move;  
    int plength; 
    int bomb[maxpath];
    int treasure[maxpath];
};

void placethebomb(struct gameinfo* g)
{
    int i;
    int j; 
    int x = 0; 
    int state = 1;

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", ex);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example:");

    for (i=0; i < ex; i++)
        if (state == 1) { printf(" 1"); state = 2; }

        else if (state == 2) { printf(" 0"); state = 3; }

        else if (state == 3) { printf(" 0"); state = 4; }

        else if (state == 4) { printf(" 1"); state = 1; }

    printf(") NOTE: there are% d to set!\n", g -> plength);

    for (i = 0; i < g -> plength / ex; i++)
    {
        printf("   Positions [%2d-%2d]: ", ex * i + 1, ex * (i + 1));

        for (j = 0; j < ex; j++)
            scanf("%d", &g -> bomb[x++]);
    }
    printf("BOMB placement set\n\n");
    return;
}

void placethetreasure(struct gameinfo* g)
{
    int i;
    int j; 
    int x = 0; 
    int state = 1;

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", ex);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example:");

    for (i = 0; i < ex; i++)
        if (state == 1) { printf(" 1"); state = 2; }

        else if (state == 2) { printf(" 0"); state = 3; }

        else if (state == 3) { printf(" 0"); state = 4; }

        else if (state == 4) { printf(" 1"); state = 1; }

    printf(") NOTE: there are% d to set!\n", g->plength);

    for (i = 0; i < g -> plength / ex; i++)
    {
        printf("   Positions [%2d-%2d]: ", ex * i + 1, ex * (i + 1));

        for (j = 0; j < ex; j++)
            scanf("%d", &g -> treasure[x++]);
    }
    printf("TREASURE placement set\n\n");
    
    return;
}

void configdisp(struct playerinfo* p, struct gameinfo* g)
{
    int i;

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n"); 
    printf("   Symbol     : %c\n", p -> symbol);
    printf("   Lives      : %d\n", p -> lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", g -> plength);
    printf("   Bombs      : ");

    for (i = 0; i < g -> plength; i++)
        printf("%d", g->bomb[i]);

    printf("\n   Treasure   : ");

    for (i = 0; i < g -> plength; i++)
        printf("%d", g -> treasure[i]);
    return;
}

int main(void)
{
    struct playerinfo player = { 0, '\0', 0, {0} };
    struct gameinfo game = { 0, 0, {0}, {0} };

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < minlives || player.lives > maxlives)
            printf("     Must be between %d and %d!\n", minlives, maxlives);
    } while (player.lives < minlives || player.lives > maxlives);

    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", 
            ex, minpath, maxpath);
        scanf("%d", &game.plength);
        if (game.plength < minpath || game.plength > maxpath ||
            game.plength % ex)
            printf("     Must be a multiple of %d and between %d-%d!!!\n", 
                ex, minpath, maxpath);
    } while (game.plength < minpath || game.plength > maxpath || game.plength % ex);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.move);
        if (game.move < player.lives || game.move > (int)(0.75 * game.plength))
            printf("    Value must be between %d and %d\n", 
                player.lives, (int)(0.75 * game.plength));
    } while (game.move < player.lives || game.move >(int)(0.75 * game.plength));

    printf("\n");
    placethebomb(&game);
    placethetreasure(&game);
    printf("GAME configuration set-up is complete...\n\n");
    configdisp(&player, &game);
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    return 0;
}