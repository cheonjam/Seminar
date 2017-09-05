#include "head.h"

int push(char *stack, int *top)
{
	char data;
	
	if(*top==(MAX-1))
	{
		printf("Stack is full \n");
		return -1;
	}

	printf("Input Data : ");
	scanf("%c",&data);

	stack[++*top]=data;
	
	return 0;
}
