#include <stdio.h>
#include <string.h>

void bubbleSort(int *A, int n);

int main()
{
	int DataSet[]={12,70,30,20,55,25,40,50};
	int Length = sizeof(DataSet)/sizeof(DataSet[0]);
	int i=0;

	bubbleSort(DataSet, Length-1);


	printf("<Bubble Sort>\n");
	for(i=0; i<Length; i++)
		printf("%d ",DataSet[i]);
	printf("\n");

	return 0;
}

void bubbleSort(int *A, int n)
{
	int last, sorted, i,tmp; 

	for(last=n-1; last>=1; last--)
	{
		sorted=1;
		for(i=0;i<=last;i++)
		{
			if(A[i]>A[i+1])
			{
				tmp=A[i];
				A[i]=A[i+1];
				A[i+1]=tmp;
				sorted=0;
			}
		}
		if(sorted)
			return;
	}
}
