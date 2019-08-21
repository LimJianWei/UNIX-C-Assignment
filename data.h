#ifndef DATA_H
#define DATA_H

/*data structure for each node of linked list*/
typedef struct Node{
	char *name, *day, *time;
	struct Node *next;
}Node;

/*	Each program will be using struct Program for dynamically allocated array.
	struct Program will access the same malloced memory for name and day as
	struct Node.tldr: struct Program rely on malloced memory for struct Node 	*/
typedef struct{
	char *name, *day, *time;
}Program;

#endif
