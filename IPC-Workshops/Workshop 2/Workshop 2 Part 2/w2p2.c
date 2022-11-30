#define _CRT_SECURE_NO_WARNINGS 
 
#include <stdio.h> 
 
int main(void) 
{ 
 
 double sdollars; 
 double mdollars; 
 double ldollars; 
 const char pattysize = 'S';
 const char sallysize = 'M';
 const char tommysize = 'L'; 
 const double tax = 0.13; 
 
 printf("Set Shirt Prices\n"); 
 printf("================\n"); 
 
 printf("Enter the price for a SMALL shirt: $"); 
 scanf("%lf", &sdollars); 
 printf("Enter the price for a MEDIUM shirt: $"); 
 scanf("%lf", &mdollars); 
 printf("Enter the price for a LARGE shirt: $"); 
 scanf("%lf", &ldollars); 
 
 printf("\nShirt Store Price List\n"); 
 printf("======================\n"); 
 
 printf("SMALL  : $%.2lf\n", sdollars); 
 printf("MEDIUM : $%.2lf\n", mdollars); 
 printf("LARGE  : $%.2lf\n", ldollars); 
 
 printf("\nPatty's shirt size is '%c'", pattysize); 
 int shirtspatty; 
 printf("\nNumber of shirts Patty is buying: "); 
 scanf("%d", &shirtspatty); 
 
 printf("\nTommy's shirt size is '%c'", tommysize); 
 int shirtstommy; 
 printf("\nNumber of shirts Tommy is buying: "); 
 scanf("%d", &shirtstommy); 
 
 printf("\nSally's shirt size is '%c'", sallysize); 
 int shirtssally; 
 printf("\nNumber of shirts Sally is buying: "); 
 scanf("%d", &shirtssally); 
 

 int spennies = sdollars * 100;                 
 int stotalpenniespatty = spennies * shirtspatty + 0.5;  
 float stotaldollarspatty = (double)stotalpenniespatty / 100;  
 int taxpenniespatty = stotalpenniespatty * tax + 0.5;           
 float taxdollarspatty = (double)taxpenniespatty / 100;           
 int tpenniespatty = taxpenniespatty + stotalpenniespatty + 0.5; 
 float tdollarspatty = (double)tpenniespatty / 100;           
 

 int lpennies = ldollars * 100;                    
 int stotalpenniestommy = lpennies * shirtstommy + 0.5;   
 float stotaldollarstommy = (double)stotalpenniestommy / 100;  
 int taxpenniestommy = stotalpenniestommy * tax + 0.5;           
 float taxdollarstommy = (double)taxpenniestommy / 100;           
 int tpenniestommy = taxpenniestommy + stotalpenniestommy + 0.5; 
 float tdollarstommy = (double)tpenniestommy / 100;           
 

 int mpennies = mdollars * 100;                    
 int stotalpenniessally = mpennies * shirtssally + 0.5;  
 float stotaldollarssally = (double)stotalpenniessally / 100;  
 int taxpenniessally = stotalpenniessally * tax + 0.5;           
 float taxdollarssally = (double)taxpenniessally / 100;          
 int tpenniessally = taxpenniessally + stotalpenniessally + 0.5; 
 float tdollarssally = (double)tpenniessally / 100;           
 
 
 printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n"); 
 printf("-------- ---- ----- --- --------- --------- ---------\n"); 
 
 printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf", pattysize, sdollars, shirtspatty, stotaldollarspatty, taxdollarspatty, tdollarspatty); 
 printf("\nSally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf", sallysize, mdollars, shirtssally, stotaldollarssally, taxdollarssally, tdollarssally); 
 printf("\nTommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf", tommysize, ldollars, shirtstommy, stotaldollarstommy, taxdollarstommy, tdollarstommy); 
 
 int stotalpennies = stotalpenniestommy + stotalpenniessally + stotalpenniespatty + 0.5; 
 float stotaldollars = (double)stotalpennies / 100; 
 
 int taxpennies = taxpenniespatty + taxpenniessally + taxpenniestommy + 0.5; 
 float taxdollars = (double)taxpennies / 100; 
 
 int tpennies = tpenniestommy + tpenniessally + tpenniespatty + 0.5; 
 float tdollars = (double)tpennies / 100; 
 
 printf("\n-------- ---- ----- --- --------- --------- ---------\n"); 
 printf("%33.4lf %9.4lf %9.4lf\n", stotaldollars, taxdollars, tdollars); 
 
 printf("\nDaily retail sales represented by coins"); 
 printf("\n=======================================\n"); 
 printf("\nSales EXCLUDING tax"); 
 printf("\nCoin     Qty   Balance"); 
 printf("\n-------- --- ---------\n"); 
 
 printf("%22.4lf\n", stotaldollars); 
 
 int toon = stotalpennies / 2 / 100;  
 int rpennies = stotalpennies % 200; 
 double rdollars = (double)rpennies / 100; 
 printf("Toonies  %3d %9.4lf\n", toon, rdollars); 
 
 int loon = rpennies / 100; 
 rpennies %= 100; 
 rdollars = (double)rpennies / 100; 
 printf("Loonies  %3d %9.4lf\n", loon, rdollars); 
 
 int qrtr = rpennies / 25; 
 rpennies %= 25; 
 rdollars = (double)rpennies / 100; 
 printf("Quarters %3d %9.4lf\n", qrtr, rdollars); 
 
 int dm = rpennies / 10; 
 rpennies %= 10; 
 rdollars = (double)rpennies / 100; 
 printf("Dimes    %3d %9.4lf\n", dm, rdollars); 
 
 int nckl = rpennies / 5; 
 rpennies %= 5; 
 rdollars = (double)rpennies / 100; 
 printf("Nickels  %3d %9.4lf\n", nckl, rdollars); 
 
 int pen = rpennies / 1; 
 rpennies %= 1; 
 rdollars = (double)rpennies / 100; 
 printf("Pennies  %3d %9.4lf\n\n", pen, rdollars); 
 
 int acostpennies = stotalpennies * 1000 / (shirtstommy + shirtspatty + shirtssally) + 5; 
 double acostdollars = (double)acostpennies / 100000; 
 printf("Average cost/shirt: $%.4lf\n", acostdollars); 
 
 printf("\nSales INCLUDING tax"); 
 printf("\nCoin     Qty   Balance"); 
 printf("\n-------- --- ---------\n"); 
 printf("%22.4lf\n", tdollars); 
 
 toon = tpennies / 2 / 100; 
 rpennies = tpennies % 200; 
 rdollars = (double)rpennies / 100; 
 printf("Toonies  %3d %9.4lf\n", toon, rdollars); 
 
 loon = rpennies / 100; 
 rpennies %= 100; 
 rdollars = (double)rpennies / 100; 
 printf("Loonies  %3d %9.4lf\n", loon, rdollars); 
 
 qrtr = rpennies / 25; 
 rpennies %= 25; 
 rdollars = (double)rpennies / 100; 
 printf("Quarters %3d %9.4lf\n", qrtr, rdollars); 
 
 dm = rpennies / 10; 
 rpennies %= 10; 
 rdollars = (double)rpennies / 100; 
 printf("Dimes    %3d %9.4lf\n", dm, rdollars); 
 
 nckl = rpennies / 5; 
 rpennies %= 5; 
 rdollars = (double)rpennies / 100; 
 printf("Nickels  %3d %9.4lf\n", nckl, rdollars); 
 
 pen = rpennies / 1; 
 rpennies %= 1; 
 rdollars = (double)rpennies / 100; 
 printf("Pennies  %3d %9.4lf\n\n", pen, rdollars); 
 
 acostpennies = tpennies * 1000 / (shirtstommy + shirtspatty + shirtssally) + 5; 
 acostdollars = (double)acostpennies / 100000; 
 printf("Average cost/shirt: $%.4lf\n\n", acostdollars); 
 
 return 0; 
}
