#include <stdio.h>
#include <stdlib.h>

int sum(int i , int j);

int main()
{
	int result,num1,num2;

	printf("Input number 1 : ");
	scanf("%d",&num1);
	printf("input number 2 : ");
	scanf("%d",&num2);

	result=sum(num1,num2);
	printf("sum : %d\n",result);

	return 0;	
}

int sum(int i, int j)
{
	return i+j;
}
