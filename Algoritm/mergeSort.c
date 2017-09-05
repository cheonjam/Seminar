#include <stdio.h>

void merge(int *DataSet, int first, int mid, int last);
void mergeSort(int *DataSet, int first, int last);

int main()
{
	int DataSet[]={12,70,30,20,55,25,40,50};
	int Length = sizeof(DataSet)/sizeof(DataSet[0]);
	int i=0;

	mergeSort(DataSet, 0, Length-1);

	for(i=0; i<Length; i++)
		printf("%d ",DataSet[i]);
	printf("\n");

	return 0;
}

void mergeSort(int *DataSet, int first, int last)
{
	int mid;

	if(first<last)
	{
		mid=(first+last)/2;
		mergeSort(DataSet,first,mid);
		mergeSort(DataSet, mid+1, last);
		merge(DataSet, first, mid, last);
	}
}

void merge(int *DataSet, int first, int mid, int last)
{
	int i=first, j=mid+1, t=0;
	int tmp[8]={};

	while(i<=mid && j<=last)
	{
		if(DataSet[i] >= DataSet[j])
			tmp[t++]=DataSet[i++];
		else
			tmp[t++]=DataSet[j++];
	}

	while(i<=mid)
		tmp[t++]=DataSet[i++];

	while(j<=last)
		tmp[t++]=DataSet[j++];
	
	for(i=first,t=0; i<=last; )
		DataSet[i++]=tmp[t++];
}
