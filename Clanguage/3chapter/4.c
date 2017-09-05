#include <stdio.h>

int main()
{
	int number;

	printf("Insert of number : ");
	scanf("%d",&number);

	switch(number%2)
	{
		case 1:
		case -1:
			printf("Odd number%d\n",number%2);
		break;
		
		case 0:
			printf("Even number\n");
		break;
	}
	
	return 0;
}

