#include "head.h"

int main()
{
	init(); // initialize front,rear,MAX
	char queue[MAX];  
	int num;
	
	while(1)
	{
		switch(menu())
		{
			case 1 : if(addq(queue))
					 	qisFull(queue);
					 break;

			case 2 : deleteq(queue);
					 break;

			case 3 : print(queue);
					 break;
			
			case 4 : 
					 return 0;

			default : 
				 	printf("Reenter number(1~4)\n");
		}
	}
	return 0;
}
