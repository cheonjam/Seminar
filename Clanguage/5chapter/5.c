#include <stdio.h>

int main()
{
	int i,j, Max=0, number[12], count[10]={};

	for(i=0;i<12;i++)	
	{
		do
		{	
			printf("Input %dnumber(1~10): ",i+1);
			scanf("%d",&number[i]);
		}while(number[i]<=0 || number[i]>10);
	}	

	printf("========================\n");
	for(i=0;i<12;i++)
		printf("%d ",number[i]);
	printf("\n");
	printf("========================\n");

	for(i=0;i<12;i++)
	{
		for(j=1;j<=10;j++)
		{
			if(number[i]==j)
				count[j]+=1;
		}
	}

	for(i=1;i<=10;i++)
	{
		if(count[i]>Max)
			Max=count[i];
	}
	
	printf("Many number : ");
	for(i=1;i<=10;i++)
	{
		if(count[i]==Max)
			printf("%d ",i);
	}
	printf("\n");	
	return 0;
}
