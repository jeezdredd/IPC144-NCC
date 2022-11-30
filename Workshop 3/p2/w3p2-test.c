#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{

    // You will need this when converting from grams to pounds (lbs)
	const double GRAMS_IN_LBS = 453.5924;

	char coffeetype1;
	char coffeegrind1;
	int weightcoffee1;
	char creamcoffee1;
	double temperaturecoffee1;

	char coffeetype2;
	char grindcoffee2;
	int weightcoffee2;
	char creamcoffee2;
	double temperaturecoffee2;

	char coffeetype3;
	char grindcoffee3;
	int weightcoffee3;
	char creamcoffee3;
	double temperaturecoffee3;

	double temperaturefcoffee3;
    double temperaturefcoffee2;
    double temperaturefcoffee1;

    	double convertcoffee2;
        	double convertcoffee3;
            	double convertcoffee1;

    char coffeechoose1;
    char coffeecreamchoose1;
    int dailyservings1;
    char makerorres1;


	printf("Take a Break - Coffee Shop\n");
	printf("==========================\n\n");
	printf("Enter the coffee product information being sold today...\n\n");
    
    printf("COFFEE-1...\n");
	printf("Type ([L]ight,[B]lend): ");
	scanf(" %c", &coffeetype1);
	printf("Grind size ([C]ourse,[F]ine): ");
	scanf(" %c", &coffeegrind1);
	printf("Bag weight (g): ");
	scanf("%d", &weightcoffee1);
	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &creamcoffee1);
	printf("Ideal serving temperature (Celcius): ");
	scanf("%lf", &temperaturecoffee1);

	printf("\n\nCOFFEE-2...\n");
	printf("Type ([L]ight, [B]lend) : ");
	scanf(" %c", &coffeetype2);
	printf("Grind size ([C]ourse, [F]ine): ");
	scanf(" %c", &grindcoffee2);
	printf("Bag weight (g): ");
	scanf(" %d", &weightcoffee2);
	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &creamcoffee2);
	printf("Ideal serving temperature (Celcius): ");
	scanf(" %lf", &temperaturecoffee2);

	printf("\n\nCOFFEE-3...\n");
	printf("Type ([L]ight, [B]lend) : ");
	scanf(" %c", &coffeetype3);
	printf("Grind size ([C]ourse, [F]ine): ");
	scanf(" %c", &grindcoffee3);
	printf("Bag weight (g): ");
	scanf(" %d", &weightcoffee3);
	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &creamcoffee3);
	printf("Ideal serving temperature (Celcius): ");
	scanf(" %lf", &temperaturecoffee3);

	convertcoffee1 = weightcoffee1 / GRAMS_IN_LBS;
	convertcoffee2 = weightcoffee2 / GRAMS_IN_LBS;
	convertcoffee3 = weightcoffee3 / GRAMS_IN_LBS;

	// Table
	printf("\n\n---+---------------+---------------+---------------+-------+--------------\n");
	printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving    \n");
	printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature  \n");
	printf("   +---------------+---------------+---------------+ With  +--------------\n");
	printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
	printf("---+---------------+---------------+---------------+-------+--------------\n");
	printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
		coffeetype1 == 'l' || coffeetype1 == 'L', coffeetype1 == 'b' || coffeetype1 == 'B',
		coffeegrind1 == 'c' || coffeegrind1 == 'C', coffeegrind1 == 'F' || coffeegrind1 == 'f',
		weightcoffee1, convertcoffee1,
		creamcoffee1 == 'Y'|| creamcoffee1 == 'y'|| creamcoffee1 == 'N' || creamcoffee1 == 'n',
		temperaturecoffee1, temperaturefcoffee1);
	printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
		coffeetype2 == 'l' || coffeetype2 == 'L', coffeetype2 == 'b' || coffeetype2 == 'B',
		grindcoffee2 == 'c' || grindcoffee2 == 'C', grindcoffee2 == 'F' || grindcoffee2 == 'f',
		weightcoffee2, convertcoffee2,
		creamcoffee2 == 'Y' || creamcoffee2 == 'y'|| creamcoffee2 == 'N' || creamcoffee2 == 'n',
		temperaturecoffee2, temperaturefcoffee2);
	printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
		coffeetype3 == 'l' || coffeetype3 == 'L', coffeetype3 == 'b' || coffeetype3 == 'B',
		grindcoffee3 == 'c' || grindcoffee3 == 'C', grindcoffee3 == 'F' || grindcoffee3 == 'f',
		weightcoffee3, convertcoffee3,
		creamcoffee3 == 'Y' || creamcoffee3 == 'y'|| creamcoffee3 == 'N' || creamcoffee3 == 'n',
		temperaturecoffee3, temperaturefcoffee3);

    char coffeestrengh;
    char coffeecreamchoose;
    int dailyservings;
    char makerorres;

    printf("Enter how you like your coffee and the coffee maker equipment you see...\n");
    printf("Coffee strength ([M]ild,[R]ich: ");
    scanf(" %c", &coffeestrengh);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeecreamchoose);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyservings);
    printf("Maker ([R]esidental,[C]ommercial): ");
    scanf(" %c", &makerorres);
    
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       ");
    if (coffeestrengh == 'm' || coffeestrengh == 'M')
        printf("%d", coffeetype1 == 'l' || coffeetype1 == 'L');
    else
        printf("%d", coffeetype1 == 'b' || coffeetype1 == 'B');
    printf("         |         ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", coffeegrind1 == 'c' || coffeegrind1 == 'C');
    else
        printf("%d", coffeegrind1 == 'f' || coffeegrind1 == 'F');
    printf("          |      ");
    if (dailyservings >= 1 && dailyservings <= 4)
        printf("%d", weightcoffee1 <= 250 && weightcoffee1 >= 0);
    else if (dailyservings >= 5 && dailyservings <= 9)
        printf("%d", weightcoffee1 == 500);
    else
        printf("%d", weightcoffee1 == 1000);
    printf("      |   ");
    if (coffeecreamchoose == 'y' || coffeecreamchoose == 'Y')
        printf("%d", coffeecreamchoose == 'y' || coffeecreamchoose == 'Y');
    else
        printf("%d", coffeecreamchoose == 'n' || coffeecreamchoose == 'N');
    printf("   |      ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", temperaturecoffee1 <= 69.9 && temperaturecoffee1 >= 60.0);
    else
        printf("%d", temperaturecoffee1 >= 70.0);
    printf("\n 2|       ");
    if (coffeestrengh == 'm' || coffeestrengh == 'M')
        printf("%d", coffeetype1 == 'l' || coffeetype1 == 'L');
    else
        printf("%d", coffeetype2 == 'b' || coffeetype2 == 'B');
    printf("         |         ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", grindcoffee2 == 'c' || grindcoffee2 == 'C');
    else
        printf("%d", grindcoffee2 == 'f' || grindcoffee2 == 'F');
    printf("          |      ");
    if (dailyservings >= 1 && dailyservings <= 4)
        printf("%d", weightcoffee2 <= 250 && weightcoffee2 >= 0);
    else if (dailyservings >= 5 && dailyservings <= 9)
        printf("%d", weightcoffee2 == 500);
    else
        printf("%d", weightcoffee2 == 1000);
    printf("      |   ");
    if (coffeecreamchoose == 'y' || coffeecreamchoose == 'Y')
        printf("%d", creamcoffee2 == 'y' || creamcoffee2 == 'Y');
    else
        printf("%d", creamcoffee2 == 'n' || creamcoffee2 == 'N');
    printf("   |      ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", temperaturecoffee2 <= 69.9 && temperaturecoffee2 >= 60.0);
    else
        printf("%d", temperaturecoffee2 >= 70.0);
    printf("\n 3|       ");
    if (coffeestrengh == 'm' || coffeestrengh == 'M')
        printf("%d", coffeetype3 == 'l' || coffeetype3 == 'L');
    else
        printf("%d", coffeetype3 == 'b' || coffeetype3 == 'B');
    printf("         |         ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", grindcoffee3 == 'c' || grindcoffee3 == 'C');
    else
        printf("%d", grindcoffee3 == 'f' || grindcoffee3 == 'F');
    printf("          |      ");
    if (dailyservings >= 1 && dailyservings <= 4)
        printf("%d", weightcoffee3 <= 250 && weightcoffee3 >= 0);
    else if (dailyservings >= 5 && dailyservings <= 9)
        printf("%d", weightcoffee3 == 500);
    else
        printf("%d", weightcoffee3 == 1000);
    printf("      |   ");
    if (coffeecreamchoose == 'y' || coffeecreamchoose == 'Y')
        printf("%d", creamcoffee3 == 'y' || creamcoffee3 == 'Y');
    else
        printf("%d", creamcoffee3 == 'n' || creamcoffee3 == 'N');
    printf("   |      ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", temperaturecoffee3 <= 69.9 && temperaturecoffee3 >= 60.0);
    else
        printf("%d", temperaturecoffee3 >= 70.0);
    printf("\n\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeestrengh);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeecreamchoose);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyservings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &makerorres);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       ");
    if (coffeestrengh == 'm' || coffeestrengh == 'M')
        printf("%d", coffeetype1 == 'l' || coffeetype1 == 'L');
    else
        printf("%d", coffeetype1 == 'b' || coffeetype1 == 'B');
    printf("         |         ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", coffeegrind1 == 'c' || coffeegrind1 == 'C');
    else
        printf("%d", coffeegrind1 == 'f' || coffeegrind1 == 'F');
    printf("          |      ");
    if (dailyservings >= 1 && dailyservings <= 4)
        printf("%d", weightcoffee1 <= 250 && weightcoffee1 >= 0);
    else if (dailyservings >= 5 && dailyservings <= 9)
        printf("%d", weightcoffee1 == 500);
    else
        printf("%d", weightcoffee1 == 1000);
    printf("      |   ");
    if (coffeecreamchoose == 'y' || coffeecreamchoose == 'Y')
        printf("%d", coffeecreamchoose == 'y' || coffeecreamchoose == 'Y');
    else
        printf("%d", coffeecreamchoose == 'n' || coffeecreamchoose == 'N');
    printf("   |      ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", temperaturecoffee1 <= 69.9 && temperaturecoffee1 >= 60.0);
    else
        printf("%d", temperaturecoffee1 >= 70.0);
    printf("\n 2|       ");
    if (coffeestrengh == 'm' || coffeestrengh == 'M')
        printf("%d", coffeetype1 == 'l' || coffeetype1 == 'L');
    else
        printf("%d", coffeetype2 == 'b' || coffeetype2 == 'B');
    printf("         |         ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", grindcoffee2 == 'c' || grindcoffee2 == 'C');
    else
        printf("%d", grindcoffee2 == 'f' || grindcoffee2 == 'F');
    printf("          |      ");
    if (dailyservings >= 1 && dailyservings <= 4)
        printf("%d", weightcoffee2 <= 250 && weightcoffee2 >= 0);
    else if (dailyservings >= 5 && dailyservings <= 9)
        printf("%d", weightcoffee2 == 500);
    else
        printf("%d", weightcoffee2 == 1000);
    printf("      |   ");
    if (coffeecreamchoose == 'y' || coffeecreamchoose == 'Y')
        printf("%d", creamcoffee2 == 'y' || creamcoffee2 == 'Y');
    else
        printf("%d", creamcoffee2 == 'n' || creamcoffee2 == 'N');
    printf("   |      ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", temperaturecoffee2 <= 69.9 && temperaturecoffee2 >= 60.0);
    else
        printf("%d", temperaturecoffee2 >= 70.0);
    printf("\n 3|       ");
    if (coffeestrengh == 'm' || coffeestrengh == 'M')
        printf("%d", coffeetype3 == 'l' || coffeetype3 == 'L');
    else
        printf("%d", coffeetype3 == 'b' || coffeetype3 == 'B');
    printf("         |         ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", grindcoffee3 == 'c' || grindcoffee3 == 'C');
    else
        printf("%d", grindcoffee3 == 'f' || grindcoffee3 == 'F');
    printf("          |      ");
    if (dailyservings >= 1 && dailyservings <= 4)
        printf("%d", weightcoffee3 <= 250 && weightcoffee3 >= 0);
    else if (dailyservings >= 5 && dailyservings <= 9)
        printf("%d", weightcoffee3 == 500);
    else
        printf("%d", weightcoffee3 == 1000);
    printf("      |   ");
    if (coffeecreamchoose == 'y' || coffeecreamchoose == 'Y')
        printf("%d", creamcoffee3 == 'y' || creamcoffee3 == 'Y');
    else
        printf("%d", creamcoffee3 == 'n' || creamcoffee3 == 'N');
    printf("   |      ");
    if (makerorres == 'r' || makerorres == 'R')
        printf("%d", temperaturecoffee3 <= 69.9 && temperaturecoffee3 >= 60.0);
    else
        printf("%d", temperaturecoffee3 >= 70.0);
   printf("\n\nHope you found a product that suits your likes!\n");

return 0;
}