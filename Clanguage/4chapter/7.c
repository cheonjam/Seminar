#include <stdio.h>

int main()
{
	int i ;
	char command;
	for(i=1 ; i <1000 ; i++)
	{
		if(i%7==0) 
			printf("%d\t",i);
		
		if(i%100==0)
		{	
			printf("\n");
			while(1)
			{
				printf("Continue (y/n)?");
				scanf("%c",&command);	
				getchar();
				if(command=='n')
					break;
				else if(command=='y')
					break;
				else 
					printf("Select y or n\n");
			}
			if(command=='n')
				break;		
		}
	}
	
	printf("\n");	

	return 0;
}
