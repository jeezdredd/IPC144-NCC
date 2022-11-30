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


// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Validate integer input
int inputInt(void);

// Validate positive integer input
int inputIntPositive(void);

// Set input range
int inputIntRange(int lower, int upper);

// Check input character matches C string
char inputCharOption(const char* validChar);

// Copy Strings without using strlib
char* cus_strcpy(char* str2, const char* str1);

// Check input character string
void inputCString(char* stringPtr, int lower, int upper);

// Display array of 10 digits as formatted phone
void displayFormattedPhone(const char* stringPtr);



// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H