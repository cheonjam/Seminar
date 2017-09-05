#include <stdio.h>

int main()
{
	int number[10];
    int Max, Min, i=0;


	while(1)
	{
		printf("input number (%d/10) : ",i+1);
		scanf("%d",&number[i]);	
		if(number[i]<=0)
		{
			printf("Number > 0 !! \n");
			continue;
		}
		if(i==9)
			break;
		i++;
	}

	Max=number[0];
	Min=number[0];
	for(i=1;i<10;i++)
	{
		if(number[i]>Max)
			Max=number[i];
		
		if(number[i]<Min)
			Min=number[i];
		
	}

	printf("Max number : %d \n",Max);
	printf("Min number : %d \n",Min);

	return 0;
}
	
