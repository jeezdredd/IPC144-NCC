/*
 *****************************************************************************
                          Workshop - #3 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main (void) {
  int a = 1, b =2;
  int option ;

  //if-then-else
  if (a == b)
  {
    printf("%d == %d\n", a, b);
  }

  else 
  {
    printf("%d != %d\n", a, b);
  }

  printf("What do you want for a side? ");
  printf("1 - mashed potatoes\n");
  printf("2 - french fries\n");
  printf("3 - broccoli\n");
  printf("4 - green beans\n");
  
  scanf("%d%*c", &option);
  if(option == 1)
  {
    printf("mashed coming right up\n");
  }
  else 
  {
    if (option == 2)
    {
        printf("nice crispy fries on the way\n");
    }
    else 
    {
        if (option == 3)
        {
            printf("Broccoli i soooo healthy\n");
        }
        else 
        {
            if (option == 4)
            {
                printf("Green beans are yummy\n");
            }
            else {
                printf("Sorry I do not have # %d\n", option);
            }
        }
    }
  }

  if(option == 1)
  {
    printf("mashed coming right up\n");
  }
  else if (option == 2)
    {
        printf("nice crispy fries on the way\n");
    }
    else if (option == 3)
        {
            printf("Broccoli i soooo healthy\n");
        }
        else if (option == 4)
            {
                printf("Green beans are yummy\n");
            }
            else 
            {
                printf("Sorry I do not have # %d\n", option);
            }

//When we do not use a block we need to be careful not
//to try to add a second statement to the else part

            if (b % 2 == 0) printf("%d is even\n", b);
            else printf("%d is odd \n", b);
            printf("odd but still a great number\n");
  
  char favColour;
  printf("What is your favorite colour? \n");
  printf("(R) - red\n");
  printf("(B) - blue\n");
  printf("(G) - green\n");
  scanf("%c", &favColour);
  
  switch (favColour) 
  {
    case 'R':
    case 'r':
    printf("Red is bright\n");
    break;
    case 'B':
    case 'b':
    printf("I like blue too\n");
    break;
    case 'G':
    case 'g':
    printf("Just like the trees\n");
    break;
    default:
    printf("I do not have that colour paint\n");
    break;
  }
  
  // ternary statement
  b = 5;
  printf("%d is %s\n", b,
  (b % 2 == 0) ?"even" : "odd");

    a += 3 * (b % 2 == 0) ? a - 1 : a + 1;
    printf("a=%d\n", a);

  return 0;
}