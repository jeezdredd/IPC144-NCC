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

#define MAX_PROD 3
#define GRAM_SERVING 64
#define LBS_KG 2.20462

struct CatFoodInfo {
	int sku;
	double prodPrice;
	int calories;
	double prodWeight;
};
struct ReportData {
	int sku;
	double prodPrice;
	int calories;
	double prodWeight;
	double prodWeightKg;
	int prodWeightG;
	double totalServing;
	double costPerServing;
	double costCalPerServing;
};

int getIntPositive(int * xPtr);

double getDoublePositive(double* yPtr);

void openingMessage(const int noProd, const int gramServing);

struct CatFoodInfo getCatFoodInfo(const int prod);

void displayCatFoodHeader(void);

void displayCatFoodData(const int id, const double price, const double weight, const int cal);

double convertLbsKg(const double * xPtr, double * yPtr);

int convertLbsG(const double * aPtr, int * bPtr);

void convertLbs(const double * cPtr, double * dPtr, int* ePtr);

double calculateServings(const int servingSize, const int totalGram, double * noOfServing);

double calculateCostPerServing(const double * prodPrice, const double * noOfServing, double * costPerServing);

double calculateCostPerCal(const double * prodPrice, const double * noOfCalories, double* costPerCalories);

struct ReportData calculateReportData(const struct CatFoodInfo product2);

void displayReportHeader(void);

void displayReportData(const struct ReportData re, const int cheapest);

void displayFinalAnalysis(const struct CatFoodInfo product2);

void start();