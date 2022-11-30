/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

#include <stdio.h>

#include "core.h"

void sinputInt(void);
void sinputIntPositive(void);
void sinputIntRange(void);
void sinputIntRange(void);
void sinputCharOption(void);
void sinputCString(void);
void sinputCString(void);
void sinputCString(void);
void sdisplayPhone(void);

int main(void)
{
    printf("Assignment 1 Milestone 1: Tester\n");
    printf("================================\n\n");

    sinputInt();
    sinputIntPositive();
    sinputIntRange();
    sinputIntRange();

    sinputCharOption();

    sinputCString();
    sinputCString();
    sinputCString();
    sdisplayPhone();

    printf("Assignment #1 Milestone #1 testing completed!\n");

    return 0;
}

void test01_inputInt(void)
{
    int intValue = 0;

    printf("TEST #1 - Instructions:\n"
           "1) Enter the word 'error'  [ENTER]\n"
           "2) Enter the number '-100' [ENTER]\n"
           ":>");

    intValue = inputInt();

    printf("////////////////////////////////////////\n");
    printf("TEST #1 RESULT: ");
    if (intValue == -100)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test02_inputIntPositive(void)
{
    int intValue = -1;

    printf("TEST #2 - Instructions:\n"
           "1) Enter the number '-100' [ENTER]\n"
           "2) Enter the number '200'  [ENTER]\n"
           ":>");

    intValue = inputIntPositive();

    printf("////////////////////////////////////////\n");
    printf("TEST #2 RESULT: ");
    if (intValue == 200)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test03_inputIntRange(void)
{
    int intValue = 999;

    printf("TEST #3 - Instructions:\n"
           "1) Enter the word 'error' [ENTER]\n"
           "2) Enter the number '-4'  [ENTER]\n"
           "3) Enter the number '12'  [ENTER]\n"
           "4) Enter the number '-3'  [ENTER]\n"
           ":>");

    intValue = inputIntRange(-3, 11);

    printf("////////////////////////////////////////\n");
    printf("TEST #3 RESULT: ");
    if (intValue == -3)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test04_inputIntRange(void)
{
    int intValue = 999;

    printf("TEST #4 - Instructions:\n"
           "1) Enter the number '14' [ENTER]\n"
           ":>");

    intValue = inputIntRange(-40, 14);

    printf("////////////////////////////////////////\n");
    printf("TEST #4 RESULT: ");
    if (intValue == 14)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test05_inputCharOption(void)
{
    char charValue = 'x';

    printf("TEST #5 - Instructions:\n"
           "1) Enter the character 'R' [ENTER]\n"
           "2) Enter the character 'e' [ENTER]\n"
           "3) Enter the character 'p' [ENTER]\n"
           "4) Enter the character 'r' [ENTER]\n"
           ":>");

    
    charValue = inputCharOption("qwErty");

    printf("////////////////////////////////////////\n");
    printf("TEST #5 RESULT: ");
    if (charValue == 'r')
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");
}

void test06_inputCString(void)
{
    char cstringValue[7] = { '\0' };

    
    printf("TEST #6: - Instructions:\n"
           "1) Enter the word 'horse'   [ENTER]\n" 
           "2) Enter the word 'chicken' [ENTER]\n"  
           "3) Enter the word 'SENECA'  [ENTER]\n"  
           ":>");

    
    inputCString(cstringValue, 6, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #6 RESULT: ");
    printf("%s (expected result: SENECA)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

void test07_inputCString(void)
{
    char cstringValue[7] = { '\0' };

    
    printf("TEST #7: - Instructions:\n"
           "1) Enter the words 'Seneca College' [ENTER]\n"
           "2) Enter the word 'CATS'            [ENTER]\n"
           ":>");

    
    inputCString(cstringValue, 4, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #7 RESULT: ");
    printf("%s (expected result: CATS)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

void test08_inputCString(void)
{
    char cstringValue[7] = { '\0' };

    
    printf("TEST #8: - Instructions:\n"
           "1) Enter the word 'dogs'  [ENTER]\n"
           "2) Enter the word 'HORSES' [ENTER]\n"
           ":>");

    
   inputCString(cstringValue, 5, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #8 RESULT: ");
    printf("%s (expected result: HORSES)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");
}

void test09_displayPhone(void)
{
    char* phone1 = NULL;
    char phone2[10 + 1] = "";
    char phone3[10 + 1] = "1";
    char phone4[10 * 2] = "111333444499999999";
    char phone5[10 + 1] = "111222444z";
    char phone6[10 + 1] = "z112224444";
    char phone7[10 + 1] = "4161114444";

    printf("////////////////////////////////////////\n");
    printf("TEST #9 RESULT:\n");
    printf("Expecting (___)___-____ => Your result: ");
    
    displayFormattedPhone(phone1);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    
    displayFormattedPhone(phone2);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    
    displayFormattedPhone(phone3);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");

    displayFormattedPhone(phone4);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    
    displayFormattedPhone(phone5);
    putchar('\n');

    printf("Expecting (___)___-____ => Your result: ");
    
    displayFormattedPhone(phone6);
    putchar('\n');

    printf("Expecting (416)111-4444 => Your result: ");
    
    displayFormattedPhone(phone7);
    printf("\n"
           "////////////////////////////////////////\n\n");
}
