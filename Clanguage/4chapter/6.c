#include <stdio.h>

int main()
{
	int  i, j;
	char character;
	for(i=0;i<5;i++)
	{
		printf("Input Character : ");
		scanf("%c",&character);
		getchar();

		for(j=0;j<character;j++)
			printf("+");
		
		printf("\n");
	}

	return 0;
}


