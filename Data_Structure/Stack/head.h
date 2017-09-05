#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct
{
	int key;
}element;

void push(element item);
element pop();
void stackFull();
void stackEmpty();
int menu();

element stack[MAX_STACK_SIZE];
int top;

