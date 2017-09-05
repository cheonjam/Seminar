#include <stdio.h>

int main()
{
	int number[10];
	int tmp, i=0, j;

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

	for(i=0;i<9;i++) 
	{
    	for(j=1;j<10-i;j++) 
	 	{	 
       		if(number[j-1]<number[j]) 
			{ 
       			 tmp=number[j-1]; 
				 number[j-1]=number[j]; 
	             number[j]=tmp;
			}
		}
	}

	for(i=0;i<10;i++) 
		printf("%d  ", number[i]); 
		
	printf("\n"); 

	return 0;
}

