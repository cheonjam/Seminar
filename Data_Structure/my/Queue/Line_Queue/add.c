#include "head.h"

int addq(char *queue)
{
	char data;
	
	if(rear==(MAX-1))
	{
		if(front==0)
		{
			printf("\nQueue is Full!!!!!\n\n");
			return 0;
		}
	
		return 1;
	}

	printf("Input Data : ");
	scanf("%c",&data);
	queue[++rear]=data;
	
	print(queue);	
	return 0;
}
