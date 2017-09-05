#include "head.h"

int deleteq(char *queue)
{
	if(front>rear)
	{
		printf("\nData is empty !!!\n\n");
		return -1;
	}
	printf("Delete data : %c\n",queue[front++]);

	print(queue);
	return 0;
}
