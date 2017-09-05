#include "head.h"

int main()
{
	printf("Input size : ");
	scanf("%d",&MAX);

	char stack[MAX]; // MAX=100	
	int num,top=-1;
	
	while(1)
	{
		printf("=======MENU=========\n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.PRINT\n");
		printf("4.Exit\n");
		printf("====================\n");
		printf("Choice number : ");
		scanf("%d",&num);
		getchar();

		switch(num)
		{
			case 1 : if(!push(stack,&top))
						 print(stack,&top);
					 break;

			case 2 : if(!pop(stack,&top))
						 print(stack,&top);
					 break;

			case 3 : print(stack,&top);
					 break;
			
			case 4 : 
					 return 0;

			default : 
				 	printf("Reenter number(1~4)\n");
		}
	}

	return 0;
}
