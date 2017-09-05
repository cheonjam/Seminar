#include "head.h"

int main()
{
	element item,delete;
	top=-1;
	
	while(1)
	{
		switch(menu())
		{
			case 1 : printf("Input data : ");
					 scanf("%d",&item.key);
					 push(item);
					 break;

			case 2 : delete=pop();
					 printf("delete data : %d\n",delete.key);
					 break;

			case 3 : 
					 return 0;

			default : 
				 	printf("Reenter number(1~3)\n");
		}
	}

	return 0;
}
