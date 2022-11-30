/*
*****************************************************************************
						  Workshop - #4 (P2)
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
#include <stdio.h>

int main (void) {

    //temp integers with grocery list
    int applesamount = 0;
    int orangesamount;
    int pearsamount;
    int tomatoesamount;
    int cabbagesamount;

    //main integers to pick choose from the grocery list
    int appleschoose;
    int orangeschoose;
    int pearschoose;
    int tomatoeschoose;
    int cabbageschoose;
    
    //store data
    int storedata = 0;
    int datachoose = 0;

    do {
        printf("Grocery Shopping\n================\n");
		do {
			printf("How many APPLES do you need? : ");
			scanf("%d", &applesamount);
			if (applesamount < 0)
			{
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (applesamount < 0);

		do {
			printf("\nHow many ORANGES do you need? : ");
			scanf("%d", &orangesamount);
			if (orangesamount < 0)
			{
				printf("ERROR: Value must be 0 or more.");
			}
		} while (orangesamount < 0);

		do {
			printf("\nHow many PEARS do you need? : ");
			scanf("%d", &pearsamount);
			if (pearsamount < 0)
			{
				printf("ERROR: Value must be 0 or more.");
			}
		} while (pearsamount < 0);

		do {
			printf("\nHow many TOMATOES do you need? : ");
			scanf("%d", &tomatoesamount);
			if (tomatoesamount < 0)
			{
				printf("ERROR: Value must be 0 or more.");
			}
		} while (tomatoesamount < 0);

		do {
			printf("\nHow many CABBAGES do you need? : ");
			scanf("%d", &cabbagesamount);
			if (cabbagesamount < 0)
			{
				printf("ERROR: Value must be 0 or more.");
			}
		} while (cabbagesamount < 0);

        //2nd part of the code 

		printf("\n--------------------------\nTime to pick the products!\n--------------------------\n\n");
		if (applesamount > 0)
		{
			do
			{
				printf("Pick some APPLES... how many did you pick? : ");
				scanf("%d", &appleschoose);
				if (appleschoose > applesamount)
				{
					printf("You picked too many... only %d more APPLE(S) are needed.\n", applesamount);
				}
				else if (appleschoose < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (appleschoose < applesamount)
				{
					printf("Looks like we still need some APPLES...\n");
					storedata = applesamount - appleschoose;
					applesamount = storedata;
					appleschoose = 0;
				}
				else if ((appleschoose = applesamount))
				{
					printf("Great, that's the apples done!\n\n");
				}
			} while (applesamount != appleschoose);
		}

		if (orangesamount > 0)
		{
			do
			{
				printf("Pick some ORANGES... how many did you pick? : ");
				scanf("%d", &orangeschoose);
				if (orangeschoose > orangesamount)
				{
					printf("You picked too many... only %d more ORANGE(S) are needed.\n", orangesamount);
				}
				else if (orangeschoose < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (orangeschoose < orangesamount)
				{
					printf("Looks like we still need some ORANGES...\n");
					storedata = orangesamount - orangeschoose;
					orangesamount = storedata;
					orangeschoose = 0;
				}
				else if ((orangeschoose = orangesamount))
				{
					printf("Great, that's the oranges done!\n\n");
				}
			} while (orangesamount != orangeschoose);
		}

		if (pearsamount > 0)
		{
			do
			{
				printf("Pick some PEARS... how many did you pick? : ");
				scanf("%d", &pearschoose);
				if (pearschoose > pearsamount)
				{
					printf("You picked too many... only %d more PEAR(S) are needed.\n", pearsamount);
				}
				else if (pearschoose < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (pearschoose < pearsamount)
				{
					printf("Looks like we still need some PEARS...\n");
					storedata = pearsamount - pearschoose;
					pearsamount = storedata;
					pearschoose = 0;
				}
				else if ((pearschoose = pearsamount))
				{
					printf("Great, that's the pears done!\n\n");
				}
			} while (pearsamount != pearschoose);
		}

		if (tomatoesamount > 0)
		{
			do
			{
				printf("Pick some TOMATOES... how many did you pick? : ");
				scanf("%d", &tomatoeschoose);
				if (tomatoeschoose > tomatoesamount)
				{
					printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoesamount);
				}
				else if (tomatoeschoose < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (tomatoeschoose < tomatoesamount)
				{
					printf("Looks like we still need some TOMATOES...\n");
					storedata = tomatoesamount - tomatoeschoose;
					tomatoesamount = storedata;
					tomatoeschoose = 0;
				}
				else if ((tomatoeschoose = tomatoesamount))
				{
					printf("Great, that's the tomatoes done!\n\n");
				}
			} while (tomatoesamount != tomatoeschoose);
		}

		if (cabbagesamount > 0)
		{
			do
			{
				printf("Pick some CABBAGES... how many did you pick? : ");
				scanf("%d", &cabbageschoose);
				if (cabbageschoose > cabbagesamount)
				{
					printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbagesamount);
				}
				else if (cabbageschoose < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (cabbageschoose < cabbagesamount)
				{
					printf("Looks like we still need some CABBAGES...\n");
					storedata = cabbagesamount - cabbageschoose;
					cabbagesamount = storedata;
					cabbageschoose = 0;
				}
				else if ((cabbageschoose = cabbagesamount))
				{
					printf("Great, that's the cabbages done!\n\n");
				}
			} while (cabbagesamount != cabbageschoose);
		}

        //repeating the process
		printf("All the items are picked!\n\nDo another shopping? (0=NO): ");
		scanf("%d", &datachoose);
		printf("\n");

	} while ((datachoose != 0));

	printf("Your tasks are done for today - enjoy your free time!\n\n");
    
	return 0;
}