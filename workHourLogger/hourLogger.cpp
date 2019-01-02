/*
*	FILE			: hourLogger.cpp
*	PROJECT			: workHourLogger
*	PROGRAMMER		: Jordan Wickens
*	FIRST VERSION	: December 9, 2018
*	DESCRIPTION		: Takes work hours and writes them to a file.
*/

#pragma warning (disable : 4996)

// library
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS		100
#define MAX_INPUT		121
#define LINE_LENGTH		60

// prototype
void logInfo(char* jobTitle, char* city, char* details, float* pHoursWorked);
void saveFile(char* jobTitle, char* city, char* details, float hoursWorked);
float getNum(void);

int main()
{

	char jobTitle[MAX_CHARS] = "";
	char city[MAX_CHARS] = "";
	char details[MAX_CHARS] = "";

	float hoursWorked = 0;
	float *pHoursWorked = &hoursWorked;

	while (true)
	{
		printf("\n -- Work Hour Logger --\n\n\n");
		printf("Main Menu:\n");
		printf("1. Log\n");
		printf("2. Save\n");
		printf("3. Exit program\n");
		double choice = getNum();

		if (choice == 1)
		{
			logInfo(jobTitle, city, details, pHoursWorked);
			printf("Info was logged successfully!\n");
		}
		else if (choice == 2)
		{
			saveFile(jobTitle, city, details, hoursWorked);
			printf("Saved to .txt file!\n");
		}
		else if (choice == 3)
		{
			break;
		}
	}
	return 0;
}


void logInfo(char* jobTitle, char* city, char* details, float* pHoursWorked)
{
	// job title collection
	printf("Enter title for type of job:\n");
	fgets(jobTitle, MAX_CHARS, stdin);

	// city collection
	printf("\nEnter city of work:\n");
	fgets(city, MAX_CHARS, stdin);

	// details collection
	printf("\nEnter details:\n");
	fgets(details, MAX_CHARS, stdin);

	// hours collection
	printf("\nEnter hours worked:\n");
	*pHoursWorked = getNum();
}

void saveFile(char* jobTitle, char* city, char* details, float hoursWorked)
{	
	FILE *logFile = fopen("WorkLog.txt", "a");
	char separator[LINE_LENGTH] = "-------------------------------------------------";

	// import live time from library
	time_t t;
	time(&t);

	// logs and formats the info to a file
	fprintf(logFile, "Date: %s\nTitle: %s\nCity: %s\nDetails: %s\nHours worked: %.1lf\n%s\n", ctime(&t), jobTitle, city, details, hoursWorked, separator);


	fclose(logFile);
}

/*
* FUNCTION		: getNum
* DESCRIPTION	:
*	Prompts the user to enter a number, then records it.
* PARAMETERS	: None.
* RETURNS		:
*	number		: The number that the user entered.
*/

float getNum(void)
{
	char record[MAX_INPUT] = { 0 }; /* record stores the string */
	float number = 0;

	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	 * corresponding with the number of items it found in the string */
	if (sscanf(record, "%f", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		 * the system, set number to -1 */
		number = -1;
	}
	return number;
}