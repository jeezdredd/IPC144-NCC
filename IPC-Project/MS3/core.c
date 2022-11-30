/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include <stdlib.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
// 
// Copy Strings without using strlib
char* cus_strcpy(char* str2, const char* str1)
{
    char* tempHolder = str2;
    while ((*str2++ = *str1++) != '\0');
    return tempHolder;
}

// Copy Strings without using strlib
int cus_strlen(char* str1)
{
    int length = 0;
    while (*str1 != '\0')
    {
        str1++;
        length++;
    }
    return length;
}

// Validate integer input
int inputInt(void)
{
    int a = 0;
    char newline = 'x';
    if (newline == '\n')
        return a;
    else {
        do {
            scanf("%d%c", &a, &newline);
            if (newline != '\n')
            {
                clearInputBuffer();
                printf("Error! Input a whole number: ");
            }
        } while (newline != '\n');
        return a;
    }
}

// Validate positive integer input
int inputIntPositive(void)
{
    int a = 0;
    do {
        a = inputInt();
        if (a < 0)
            printf("ERROR! Value must be > 0: ");
    } while (a < 0);
    return a;
}

// Set input range
int inputIntRange(int lower, int upper)
{
    int a = 0;
    do {
        a = inputInt();
        if (a < lower || a > upper)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (a < lower || a > upper);
    return a;
}

// Check input character matches C string
char inputCharOption(const char* validChar)
{
    char letter;
    int  i;
    int  length = strlen(validChar);

    while (1)
    {
        scanf(" %c", &letter);
        clearInputBuffer();
        int flag = 0;
        for (i = 0; i < length; i++)
        {
            if (letter == validChar[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
        else
        {
            printf("Error! Character must me one of [%s]: ", validChar);
        }
    }
    return letter;
}

// Check input character string
void inputCString(char* stringPtr, int lower, int upper)
{
    int flag = 0, stringLength = 0;
    char userInput[99];
    do {
        scanf("%[^\n]%*c", userInput);
        int i;
        for (i = 0; userInput[i] != '\0'; i++)
        {
            stringLength = i + 1;
        }
        if (lower == upper && stringLength != lower)
        {
            printf("ERROR: String length must be exactly %d chars: ", lower);
            flag = 1;
        }
        else if (stringLength < lower)
        {
            printf("ERROR: String length must be between %d and %d chars: ", lower, upper);
            flag = 1;
        }
        else if (stringLength > upper)
        {
            printf("ERROR: String length must be no more than %d chars: ", upper);
            flag = 1;
        }
        else
        {
            flag = 0;
            cus_strcpy(stringPtr, userInput);
        }
    } while (flag != 0);

}

// Display array of 10 digits as formatted phone
void displayFormattedPhone(const char* stringPtr)
{
    int i, length;
    int flag = 0;
    if (stringPtr) length = strlen(stringPtr);
    if (stringPtr == NULL)
    {
        printf("(___)___-____");
    }
    else if (length < 10 || length > 10)
    {
        printf("(___)___-____");
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            if (stringPtr[i] < '0' || stringPtr[i] > '9')
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", stringPtr[0], stringPtr[1], stringPtr[2], stringPtr[3], stringPtr[4], stringPtr[5], stringPtr[6], stringPtr[7], stringPtr[8], stringPtr[9]);
        }
        else
        {
            printf("(___)___-____");
        }
    }
}
