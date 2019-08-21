#include <stdio.h>	/*printf, etc*/
#include <string.h>	/*string function*/
#include "boolean.h"	/*as condition/event handler*/
#include "data.h"	/*for Program struct*/

void userInput(char *day, int *sort)
{
	char input[20];
	int quit = FALSE;
	printf("This is a program to produce a formatted TV guide from raw input data\n");
	do{
		printf("Key in a day of a week(eg: monday): ");/*not designed to be foolproof, can be improved using toupper*/
		scanf("%s", input);
		quit = TRUE;
		if(!strcmp(input, "monday"))		strcpy(day,"Monday");
		else if(!strcmp(input, "tuesday"))	strcpy(day,"Tuesday");
		else if(!strcmp(input, "wednesday"))	strcpy(day,"Wednesday");
		else if(!strcmp(input, "thursday"))	strcpy(day,"Thursday");
		else if(!strcmp(input, "friday"))	strcpy(day,"Friday");
		else if(!strcmp(input, "saturday"))	strcpy(day,"Saturday");
		else if(!strcmp(input, "sunday"))	strcpy(day,"Sunday");
		else{
			printf("Error: Please check each letter and make sure all letter are small letter\n");
			quit = FALSE;
		}
	}while(!quit);
	do{
		printf("Key in sorting method(eg: name, time): ");
		scanf("%s", input);
		quit = TRUE;
		if(!strcmp(input, "name"))	*sort = 1;
		else if(!strcmp(input, "time"))	*sort = 2;
		else{
			printf("Error: Please check each letter and make sure all letter are small letter\n");
			quit = FALSE;
		}
	}while(!quit);
}

/*prints out correct guide, count for recursion times, day to specify which day to print*/
void printGuide(Program *guide, int *count, char *day)
{
	int i;

	printf("TV guide:\n");
	for(i=0;i<*count;++i)
	{
		if(!strcmp(day, guide[i].day))
		{
			if(strlen(guide[i].time)==4)	printf(" ");
			printf("%s - %s\n", guide[i].time, guide[i].name);
		}
	}
}

