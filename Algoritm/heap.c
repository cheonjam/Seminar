#include <stdio.h>
#include <stdlib.h>
void buildHeap(int a[],int n)
{
	int i;
	
	for(i=n/2;i>=1;i--)
	{
		heapify(a,i,n);
	}
}
void heapify(int a[],int k,int n)
{
	int left,right,smaller,tmp;

	left = 2*k;
	right = 2*k+1;

	if(right<=n)
	{
		if(a[left] < a[right])
			smaller = left;
		else
			smaller = right;
	}
	else if(left <= n)
		smaller = left;
	else
		return;

	if(a[smaller] < a[k])
	{
		tmp = a[k];
		a[k] = a[smaller];
		a[smaller] = tmp;
	
		heapify(a,smaller,n);
	}
}

void heapSort(int a[],int n)
{
	int i,tmp;
	
	buildHeap(a,n);

	for(i=n;i>=2;i--)
	{
		tmp = a[1];
		a[1] = a[i];
		a[i] = tmp;

		heapify(a,1,i-1);
	}
}
int main()
{
	int *arr;
	int i,n;

	printf("input n(under 10) == ");
	scanf("%d\n",&n);

	arr = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("\n");
	
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	
	heapSort(arr,n);

	printf("\n");
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	

	printf("\n");
}
		
