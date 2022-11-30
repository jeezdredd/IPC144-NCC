#include <stdio.h>

int main (void) {
    int sum = 20;
    
    int fifty = sum / 50;
    sum %= 50;

    int twenty = sum / 20;
    sum %= 20;

    int ten = sum / 10;
    sum %= 10;

    int five = sum / 5;
    sum %= 5;

    printf("Fifty: %d\n", fifty);
    printf("Twenty: %d\n", twenty);
    printf("Ten: %d\n", ten);
    printf("Five: %d\n", five);

}