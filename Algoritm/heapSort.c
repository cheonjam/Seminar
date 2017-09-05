#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define NUM 10 

void BuildHeap(int *A, int n);
void heapify(int *A, int k, int n);
void HeapSort(int *A, int n);

void main()
{
	int Data[NUM],i;
	
	srand(time(NULL));
	for(i=0; i<NUM; i++)
		Data[i]=rand()%MAX;

	printf("Before : ");
	for(i=0; i<NUM; i++)
		printf("%d ",Data[i]);
	printf("\n");

	HeapSort(Data,NUM-1);

	printf("After  : ");
	for(i=0; i<NUM; i++)
		printf("%d ",Data[i]);
	printf("\n");
}

void BuildHeap(int *A, int n)
{
	int i;

	for(i=(n/2) ; i>=0; i--)
		heapify(A, i, n);
}

void heapify(int *A, int k, int n)
{
	int left, right, tmp, higher;

	left=2*k;
	right=2*k+1;
	
	if(right <= n)
	{
		if(A[left]>A[right])
			higher=left;
		else
			higher=right;
	}
	else if(left<=n)
		higher=left;
	else
		return ;

	if(A[higher] > A[k])
	{
		tmp=A[k];
		A[k]=A[higher];
		A[higher]=tmp;
		
		heapify(A, higher, n);
	}
}

void HeapSort(int *A, int n)
{
	int tmp,i;

	BuildHeap(A,n);

	for(i=n;i>=1; i--)
	{
		tmp=A[0];
		A[0]=A[i];
		A[i]=tmp;

		heapify(A,0,i-1);
	}
}
