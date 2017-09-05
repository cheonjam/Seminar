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

void qisFull(char *queue)
{
	int i,j;
	char data;
	printf("Rearrange!!\n");

	for(i=front,j=0;i<=rear;i++,j++)
		queue[j]=queue[i];
	front=0;
	rear=j;

	printf("Input data : ");
	scanf("%c",&data);
	queue[rear]=data;

	print(queue);
}
