/*
*****************************************************************************
                          Workshop - #3 (P2)
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

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    double GRAMS_IN_LBS = 453.5924;
    int coffeetype1;
    char coffeegrind1;
    int coffeeweight1;
    char coffeecream1;
    double coffeetemperature1;
    double coffeetemperaturef1;

    int coffeetype2;
    char coffeegrind2;
    int coffeeweight2;
    char coffeecream2;
    double coffeetemperature2;
    double coffeetemperaturef2;

    int coffeetype3;
    char coffeegrind3;
    int coffeeweight3;
    char coffeecream3;
    double coffeetemperature3;
    double coffeetemperaturef3;

    float bagweightconvert1;
    float bagweightconvert2;
    float bagweightconvert3;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product infromation being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight, [B]lend): ");
    scanf(" %d", &coffeetype1);
    printf("\nGrind size ([C]ourse,[F]ine):");
    scanf(" %c", &coffeegrind1);
    printf("Bag weight (g): ");
    scanf(" %d", &coffeeweight1);
    printf("\nBest served with cream ([Y]es, [N]o: ");
    scanf(" %c", &coffeecream1);
    printf("\nIdeal serving temperature (Celcius): ");
    scanf(" %lf", coffeetemperature1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight, [B]lend): ");
    scanf("%d", &coffeetype2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf("%c", &coffeegrind2);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeweight2);
    printf("Best served with cream ([Y]es, [N]o: ");
    scanf("%c", &coffeecream2);
    printf("Ideal serving temperature (Celcius): \n");
    scanf("%lf", coffeetemperature2);

    printf("COFFEE-3...\n");
    printf("Type ([L]ight, [B]lend): ");
    scanf("%d", &coffeetype1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf("%c", &coffeegrind3);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeweight3);
    printf("Best served with cream ([Y]es, [N]o: ");
    scanf("%c", &coffeecream3);
    printf("Ideal serving temperature (Celcius): \n");
    scanf("%lf", coffeetemperature3);

    printf("---+---------------+---------------+---------------+-------+--------------\n");
	printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving    \n");
	printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature  \n");
	printf("   +---------------+---------------+---------------+ With  +--------------\n");
	printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
	printf("---+---------------+---------------+---------------+-------+--------------\n");
	printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
    coffeetype1 == 'l' || coffeetype1 == 'L', coffeetype1 == 'b' || coffeetype1 == 'B',
		coffeegrind1 == 'c' || coffeegrind1 == 'C', coffeegrind1 == 'F' || coffeegrind1 == 'f',
		coffeeweight1, bagweightconvert1,
		coffeecream1 == 'Y'|| coffeecream1 == 'y'||coffeecream1 == 'N' || coffeecream1 == 'n',
		coffeetemperature1, coffeetemperaturef1);
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
    coffeetype2 == 'l' || coffeetype2 == 'L', coffeetype2 == 'b' || coffeetype2 == 'B',
		coffeegrind2 == 'c' || coffeegrind2 == 'C', coffeegrind2 == 'F' || coffeegrind2 == 'f',
		coffeeweight2, bagweightconvert2,
		coffeecream2 == 'Y'|| coffeecream2 == 'y'|| coffeecream2 == 'N' || coffeecream2 == 'n',
		coffeetemperature2, coffeetemperaturef2);
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n\n",
    coffeetype3 == 'l' || coffeetype3 == 'L', coffeetype3 == 'b' || coffeetype3 == 'B',
		coffeegrind3 == 'c' || coffeegrind3 == 'C', coffeegrind3 == 'F' || coffeegrind3 == 'f',
		coffeeweight3, bagweightconvert3,
		coffeecream3 == 'Y'|| coffeecream3 == 'y'||coffeecream3 == 'N' || coffeecream3 == 'n',
		coffeetemperature3, coffeetemperaturef3);
   
	// Note:
	// You can convert Celsius to Fahrenheit given the following formula:
	// fahrenheit = (celsius * 1.8) + 32.0);
    
    bagweightconvert1 = coffeeweight1 / GRAMS_IN_LBS;
    bagweightconvert2 = coffeeweight2 / GRAMS_IN_LBS;
    bagweightconvert3 = coffeeweight3 / GRAMS_IN_LBS;


    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
As described in step-10
=======================
printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
*/