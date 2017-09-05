#include "head.h"

int pop(char *stack, int *top)
{
	if(*top==-1)
	{
		printf("Stack is empty \n");
		return -1;
	}
	printf("Delete data : %c\n",stack[(*top)--]);

	return 0;
}
