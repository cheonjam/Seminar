#include "head.h"

void push(element item)
{
	if(top >= MAX_STACK_SIZE-1)
		stackFULL();

	stack[++top]=item;	
}

void stackFULL()
{
	fprintf(stderr,"Stack is full, cannot add element");
	exit(1);
}

element pop()
{
	if(top==-1)
		stackEmpty();

	return stack[top--];
}

void stackEmpty()
{
	fprintf(stderr,"Stack is Empty, cannot delete element");
	exit(1);

}

