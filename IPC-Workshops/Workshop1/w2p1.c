#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    double ssize = 0.0;
    double msize = 0.0;
    double lsize = 0.0;
    const double tax = 0.13;
    int totalsh = 0;

    printf("Set the shirt price\n");    
    printf("===================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &ssize);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &msize);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &lsize);

    printf("\nShirt Store price list\n");
    printf("======================\n");
    printf("SMALL : $%.2lf\n", ssize);
    printf("MEDIUM : $%.2lf\n", msize);
    printf("LARGE : $%.2lf\n", lsize);

    printf("\nPatty's shirt size is 'S'\n");
    printf("Number of shirts Patty bought:");
    scanf("%d", &totalsh);

    double sTotal = ((int)(totalsh * ssize * 100 + 0.5)) / 100;
    double taxes = ((int)(tax * sTotal * 100 + 0.5)) / 100;
    double Total = ((int)((sTotal + taxes) * 100 + 0.5)) / 100;

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", totalsh);
    printf("Sub-total: $%8.4f\n", sTotal);
    printf("Taxes    : $%8.4f\n", taxes);
    printf("Total    : $%8.4f\n", Total);

    return 0;
} 