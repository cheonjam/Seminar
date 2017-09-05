#include "head.h"

void print(char *stack, int *top)
{
	int i;

	printf("\n======\n");
	for(i=*top;i>=0;i--)
	{
		if(i==*top)
		{
			printf("%c <- top\n",stack[i]);
			continue;
		}
		printf("%c\n",stack[i]);
	}
	printf("======\n\n");
}
