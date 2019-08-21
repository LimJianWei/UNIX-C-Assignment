#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"	/*structure*/
#include "io.h"		/*file io*/
#include "list.h"	/*linked list function*/
#include "interface.h"	/*terminal io*/
#include "comparison.h"	/*qsort function*/

/*	Remark: this does require input file to be in the correct format
		since it is not foolproof solution*/

/*Main function
	error message is generated here for less library dependancies	*/
int main(int c, char *v[])
{
	if(c!=3)
		printf("Error(main): Program only accepts two command-line parameters\n");
	else/*runs when there is two command-line parameters*/
	{
		Node *head = NULL;
		head = fileInput(v[1]);
		if(head==NULL)
			printf("Error(fileInput): failed to open '%s'\n",v[1]);
		else
		{
			int count, sort, i;
			char day[10];
			Program *guide;

			count = countList(head);
			guide = (Program*)malloc(count*sizeof(Program));/*allocate array*/
			process(head, guide, &count);/*assign heap memory address to array*/
			freeList(&head);/*free linked list only*/
			
			userInput(day, &sort);
			if(sort==1)
				qsort(guide, count, sizeof(Program), sortByName);
			else if(sort==2)
				qsort(guide, count, sizeof(Program), sortByTime);
			printGuide(guide, &count, day);
			if(fileOutput(guide, v[2], &count, day))
				printf("Error(fileOutput): failed to open '%s'\n",v[2]);
			for(i=0;i<count;++i)
			{
				free(guide[i].name);
				free(guide[i].day);
				free(guide[i].time);
			}
			free(guide);
			/*remember to free all heap*/
		}
	}
	return 0;
}
