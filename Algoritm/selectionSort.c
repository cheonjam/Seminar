#include <stdio.h>
#include <string.h>

void selectionSort(int *DataSet, int n);
int theLargest(int *DataSet, int last);

int main()
{
	int DataSet[]={12,70,30,20,55,25,40,50};
	int Length = sizeof(DataSet)/sizeof(DataSet[0]);
	int i=0;

	selectionSort(DataSet, Length-1);

	for(i=0; i<Length; i++)
		printf("%d ",DataSet[i]);
	printf("\n");

	return 0;
}

void selectionSort(int *A, int n)
{
	int tmp, last, k;

	for(last=n; last>=1; last--)
	{
		k=theLargest(A,last);
		tmp=A[k];
		A[k]=A[last];
		A[last]=tmp;
	}
}

int theLargest(int *A, int last)
{
	int i, largest=0;
	
	for(i=1; i<=last; i++)
	{
		if(A[i]>A[largest])
			largest=i;
	}

	return largest;
}
