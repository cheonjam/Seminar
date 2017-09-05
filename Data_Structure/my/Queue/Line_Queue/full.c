#include "head.h"

void qisFull(char *queue)
{
	int i,j;

	for(i=front,j=0;i!=rear;i++,j++)
		queue[j]=queue[i];
	front=-1;
	rear=j;
}
