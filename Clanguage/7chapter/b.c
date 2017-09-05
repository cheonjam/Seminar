#include <stdio.h>

int main()
{
	int i,j, result=0,max,temp;
	int num[5]={7, 9, 1, 4, 5};
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			if(num[i]<num[j])
			{
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}

	}

	for(i=0;i<5;i++)
		printf("%d ",num[i]);

	printf("\n");
}
