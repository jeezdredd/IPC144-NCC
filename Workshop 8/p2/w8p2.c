/*
*****************************************************************************
						  Workshop - #8 (P2)
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
#include "w8p2.h"

int getIntPositive(int* xPtr)
{
	int n;
	int exam = 0;

	do {
		scanf("%d", &n);

		if (n <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			exam = 1;
		}

		else
		{
			exam = 0;
			if (xPtr) *xPtr = n;
			xPtr = &n;
		}

	} while (exam != 0);

	return n;
}

double getDoublePositive(double* yPtr)
{
	double y;
	int exam = 0;
	do {
		scanf("%lf", &y);
		if (y <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			exam = 1;
		}
		else
		{
			exam = 0;
			if (yPtr) *yPtr = y;
			yPtr = &y;
		}
	} while (exam != 0);
	return y;
}

void openingMessage(const int noProd, const int gramServing)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", noProd);
	printf("NOTE: A 'serving' is %dg\n", gramServing);
}

struct CatFoodInfo getCatFoodInfo(const int prod)
{
	struct CatFoodInfo product;
	printf("SKU           : ");
	getIntPositive(&product.sku);
	printf("PRICE         : $");
	getDoublePositive(&product.prodPrice);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&product.prodWeight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&product.calories);
	return product;
}

void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int id, const double price, const double weight, const int cal) {
	printf("%07d %10.2lf %10.1lf %8d\n", id, price, weight, cal);
}

double convertLbsKg(const double* xPtr, double* yPtr)
{
	double x, y;

	x = *xPtr;
	y = x / LBS_KG;
	xPtr = &x;

	if (yPtr) *yPtr = y;
	yPtr = &y;

	return y;
}

int convertLbsG(const double* aPtr, int* bPtr)
{
	double x;
	int y;

	x = *aPtr;
	y = (int)(x / LBS_KG * 1000);
	aPtr = &x;

	if (bPtr) *bPtr = y;
	bPtr = &y;

	return y;
}

void convertLbs(const double* cPtr, double* dPtr, int* ePtr)
{
	double y;
	int z;

	y = convertLbsKg(cPtr, dPtr);
	if (dPtr) *dPtr = y;
	dPtr = &y;

	z = convertLbsG(cPtr, ePtr);
	if (ePtr) *ePtr = z;
	ePtr = &z;
}

double calculateServings(const int servingSize, const int totalGram, double* noOfServing)
{
	double z;

	z = (float)totalGram / (float)servingSize;
	noOfServing = &z;
	if (noOfServing) *noOfServing = z;

	return z;
}

double calculateCostPerServing(const double* prodPrice, const double* noOfServing, double* costPerServing)
{
	double x,y,z;

	x = *prodPrice;
	y = *noOfServing;
	z = x/y;
	costPerServing = &z;

	if (costPerServing) *costPerServing = z;

	return z;
}

double calculateCostPerCal(const double* prodPrice, const double* noOfCalories, double* costPerCalories)
{
	double x, y, z;

	x = *prodPrice;
	y = *noOfCalories;
	z = x/y;
	costPerCalories = &z;

	if (costPerCalories) *costPerCalories = z;

	return z;
}

struct ReportData calculateReportData(const struct CatFoodInfo product2)
{
	double pWKg = 0, tS = 0, cPS = 0, cCPS = 0, calPS;
	int pWG = 0;

	struct ReportData re;
	re.sku = product2.sku;
	re.prodPrice = product2.prodPrice;
	re.calories = product2.calories;
	re.prodWeight = product2.prodWeight;
	re.prodWeightKg = convertLbsKg(&product2.prodWeight,&pWKg);
	re.prodWeightG = convertLbsG(&product2.prodWeight,&pWG); 
	re.totalServing = calculateServings(GRAM_SERVING, re.prodWeightG,&tS);
	re.costPerServing = calculateCostPerServing(&re.prodPrice,&re.totalServing,&cPS);
	calPS = (re.totalServing * re.calories);
	re.costCalPerServing = calculateCostPerCal(&re.prodPrice,&calPS,&cCPS);

	return re;
}

void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAM_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const struct ReportData re, const int cheapest)
{
	struct ReportData re3;
	re3.sku = re.sku;
	re3.prodPrice = re.prodPrice;
	re3.calories = re.calories;
	re3.prodWeight = re.prodWeight;
	re3.prodWeightKg = re.prodWeightKg;
	re3.prodWeightG = re.prodWeightG;
	re3.totalServing = re.totalServing;
	re3.costPerServing = re.costPerServing;
	re3.costCalPerServing = re.costCalPerServing;

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", re3.sku, re3.prodPrice, re3.prodWeight, re3.prodWeightKg, re3.prodWeightG, re3.calories, re3.totalServing, re3.costPerServing, re3.costCalPerServing);

	if (cheapest == 1)
	{
		printf(" ***");
	}
	printf("\n");
}

void displayFinalAnalysis(const struct CatFoodInfo product2)
{
	struct CatFoodInfo product3;
	product3.sku = product2.sku;
	product3.prodPrice = product2.prodPrice;
	printf("\nFinal Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\nHappy shopping!\n",product3.sku,product3.prodPrice);
}

void start() {
	struct CatFoodInfo product2[MAX_PROD];
	struct ReportData re2[MAX_PROD];

	openingMessage(MAX_PROD, GRAM_SERVING);

	int j;
	int cheapest[MAX_PROD] = { 0 };
	int location = 0;

	for (j = 0; j < MAX_PROD; j++)
	{
		printf("\nCat Food Product #%d\n", (j + 1));
		printf("--------------------\n");
		product2[j] = getCatFoodInfo(1);	
	}
	displayCatFoodHeader();

	for (j = 0; j < MAX_PROD; j++)
	{
		displayCatFoodData(product2[j].sku, product2[j].prodPrice, product2[j].prodWeight, product2[j].calories);
	}

	for (j = 0; j < MAX_PROD; j++)
	{
		re2[j] = calculateReportData(product2[j]);
		int k;
		for (k = 1; k < MAX_PROD; k++)
		{
			if (re2[k].costCalPerServing < re2[location].costCalPerServing)
			{
				location = k;
				cheapest[k] = 1;
			}
            
			else {
				cheapest[k] = 0;
				cheapest[location] = 1;
			}
		}

	}
	displayReportHeader();	

	for (j = 0; j < MAX_PROD; j++)
	{
		displayReportData(re2[j],cheapest[j]);

	}
		displayFinalAnalysis(product2[location]);
	
}