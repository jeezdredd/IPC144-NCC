/*
*****************************************************************************
                          Workshop - #6 (Part 1)
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
    const double minimumincome = 500.00;    
    const double maximumincome = 400000.00; 
    const double minimumcost = 100.00;      

    double inc; 
    double totalprice = 0; 
    double itemprice[MAXIMUMNUMBER]; 

    int numberofItem;
    int ex; 
    int priorityofItem[MAXIMUMNUMBER];  

    char paying[MAXIMUMNUMBER];  

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
        scanf("%d", &numberofItem);

        if (numberofItem < 1 || numberofItem > MAXIMUMNUMBER)
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");

    } while (numberofItem < 1 || numberofItem > MAXIMUMNUMBER);

    printf("\n");

    for (ex = 0; ex < numberofItem; ex++)
    {
        printf("Item-%d Details:\n", ex+1);
        do {
            printf("   Item cost: $");
            scanf("%lf", &itemprice[ex]);

            if (itemprice[ex] < minimumcost)
                printf("      ERROR: Cost must be at least $100.00\n");   

        } while (itemprice[ex] < minimumcost);

        totalprice += itemprice[ex];
        
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priorityofItem[ex]);
            if (priorityofItem[ex] < 1 || priorityofItem[ex] > 3)

                printf("      ERROR: Value must be between 1 and 3\n");

        } while (priorityofItem[ex] < 1 || priorityofItem[ex] > 3);
        
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

    for (ex = 0; ex < numberofItem; ex++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", ex+1, priorityofItem[ex], paying[ex], itemprice[ex]);
    } 

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalprice);
    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}