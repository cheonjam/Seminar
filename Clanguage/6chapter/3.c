#include <stdio.h>

int main()
{
	int num[10],i,max;	
	int *pNum=num;
		
	for(i=0;i<10;i++)
	{
		printf("Input (%d)number :",i+1);
		scanf("%d",pNum+i);
	}
	printf("your input number:");
	for(i=0;i<10;i++)
		printf("%d ",*(pNum+i));
	printf("\n");

	max=*pNum;	
	for(i=0;i<10;i++)
	{
		if(*(pNum+i)>max)
			max=*(pNum+i);
	}
	
	printf("Max number:%d\n",max);

	return 0;
}

