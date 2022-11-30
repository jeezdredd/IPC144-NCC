/**
*****************************************************************************
                              Workshop - #3 (P1)
Full Name  : Sevastyan Che
Student ID#: 181071218
Email      : sche5@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
**/
#include <stdio.h>

int main (void)
{
    const double testValue  = 330.99;
    const int idproductone = 111;
    const int idproducttwo = 222;
    const int idproductthree = 111;
    const double priceproductone = 111.49;
    const double priceproducttwo = 222.99;
    const double priceproductthree = 334.49;
    const char taxedproductone = 'Y';
    const char taxedproducttwo = 'N';
    const char taxedproductthree = 'N';
    const double priceaverage = (double)((int)(((priceproductone + priceproducttwo + priceproductthree) / 3) * 100 + 0.5)) / 100;
    
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", idproductone);
    printf("  Taxed: %c\n", taxedproductone);
    printf("  Price: $%.4lf\n\n", priceproductone);
    printf("Product-2 (ID:%d\n", idproducttwo);
    printf("  Taxed: %c\n", taxedproducttwo);
    printf("  Price: $%.4lf\n\n", priceproducttwo);
    printf("Product-3 (ID:%d\n", idproductthree);
    printf("  Taxed: %c\n", taxedproductthree);
    printf("  Price: $%.4lf\n\n", priceproductthree);
    printf("The average of all prices is: $%.4lf\n\n", priceaverage);

    printf("About Relational and Logical Expressions!\n");
	printf("========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0\n");
	printf("3. TRUE : is represented by any integer value other than 0\n\n");
	printf("Some Data Analysis...\n");
	printf("=====================\n");
	printf("1. Is product 1 taxable? -> %d\n\n", taxedproductone == 'Y');
	printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n",(taxedproducttwo == 'n' || taxedproducttwo == 'N') && (taxedproductthree == 'n' || taxedproductthree == 'N'));
	printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, priceproductthree < testValue );
	printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", priceproductthree > (priceproductone + priceproducttwo));
	printf("5. Is the price of product 1 equal to or more than the price difference\n");
	printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", priceproductone >= priceproductthree - priceproducttwo, priceproductthree- priceproducttwo);
	printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", priceproducttwo >= priceaverage);
	printf("7. Based on product ID, product 1 is unique -> %d\n\n", idproductone!= idproducttwo && idproductone != idproductthree);
	printf("8. Based on product ID, product 2 is unique -> %d\n\n", idproducttwo != idproductone && idproducttwo != idproductthree);
	printf("9. Based on product ID, product 3 is unique -> %d\n\n", idproductthree != idproductone &&idproductthree != idproducttwo);

		return 0;
}
 