#include <stdio.h>
#include <string.h>

void insertionSort(int *A, int n);

int main()
{
	int DataSet[]={12,70,30,20,55,25,40,50};
	int Length = sizeof(DataSet)/sizeof(DataSet[0]);
	int i=0;

	insertionSort(DataSet, Length);

	printf("<insertionSort>\n");
	for(i=0; i<Length; i++)
		printf("%d ",DataSet[i]);
	printf("\n");

	return 0;
}

void insertionSort(int *A, int n)
{
	int i=0, loc, newItem;

	for(i=1;i<n;i++)
	{
		loc=i-1;
		newItem=A[i];

		while(loc>=1 && newItem < A[loc])
		{
			A[loc+1]=A[loc];
			loc--;
		}
		A[loc+1]=newItem;
	}
}


