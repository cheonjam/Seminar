#include <stdio.h>
#include <string.h>

void quickSort(int *A, int p, int r);
int partition(int *A, int p, int r);

int main()
{
	int DataSet[]={12,70,30,20,55,25,40,50};
	int Length = sizeof(DataSet)/sizeof(DataSet[0]);
	int i=0;

	quickSort(DataSet,0, Length-1);

	printf("<QuickSort>\n");
	for(i=0; i<Length; i++)
		printf("%d ",DataSet[i]);
	printf("\n");

	return 0;
}

void quickSort(int *A, int p, int r)
{
	int q;

	if(p<r)
	{
		q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int partition(int *A, int p, int r)
{
	int i,j,x, tmp;

	x=A[r];
	i=p-1;

	for(j=p; j<r; j++)
	{
		if(A[j]<=x)
		{
			tmp=A[++i];
			A[i]=A[j];
			A[j]=tmp;
		}
	}
		tmp=A[i+1];
		A[i+1]=A[r];
		A[r]=tmp;

		return i+1;
}
