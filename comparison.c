#include <string.h>
#include "data.h"
#include "boolean.h"

int sortByTime(const void *a, const void *b)
{
	Program *A = (Program *)a;
	Program *B = (Program *)b;
	int timeA, timeB;
	/*	as time char array contains :, can't directly use atoi, strtok isn't suitable too
		Below is just converting string to integer while neglecting :
		it's using conditional/ternary operator*/
	(strlen(A->time)==4)?
		(timeA = 100*(A->time[0]-'0')+10*(A->time[2]-'0')+(A->time[3]-'0')):
		(timeA = 1000*(A->time[0]-'0')+100*(A->time[1]-'0')+10*(A->time[3]-'0')+(A->time[4]-'0'));
	(strlen(B->time)==4)?
		(timeB = 100*(B->time[0]-'0')+10*(B->time[2]-'0')+(B->time[3]-'0')):
		(timeB = 1000*(B->time[0]-'0')+100*(B->time[1]-'0')+10*(B->time[3]-'0')+(B->time[4]-'0'));
	return timeA - timeB;
}

int sortByName(const void *a, const void *b)
{
	Program *A = (Program *)a;
	Program *B = (Program *)b;
	int recursion, temp;
	int i=0;
	int quit = FALSE;
	/*control amount of recursion, using conditional operator too*/
	(strlen(A->name)<strlen(B->name))?(recursion=strlen(A->name)):(recursion=strlen(B->name));
	/*	if both char is identical, compare the next
		can handle even if both string has same content*/
	while(!quit&&(recursion>i)) 
	{
		temp = A->name[i] - B->name[i];
		if(temp!=0)	quit = TRUE;
		++i;
	}
	if(temp==0)	temp = 1;/*shorter name prints out first*/
	return temp;
}
