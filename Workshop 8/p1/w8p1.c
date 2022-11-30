/*
*****************************************************************************
                          Workshop - #8 (P1)
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
#include "w8p1.h"

int getIntPositive(int* number)
{
	int temp;

	do {
		scanf("%d", &temp);

		if (temp <= 0)
			printf("ERROR: Enter a positive value: ");	
	} while (temp <= 0);

	if (number != NULL)
		*number = temp;

	return temp;
}

double getDoublePositive(double* number)
{
	double temp;
	
	do {
		scanf("%lf", &temp);

		if (temp <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (temp <= 0);

	if (number != NULL)
		*number = temp;
	return temp;
}

void openingMessage(const int number)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", number);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_PER_SERVING);
	return;
}

struct CatFoodInfo getCatFoodInfo(const int n)
{
	struct CatFoodInfo food;

	printf("\nCat Food Product #%d\n", n+1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.main);
	printf("PRICE         : $");
	getDoublePositive(&food.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calorie);

	return food;
}

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int sku, double* price, int calories, double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
	return;
}

void start()
{
	struct CatFoodInfo food[MAX_NUM_PRODUCTS] = { {0} };

	int num_products = 3, i;
	openingMessage(num_products);

	for (i = 0; i < num_products; i++)
		food[i] = getCatFoodInfo(i);

	printf("\n");

	displayCatFoodHeader();

	for (i = 0; i < num_products; i++)
		displayCatFoodData(food[i].main, &food[i].price, food[i].calorie, &food[i].weight);

	return;
}