#include "head.h"

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

