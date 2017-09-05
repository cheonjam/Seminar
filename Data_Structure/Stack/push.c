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
//	exit(1);
}


