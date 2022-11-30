/*
*****************************************************************************
						  Workshop - #4 (P1)
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

int main (void)
{
	int number, i = 1;
	char characterinsert;

	printf("+----------------------+\n");
	printf("Loop application STARTED\n");
	printf("+----------------------+\n\n");

    
	do
	{
		printf("D = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &characterinsert, &number);
		if ((characterinsert == 'D' || characterinsert == 'W' || characterinsert == 'F') && (number >= 3 && number <= 20)) 
        {
			switch (characterinsert)
			{
			case 'D':

			printf("DO-WHILE: ");

			do {
					number--;

			printf("D");
            
				} while (number > 0);

			printf("\n\n");

			  break;

			case 'W':
			printf("WHILE   : ");
				while (number > 0)

				{
					number--;
                    
			printf("W");
				}

			printf("\n\n");
				break;

			default:
			printf("FOR     : ");
				for (number = number; number > 0; number--)

				{

			printf("F");

				}

			printf("\n\n");
				break;

			}
		}

		else if (characterinsert == 'Q')
		{

			if (number == 0)

			{

				i = number;
		    printf("\n+--------------------+\nLoop application ENDED\n+--------------------+\n\n");
            
			}

			else

			{
				printf("ERROR: To quit, the number of iterations should be 0!\n\n");
			}
		}

		else if ((characterinsert != 'D' && characterinsert != 'W' && characterinsert != 'F' && characterinsert != 'Q') || (number < 3 || number > 20))

		{

			if ((characterinsert != 'D' && characterinsert != 'W' && characterinsert != 'F' && characterinsert != 'Q') && (number < 3 || number > 20))

			{
				printf("ERROR: Invalid entered value(s)!\n\n");
			}

			else if ((number < 3 || number > 20))

			{
				printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
			}

			else

			{
				printf("ERROR: Invalid entered value(s)!\n\n");
			}
		}

	} while (i);
	return 0;
}