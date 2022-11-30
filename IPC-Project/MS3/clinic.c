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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, checker = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0) {
            checker = 1;
            break;
        }
    }
    if (checker == 0) {
        noRecords();
        putchar('\n');
    }
    else {
        displayPatientTableHeader();
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber != 0)
                displayPatientData(&patient[i], fmt);
        }
        putchar('\n');
    }
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int index = 0;
    int flag = 0;
    for (i = 0; i < max; i++)
    {
        //printf("%d\n", patient[i].patientNumber);
        if (patient[i].patientNumber == 0) {
            index = i;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("ERROR: Patient listing is FULL!\n");
    }
    else {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n");
    }
    putchar('\n');
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int pat, index;
    printf("Enter the patient number: ");
    pat = inputIntPositive();
    index = findPatientIndexByPatientNum(pat, patient, max);
    putchar('\n');
    if (index != -1)
        menuPatientEdit(&patient[index]);
    else
        printf("ERROR: Patient record not found!\n");
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int pat, index;
    char confirm;
    printf("Enter the patient number: ");
    pat = inputIntPositive();
    index = findPatientIndexByPatientNum(pat, patient, max);
    putchar('\n');
    if (index != -1)
    {
        displayPatientData(&patient[index], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        confirm = inputCharOption("yn");
        if (confirm == 'y')
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n");
        }
        else if (confirm == 'n')
        {
            printf("Operation aborted.\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
    putchar('\n');
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    //qsort(identifier, struct size, sizeof(tag), compare);
    //qsort(Temp, data->maxAppointments, sizeof(struct Appointment), compareDate);
    int i, j;
    struct Appointment* Temp = (struct Appointment*)calloc(data->maxAppointments, sizeof(struct Appointment));
    
    for (i = 0; i < data->maxAppointments; i++)
    {
        Temp[i].patientNum = data->appointments[i].patientNum;
        Temp[i].date = data->appointments[i].date;
        Temp[i].time = data->appointments[i].time;
    }
    BubbleSort(Temp, data->maxAppointments);
    displayScheduleTableHeader(&Temp->date, 1);
    for  (i = 0;i < data->maxAppointments; i++)
    {
        if (Temp[i].patientNum != 0)
        {
            j = findPatientIndexByPatientNum(Temp[i].patientNum, data->patients, data->maxPatient);
            displayScheduleData(&data->patients[j], &Temp[i], 1);
        }
    }
    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int year, month, day;
    dateInput(&year, &month, &day);
    struct Date tempDate;
    tempDate.year = year;
    tempDate.month = month;
    tempDate.day = day;
    displayScheduleTableHeader(&tempDate, 0);
    int i, j;
    struct Appointment* Temp = (struct Appointment*)calloc(data->maxAppointments, sizeof(struct Appointment));
    for (i = 0; i < data->maxAppointments; i++)
    {
        Temp[i].patientNum = data->appointments[i].patientNum;
        Temp[i].date = data->appointments[i].date;
        Temp[i].time = data->appointments[i].time;
    }
    BubbleSort(Temp, data->maxAppointments);
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (Temp[i].patientNum != 0 && Temp[i].date.year == tempDate.year && Temp[i].date.month == tempDate.month && Temp[i].date.day == tempDate.day)
        {
            j = findPatientIndexByPatientNum(Temp[i].patientNum, data->patients, data->maxPatient);
            displayScheduleData(&data->patients[j], &Temp[i], 1);
        }
    }
    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoint, int maxAppoint, struct Patient* pat, int maxPat)
{
    int patNum,i;
    int year, month, day;
    int hour, minute;
    int flag = 0;
    int available = 0;
    for (i = 0; i < maxAppoint; i++)
    {
        if (appoint[i].patientNum < 1)
        {
            available = 1;
            break;
        }
    }
    if (available == 0)
    {
        printf("ERROR: Appointment is FULL!\n\n");
        return;
    }
    printf("Patient Number: ");
    patNum = inputIntPositive();
    int index = findPatientIndexByPatientNum(patNum, pat, maxPat);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
        return;
    }
    while (1)
    {
        dateInput(&year, &month, &day);
        printf("Hour (0-23)  : ");
        hour = inputIntRange(0, 23);
        printf("Minute (0-59): ");
        minute = inputIntRange(0, 59);
        for (i = 0; i < maxAppoint; i++)
        {
            if (appoint[i].date.year == year && appoint[i].date.month == month && appoint[i].date.day == day && appoint[i].time.hour == hour && appoint[i].time.min == minute)
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
                flag = 0;
                break;
            }
            flag = 1;
        }
        if (flag == 0)
            continue;
        while (1)
        {
            int input = hour * 60 + minute;
            if (input%INTERVALS != 0 || input < START_HOURS * 60 + START_MINS || input > END_HOURS * 60 + END_MINS)
            {
                printf("ERROR: Time must be between %02d:%02d and %02d:%02d in %d minute intervals.\n\n",
                    START_HOURS, START_MINS, END_HOURS, END_MINS, INTERVALS);
                printf("Hour (0-23)  : ");
                hour = inputIntRange(0, 23);
                printf("Minute (0-59): ");
                minute = inputIntRange(0, 59);
                flag = 0;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    for (i = 0; i < maxAppoint; i++)
    {
        if (appoint[i].patientNum < 1)
        {
            appoint[i].patientNum = patNum; appoint[i].date.year = year; appoint[i].date.month = month; appoint[i].date.day = day; appoint[i].time.hour = hour; appoint[i].time.min = minute;
            break;
        }
    }
    printf("\n*** Appointment scheduled! ***\n");
    putchar('\n');
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appoint, int maxAppoint, struct Patient* pat, int maxPat)
{
    int patientNum;
    int year, month, day;
    int i;

    printf("Patient Number: ");
    patientNum = inputIntPositive();
    int index = findPatientIndexByPatientNum(patientNum, pat, maxPat);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
        return;
    }

    
    dateInput(&year, &month, &day);
    putchar('\n');
    printf("Name  : %s\n", pat[index].name);
    printf("Number: %05d\n", pat[index].patientNumber);
    printf("Phone : ");
    displayFormattedPhone(pat[index].phone.number);
    printf(" (%s)\n", pat[index].phone.description);
    printf("Are you sure you want to remove this appointment (y,n): ");
    char answer;
    answer = inputCharOption("yn");
    if (answer == 'n')
    {
        printf("Operation aborted.\n");
    }
    else
    {
        for (i = 0; i < maxAppoint; i++)
        {
            if (appoint[i].patientNum == patientNum &&
                appoint[i].date.year == year &&
                appoint[i].date.month == month &&
                appoint[i].date.day == day)
            {
                appoint[i].patientNum = 0;
                break;
            }
        }
        printf("\n*** Appointment record has been removed! ***\n");
    }
    putchar('\n');
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int pat, index;
    printf("Search by patient number: ");
    pat = inputIntPositive();
    putchar('\n');
    index = findPatientIndexByPatientNum(pat, patient, max);
    if (index != -1)
        displayPatientData(&patient[index], FMT_FORM);
    else
        noRecords();
    putchar('\n');
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    char phone[PHONE_LEN + 1];
    int flag = 0;
    printf("Search by phone number: ");
    inputCString(phone, 10, 10);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(phone, patient[i].phone.number) == 0)
        {
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        putchar('\n');
        noRecords();
    }
    else {
        for (i = 0; i < max; i++) {
            if (strcmp(phone, patient[i].phone.number) == 0)
                displayPatientData(&patient[i], FMT_TABLE);
        }
    }
    putchar('\n');
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i;
    int temp = -1;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > temp) {
            temp = patient[i].patientNumber;
        }
    }
    temp++;
    return temp;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i;
    int index = -1;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
            index = i;
    }
    return index;
}
// Print No records found
void noRecords(void)
{
    printf("*** No records found ***\n");
}

