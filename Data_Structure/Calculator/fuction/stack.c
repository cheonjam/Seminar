#include "head.h"

void push(char *stack, char item)
{
	if(top >= MAX_STACK_SIZE-1)
		stackFULL();

	stack[++top]=item;	
}

void stackFULL()
{
	fprintf(stderr,"Stack is full, cannot add element\n");
	exit(1);
}

char pop(char *stack)
{
	if(top==-1)
		stackEmpty();

	return stack[top--];
}

void stackEmpty()
{
	fprintf(stderr,"Stack is Empty, cannot delete element\n");
	exit(1);

}
