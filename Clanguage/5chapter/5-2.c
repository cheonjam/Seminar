#include <stdio.h>

int main()
{
	int i,j, Max=0, number[12], count[11]={};

	for(i=0;i<12;i++)	
	{
		printf("Input %dnumber(1~10): ",i+1);
		scanf("%d",&number[i]);
		if(number[i]<1 || number[i]>10)
		{
			printf("Incorrect number!!\n");
			i--;
			continue;
		}
	}	

	printf("========================\n");
	for(i=0;i<12;i++)
		printf("%d ",number[i]);
	printf("\n");
	printf("========================\n");

	for(i=0;i<12;i++)
		count[number[i]]++;
	
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
