#include "head.h"

void print(char *queue)
{
	int i,j;

	printf("\n======\n");
	for(j=rear,i=rear;i>front;i--,j--)
	{
		if(i==rear)
		{
			printf("(%d) %c <- rear\n",j,queue[i]);
			continue;
		}
		printf("(%d) %c\n",j,queue[i]);
	}

	if(front==rear)
		printf("(%d) %c <-front,rear\n",j,queue[i]);
	else if(front<rear)
		printf("(%d) %c <-front \n",j,queue[i]);
	printf("======\n\n");
}