// Swap function
void swap(struct Appointment* a, struct Appointment* b)
{
    struct Appointment Temp = *a;
    *a = *b;
    *b = Temp;
}

// Compare function (for qsort)
/*int compareDate(const void* a, const void* b)
{
    const struct Appointment* tempA = a;
    const struct Appointment* tempB = b;
    long long dateTimeA = (tempA->date.year * 60 * 24 * 30 * 12) + (tempA->date.month * 60 * 24 * 30) + (tempA->date.day * 60 * 24) + (tempA->time.hour * 60) + (tempA->time.min);
    long long dateTimeB = (tempB->date.year * 60 * 24 * 30 * 12) + (tempB->date.month * 60 * 24 * 30) + (tempB->date.day * 60 * 24) + (tempB->time.hour * 60) + (tempB->time.min);
    return(dateTimeA - dateTimeB);
}*/

// Bubble Sort function
void BubbleSort(struct Appointment appoint[], int size)
{
    int j, k;
    for (j = 0; j < size - 1; j++)
    {
        for (k = 0; k < size - j - 1; k++)
        {
            long long dateTimeA = (appoint[k].date.year * 60 * 24 * 30 * 12) + (appoint[k].date.month * 60 * 24 * 30) + (appoint[k].date.day * 60 * 24) + (appoint[k].time.hour * 60) + (appoint[k].time.min);
            long long dateTimeB = (appoint[k + 1].date.year * 60 * 24 * 30 * 12) + (appoint[k + 1].date.month * 60 * 24 * 30) + (appoint[k + 1].date.day * 60 * 24) + (appoint[k + 1].time.hour * 60) + (appoint[k + 1].time.min);
            if (dateTimeA > dateTimeB)
                swap(&appoint[k], &appoint[k + 1]);
        }
    }
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&(patient->phone));
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');
    if (selection == 1)
    {
        cus_strcpy(phone->description, "CELL");
        //inputCString(phone->number,10,10);
    }
    if (selection == 2)
    {
        cus_strcpy(phone->description, "HOME");
    }
    if (selection == 3)
    {
        cus_strcpy(phone->description, "WORK");
    }
    if (selection == 4)
    {
        cus_strcpy(phone->description, "TBD");;
    }
    else
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
    }
}
// Date (y/m/d) input function for repetition
void dateInput(int* yearPtr, int* monthPtr, int* dayPtr)
{
    int year, month, day;
    printf("Year        :");
    year = inputIntPositive();
    printf("Month (1-12): ");
    month = inputIntRange(1, 12);
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
    }
    else if (month == 2)
    {
        if (year%4 == 0)
        {
            printf("Day (1-29)  : ");
            day = inputIntRange(1, 29);
        }
        else {
            printf("Day (1-28)  : ");
            day = inputIntRange(1, 28);
        }
    }
    else
    {
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
    }
    if (yearPtr) *yearPtr = year;
    yearPtr = &year;
    if (monthPtr) *monthPtr = month;
    monthPtr = &month;
    if (dayPtr) *dayPtr = day;
    dayPtr = &day;
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int counter = 0;

    FILE* fp;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "%*[^\n]\n") != EOF) {
            if(fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[counter].patientNumber,
                patients[counter].name,
                patients[counter].phone.description,
                patients[counter].phone.number));
            counter++;
            if (counter >= max)
                break;
        }
    }
    else
    {
        printf("Failed to open file %s!!!\n", datafile);
        printf("Program is exiting...\n");
        exit(1);
    }
    return counter;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int counter = 0;

    FILE* fp;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[counter].patientNum,
            &appoints[counter].date.year,
            &appoints[counter].date.month,
            &appoints[counter].date.day,
            &appoints[counter].time.hour,
            &appoints[counter].time.min) != EOF)
        {
            counter++;
            if (counter >= max)
                break;
        }
    }
    else
    {
        printf("Failed to open file %s!!!\n", datafile);
        printf("Program is exiting...\n");
        exit(1);
    }
    return counter;
}