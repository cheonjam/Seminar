#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 16*13 

typedef struct
{
	int row;
	int col;
}element;

void push(element item);
element pop();
void stackFULL();
void stackEmpty();

element stack[MAX_STACK_SIZE];

int top;

