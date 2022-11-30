#define _CRT_NO_WARNINGS
#include <stdio.h>

int main (void) {
    int times = 0;
    char loopType = 'x';
    int badData = 1;
    
    while (badData) {
        printf("Enter the loop type and number of times (3-20): ");
        scanf("%c%d%*c", &loopType, &times);
        badData = 0;
        badData = !(loopType == 'W' || loopType == 'F' || loopType == 'Q' || loopType == 'D');
        if (badData) printf("invalid loop type"); 
        

        ) 
    }
}