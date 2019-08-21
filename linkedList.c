#include <stdlib.h>	/*free function*/
#include "data.h"	/*struct*/


/*create a new node from a linked list, assign address for pointers*/
void push(Node **head, Node *data)
{
	Node *new_head;
	
	new_head = (Node*)malloc(sizeof(Node));
	new_head->name = data->name;
	new_head->day = data->day;
	new_head->time = data->time;
	new_head->next = (*head);
	(*head) = new_head;
}

/*	destroy current head, previous head becomes current head, 
	and free heap memory created via malloc			*/
void pop(Node **head)
{
	if((*head)!=NULL)
	{
		Node *ref = (*head)->next;
		free(*head);
		(*head) = ref;
	}
}


/*not in use, for debug purposes, prints out tv guide
void printList(Node *head_ref)
{
	while(head_ref!=NULL)
	{
		printf("%s\n%s %s\n",head_ref->name, head_ref->day, head_ref->time);
		head_ref = head_ref->next; 
	}
}*/

/*free linked list by looping pop function*/
void freeList(Node **head)
{
	while((*head)!=NULL)
		pop(head);
}

/*counts how many node in a linked list*/
int countList(Node *head_ref)
{
	int count = 0;
	while(head_ref!=NULL)
	{		
		head_ref = head_ref->next;
		count++;
	}
	return count;
}

/*transfer heap address from linked list to guide*/
void process(Node *head, Program *guide, int *count)
{
	int i;
	for(i=0;i<*count;++i)
	{
		guide[i].name = head->name;
		guide[i].day = head->day;
		guide[i].time = head->time;
		head = head->next;
	}
}
