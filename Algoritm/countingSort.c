#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define NUM 10

void countingSort(int *A, int *B, int n);

void main()
{
	int Data[NUM],Sort_Data[NUM], i;
	
	srand(time(NULL));
	for(i=0; i<NUM; i++)
		Data[i]=rand()%MAX;

	printf("Before : ");
	for(i=0; i<NUM; i++)
		printf("%d ",Data[i]);
	printf("\n");

	countingSort(Data,Sort_Data,NUM);

	printf("After  : ");
	for(i=0; i<NUM; i++)
		printf("%d ",Sort_Data[i]);
	printf("\n");
}


void countingSort(int *A, int *B, int n)
{
	int i;
	int count[MAX];


	memset(count,0,sizeof(count));

	for(i=0; i<n; i++)
		count[A[i]]++;

	for(i=1; i<MAX; i++)
		count[i]+=count[i-1];

	for(i=n-1;i>=0;i--)
	{
		B[count[A[i]]-1]=A[i];
		count[A[i]]--;
	}
	
}
