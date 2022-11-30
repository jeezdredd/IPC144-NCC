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
#ifndef CLINIC_H
#define CLINIC_H


//////////////////////////////////////
// Module macro's (usable by any file that includes this header)
//////////////////////////////////////

// Display formatting options (Provided to student)
// !!! DO NOT MODIFY THESE MACRO'S !!!
#define FMT_FORM 1
#define FMT_TABLE 2

#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10

#define START_HOURS 10
#define END_HOURS 14
#define START_MINS 0
#define END_MINS 0
#define INTERVALS 30

//////////////////////////////////////
// Structures
//////////////////////////////////////

struct Phone
{
    char description[PHONE_DESC_LEN + 1];
    char number[PHONE_LEN + 1];
};

struct Patient
{
    int patientNumber;
    char name[NAME_LEN + 1];
    struct Phone phone;
};

// ------------------- MS#3 -------------------


struct Time
{
    int hour;
    int min;
};

// Data type: Date
// ToDo:
struct Date
{
    int year;
    int month;
    int day;
};

// Data type: Appointment
// ToDo:
struct Appointment
{
    int patientNum;
    struct Date date;
    struct Time time;

};


// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
    struct Appointment* appointments;
    int maxAppointments;
};

void displayPatientTableHeader(void);

void displayPatientData(const struct Patient* patient, int fmt);

void displayScheduleTableHeader(const struct Date* date, int isAllRecords);

void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField);

void menuMain(struct ClinicData* data);

void menuPatient(struct Patient patient[], int max);

void menuPatientEdit(struct Patient* patient);

void menuAppointment(struct ClinicData* data);

void displayAllPatients(const struct Patient patient[], int max, int fmt);

void searchPatientData(const struct Patient patient[], int max);

void addPatient(struct Patient patient[], int max);

void editPatient(struct Patient patient[], int max);

void removePatient(struct Patient patient[], int max);


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void viewAllAppointments(struct ClinicData* data);

void viewAppointmentSchedule(struct ClinicData* data);

void addAppointment(struct Appointment* appoint, int maxAppoint, struct Patient* pat, int maxPat);
 
void removeAppointment(struct Appointment* appoint, int maxAppoint, struct Patient* pat, int maxPat);

//////////////////////////////////////0
// UTILITY FUNCTIONS
//////////////////////////////////////

void searchPatientByPatientNumber(const struct Patient patient[], int max);

void searchPatientByPhoneNumber(const struct Patient patient[], int max);

int nextPatientNumber(const struct Patient patient[], int max);

int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max);

void noRecords(void);

void swap(struct Appointment* a, struct Appointment* b);

int compareDate(const void* a, const void* b);

void BubbleSort(struct Appointment appoint[], int size);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

void inputPatient(struct Patient* patient);

void inputPhoneData(struct Phone* phone);

int strcmp(const char* s1, const char* s2);

void dateInput(int *yearPtr, int *monthPtr, int *dayPtr);

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

int importPatients(const char* datafile, struct Patient patients[], int max);

int importAppointments(const char* datafile, struct Appointment appoints[], int max);

#endif // !CLINIC_H
