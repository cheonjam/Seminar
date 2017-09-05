#include "head.h"

int addq(char *queue)
{
	char data;
	
	if(qisFull(queue))
	{
		printf("\nQueue is Full!!!!!\n\n");

		return 1;
	}

	if(rear==MAX)
		rear=0;
	else
		rear++;

	printf("Input Data : ");
	scanf("%c",&data);
	queue[rear]=data;
	
	print(queue);	
	return 0;
}
