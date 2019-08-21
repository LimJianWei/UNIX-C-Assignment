#ifndef LIST_H
#define LIST_H

void push(Node **head, Node *data);
void pop(Node **head);
void freeList(Node **head);
int countList(Node *head_ref);
/*void printList(Node *head_ref);*/
void process(Node *head, Program *guide, int *count);

#endif
