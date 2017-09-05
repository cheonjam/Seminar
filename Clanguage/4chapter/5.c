#include <stdio.h>

int main()
{
	int number, i ;
	char character;

	
	while(1)
	{
		i=1;
		printf("Input character('q' = quit) : ");
		scanf("%s",&character);
	
		if(character=='q')
			break ;
	
		printf("The number to be repected : ");
		scanf("%d",&number);

		while(i <= number)
		{
			printf("%c",character);
			i ++;
		}
		printf("\n");
	}

	
	return 0;
}
