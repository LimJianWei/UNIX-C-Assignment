#include <string.h>	/*string function*/
#include <stdlib.h>	/*malloc*/
#include <stdio.h>	/*FILE, fopen, fgets, EOF, etc*/
#include "data.h"	/*struct*/
#include "list.h"	/*linked list function*/
#define BUFFER_SIZE 100	/*adjust here for input buffer size*/


/*	File input stream as input, malloc appropriate sizes, and create a linked list 
	first line will be as name, second line as day and time				*/
Node *fileInput(char *cp)
{
	FILE *fp = NULL;
	fp = fopen(cp,"r");
	if(fp==NULL)
		return NULL;/*return NULL when error*/
	else
	{

		char buffer[BUFFER_SIZE];/*reminder, create constant macro for buffer size*/
		Node node;
		Node *head = NULL;

		do{
			fgets(buffer, BUFFER_SIZE, fp);/*for name*/
			strtok(buffer, "\n");/*remove \n from buffer*/
			node.name = (char*)malloc((strlen(buffer)+1)*sizeof(char));
			strcpy(node.name, buffer);

			fscanf(fp, "%s", buffer);/*day*/
			node.day = (char*)malloc((strlen(buffer)+1)*sizeof(char));
			strcpy(node.day, buffer);

			fscanf(fp, "%s", buffer);/*time*/
			node.time = (char*)malloc((strlen(buffer)+1)*sizeof(char));
			strcpy(node.time, buffer);

			push(&head, &node);
		}while(fgetc(fp)!=EOF);
		/*feedback loop uses EOF character to detect, the last node created is redundant*/
		free(node.name);
		free(node.day);
		free(node.time);
		pop(&head);
		return head;
	}
	fclose(fp);
}

int fileOutput(Program *guide, char *cp, int *count, char *day)
{
	FILE *fp = NULL;
	fp = fopen(cp,"w");
	if(fp==NULL)
		return 1;/*return NULL when error*/
	else
	{
		int i;
		for(i=0;i<*count;++i)
		{
			if(!strcmp(day, guide[i].day))
			{
				if(strlen(guide[i].time)==4)	fprintf(fp, " ");
				fprintf(fp, "%s - %s\n", guide[i].time, guide[i].name);
			}
		}
	}
	return 0;
}
