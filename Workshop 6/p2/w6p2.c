/*
*****************************************************************************
                          Workshop - #6 (P2)
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

#define MAXIMUMNUMBER 10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    const double minimumincome = 500.00;  //minIncome 
    const double maximumincome = 400000.00; //maxIncome
    const double minimumcost = 100.00; //minCost
    double inc; //income
    double totalprice = 0; //totalCost

    int itemnumber; //itemNim
    int ex; //i
    int months; //totalMonth
    int reassign = 1; //keepLooking
    int choose;  //option
    int itemschoose;   //byPriority

    double itemprice[MAXIMUMNUMBER];       //itemCost
    int itemchooselist[MAXIMUMNUMBER];      //itemPriority
    char paying[MAXIMUMNUMBER];   //financeOptions
    double itemsamount[3] = {0}; //priorityCost
                     
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &inc);

        if (inc < minimumincome)
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");

        if (inc > maximumincome)
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");

    } while (inc < minimumincome || inc > maximumincome);

    printf("\n");

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &itemnumber);

        if (itemnumber < 1 || itemnumber > MAXIMUMNUMBER)

            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");

    } while (itemnumber < 1 || itemnumber > MAXIMUMNUMBER);

    printf("\n");

    for (ex = 0; ex < itemnumber; ex++)
    {
        printf("Item-%d Details:\n", ex + 1);

        do {
            printf("   Item cost: $");
            scanf("%lf", &itemprice[ex]);

            if (itemprice[ex] < minimumcost)
                printf("      ERROR: Cost must be at least $100.00\n");
                
        } while (itemprice[ex] < minimumcost);
        totalprice += itemprice[ex];

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemchooselist[ex]);

            if (itemchooselist[ex] < 1 || itemchooselist[ex] > 3)
                printf("      ERROR: Value must be between 1 and 3\n");

        } while (itemchooselist[ex] < 1 || itemchooselist[ex] > 3);

        switch (itemchooselist[ex])
        {

        case 1 :
            itemsamount[0] += itemprice[ex];
            break;

        case 2 :
            itemsamount[1] += itemprice[ex];
            break;

        case 3:
            itemsamount[2] += itemprice[ex];
            break;

        }

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &paying[ex]);

            if (paying[ex] != 'y' && paying[ex] != 'n')
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");

        } while (paying[ex] != 'y' && paying[ex] != 'n');

        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (ex = 0; ex < itemnumber; ex++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", 
            ex + 1, itemchooselist[ex], paying[ex], itemprice[ex]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalprice);

    do {

        do {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &choose);
            printf("\n");

            if (choose != 0 && choose != 1 && choose != 2)
            {
                printf("ERROR: Invalid menu selection.\n\n");
            }
            
        } while (choose != 0 && choose != 1 && choose != 2);

        if (choose == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalprice);
            //round up the total month
            months = (totalprice + (inc - 1)) / inc; 
            printf("Forecast: %d years, %d months\n", months / 12, months % 12);
            for (ex = 0; ex < itemnumber && reassign; ex++)
            {
                if (paying[ex] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    reassign = 0;
                }
            }
            printf("====================================================\n\n");
        }

        else if (choose == 2)
        {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &itemschoose);

            printf("\n====================================================\n");

            printf("Filter:   by priority (%d)\n", itemschoose);
            printf("Amount:   $%1.2lf\n", itemsamount[itemschoose - 1]);

       
            months = (itemsamount[itemschoose - 1] + (inc - 1)) / inc; 
            printf("Forecast: %d years, %d months\n", months / 12, months % 12);
            reassign = 1;

            for (ex = 0; ex < itemnumber && reassign; ex++)

            {
                if (itemchooselist[ex] == itemschoose && paying[ex] == 'y')

                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    reassign = 0;
                }

            }

            printf("====================================================\n\n");
        }

    } while (choose);
    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}