#include "head.h"

void init()
{
	printf("Input Queue Size : ");
	scanf("%d",&MAX);
	front=0;
	rear=-1;
}

int menu()
{
	int num;

	printf("=======MENU=========\n");
	printf("1.Add\n");
	printf("2.Delete\n");
	printf("3.Print\n");
	printf("4.Exit\n");
	printf("====================\n");
	printf("Choice number : ");
	scanf("%d",&num);
	getchar();

	return num;
}

int qisFull(char *queue)
{
	int i,count;
/*
	for(i=front,count=1;i!=rear;i++,count++)
	{
		if(i==MAX+1)
			i=0;
	}
	count++;

	if(count==MAX)
		return 1;

	retrun 0;

*/

	if(rear+2==front)
		return -1;
	if(rear==MAX-1 && front==0)
		return -1;
	if(rear==MAX && front==1)
		return -1;

	return 0;
}
