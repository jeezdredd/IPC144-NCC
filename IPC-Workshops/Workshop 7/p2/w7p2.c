/*
*****************************************************************************
						  Workshop - #7 (P2)
Full Name  : Sevastyan Che
Student ID#: sche5@myseneca.ca
Section    : NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define maxlength 70 
#define minlength 10
#define maxlifes 10 
#define minlifes 1 
#define maxmoves 15 
#define minmoves 3 
#define ex 5 

int main(void)
{
	int m = 0;
    int temp = 1; 
    int temporaryst = 1;
    int i;
    int j = 1; 

	struct playerinfo 
	{
		int totallives;
        int totaltreasures;
        int pastpositions[maxlength]; 
        int treasobt;
		char player;
        char trail[maxlength]; 
	};

	struct gameinfo 
	{
        int movesallowed;
        int pathlength;
        int bomb[maxlength];
        int treasure[maxlength]; 
	};

	printf("================================\n         Treasure Hunt!\n================================\n\n");
	printf("PLAYER Configuration\n--------------------\n");
	printf("Enter a single character to represent the player: ");

	struct playerinfo playersetup; 
	scanf(" %c", &playersetup.player); 

	do 
	{
		printf("Set the number of lives: ");
		scanf(" %d", &playersetup.totallives); 
		if ((playersetup.totallives >= minlifes) && (playersetup.totallives <= maxlifes))
		{
			temp = 0; 
			printf("Player configuration set-up is complete\n\n");
		}

		else
		{
			printf("     Must be between %d and %d!\n", minlifes, maxlifes); 
		}
	} while (temp); 

	printf("GAME Configuration\n------------------\n");
	struct gameinfo gamesetup; 
	temp = 1; 

	do 
	{
		printf("Set the path length (a multiple of 5 between %d-%d): ", minlength, maxlength);
		scanf(" %d", &gamesetup.pathlength); 
		if ((gamesetup.pathlength >= minlength) && (gamesetup.pathlength <= maxlength) && (gamesetup.pathlength % ex == 0)) 
		{
			temp = 0; 
		}

		else
		{
			printf("     Must be a multiple of 5 and between %d-%d!!!\n", minlength, maxlength); 
		}
	} while (temp); 
	temp = 1; 

	do 
	{
		printf("Set the limit for number of moves allowed: ");
		scanf(" %d", &gamesetup.movesallowed); 
		if ((gamesetup.movesallowed >= minmoves) && (gamesetup.movesallowed <= maxmoves)) 
		{
			temp = 0; 
		}

		else
		{
			printf("    Value must be between %d and %d\n", minmoves, maxmoves); 
		}
	} while (temp); 

	printf("\nBOMB Placement\n--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", ex, gamesetup.pathlength);
	for (i = 0; i < gamesetup.pathlength; i += ex) 
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + ex);
		for (j = j + i; j <= (ex + i); j++) 
		{
			scanf("%d", &gamesetup.bomb[j]);
		}
		j = 1;
	}

	printf("BOMB placement set");
	printf("\n\nTREASURE Placement\n------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", ex, gamesetup.pathlength);
	for (i = 0; i < gamesetup.pathlength; i += ex) 
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + ex);
		for (j = j + i; j <= (ex + i); j++) 
		{
			scanf("%d", &gamesetup.treasure[j]); 
		}
		j = 1; 
	}

	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\nTREASURE HUNT Configuration Settings\n------------------------------------\n");
	printf("Player:\n   Symbol     : %c\n   Lives      : %d\n   Treasure   : [ready for gameplay]\n   History    : [ready for gameplay]\n\n", playersetup.player, playersetup.totallives);
	printf("Game:\n   Path Length: %d\n   Bombs      : ", gamesetup.pathlength);

	for (i = 1; i <= gamesetup.pathlength; i++) 
	{
		printf("%d", gamesetup.bomb[i]);
	}

	printf("\n   Treasure   : ");
	for (i = 1; i <= gamesetup.pathlength; i++) 
	{
		printf("%d", gamesetup.treasure[i]);
	}

	printf("\n\n====================================\n~ Get ready to play TREASURE HUNT! ~\n====================================\n");
	playersetup.treasobt = 0;
	for (i = 1; i <= gamesetup.pathlength; i++) 
	{
		playersetup.trail[i] = '-';
	}

	do
	{
		while (m == 1)
		{
			do
			{
				printf("  ");
			} while (m == 0);
			for (i = 1; i <= j; i++) 
			{
				if (j == i)
				{
					printf("%c", playersetup.player);

				}
				else
				{
					printf(" ");
				}
			}
			m = 0;
		}
		printf("\n  ");

		for (i = 1; i <= gamesetup.pathlength; i++) 
		{
			printf("%c", playersetup.trail[i]);
		}
		printf("\n  ");

		for (i = 1; i <= gamesetup.pathlength; i++) 
		{
			if (i % 10 == 0) 
			{
				printf("%d", i / 10);
			}
			else
			{
				printf("|"); 
			}
		}
		printf("\n  ");

		for (i = 1; i <= gamesetup.pathlength; i++) 
		{
			if (i > 9) 
			{
				temporaryst = i / 10;
				printf("%d", i - (temporaryst * 10));
			}
			else
			{
				printf("%d", i);
			}
		}
		temporaryst = 1;

		printf("\n+---------------------------------------------------+\n  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n+---------------------------------------------------+\n", playersetup.totallives, playersetup.treasobt, gamesetup.movesallowed); //This represents the total lives, treasures and moves remaining.
		temp = 1; \
		if ((gamesetup.movesallowed != 0) && (playersetup.totallives != 0)) 
		{
			do
			{
				printf("Next Move [1-%d]: ", gamesetup.pathlength);
				scanf("%d", &j); 
				m = 1;
				if (j > gamesetup.pathlength || j < 1)
				{
					printf("  Out of Range!!!\n");
				}
				else
				{
					temp = 0; 
				}
			} while (temp);

			if (playersetup.trail[j] != '-') 
			{
				printf("\n===============> Dope! You've been here before!\n\n");
			}

			else if (gamesetup.bomb[j] == 1 && gamesetup.treasure[j] == 1) 
			{
				printf("\n===============> [&] !!! BOOOOOM !!! [&]\n===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				playersetup.trail[j] = '&'; 
				gamesetup.movesallowed--;
				playersetup.totallives--;
				playersetup.treasobt++;
			}

			else if (gamesetup.bomb[j] == 1)
			{
				printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
				playersetup.trail[j] = '!'; 
				gamesetup.movesallowed--;
				playersetup.totallives--;
			}

			else if (gamesetup.treasure[j] == 1) 
			{
				printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
				playersetup.trail[j] = '$'; 
				gamesetup.movesallowed--;
				playersetup.treasobt++;
			}

			else
			{
				printf("\n===============> [.] ...Nothing found here... [.]\n\n");
				playersetup.trail[j] = '.'; 
				gamesetup.movesallowed--;
			}

			if (playersetup.totallives == 0) 
			{
				printf("No more LIVES remaining!\n\n");
			}

			else if (gamesetup.movesallowed == 0)
			{
				printf("No more MOVES remaining!\n\n"); 
			}

		}
		else
		{
			printf("\n##################\n#   Game over!   #\n##################");
			temporaryst = 0;
		}

	} while (temporaryst);
	printf("\n\nYou should play again and try to beat your score!\n");
	return 0;
}