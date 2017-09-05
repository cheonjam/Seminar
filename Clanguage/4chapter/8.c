#include <stdio.h>

int main()
{
	int i , j , k ;
	
	for(i=0 ; i <3 ; i++)
	{
		printf("i%d",i);
		//if(i==1) break;
	
		for(j=0 ; j <3 ; j++)
		{	
			printf("j%d",j);
			if(j==1) break;
			//
			for(k=0 ; k<3 ; k ++)
			{	
				printf("k%d",k);
			}
		}
	}
	
	printf("\n");

	return 0;
}

