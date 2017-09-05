#include <stdio.h>

int main()
{
	int number1,number2;

	printf("First number : ");
	scanf("%d",&number1);
	printf("Second number : ");
	scanf("%d",&number2);

	if(!number2)
		printf("Divide by 0\n");
	else 
		printf("Result : %d\n",number1/number2);
	
	return 0;
}

