#include "head.h"

int deleteq(char *queue)
{
	if(front-1==rear||(rear==MAX&&front==0))
	{
		printf("\nData is empty !!!\n\n");
		return -1;
	}
	
	printf("Delete data : %c\n",queue[front]);

	if(front==MAX)
		front=0;
	else
		front++;

	if(front-1==rear||(rear==MAX&&front==0))
	{
		printf("\nData is empty !!!\n\n");
		return -1;
	}

	return 0;
}
