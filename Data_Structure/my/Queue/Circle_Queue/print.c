#include "head.h"

void print(char *queue)
{
	int i,j;

	printf("\n===========\n");

	/*
	for(i=rear;i!=front;i--)
	{
		if(i<0)
			i=MAX;
		if(i==rear)
		{
			printf("(%d) %c <- rear\n",i,queue[i]);
			continue;
		}

		printf("(%d) %c\n",i,queue[i]);
	//	sleep(0.5);
		printf("rear: %d front : %d\n",rear,front);
	}
	*/
	i=rear;
	while(i!=front)
	{
		if(i==rear)
			printf("(%d) %c <- rear\n",i,queue[i]);
		else
			printf("(%d) %c\n",i,queue[i]);

		i--;
		if(i<0)
			i=MAX;
	}


	if(rear==front)
		printf("(%d) %c <-rear,front\n",i,queue[i]);
	else
		printf("(%d) %c <-front\n",i,queue[i]);

	printf("===========\n\n");
}
