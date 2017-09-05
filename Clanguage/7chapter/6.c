#include <stdio.h>

void sum(int *i, int *j, int *ret);

int main()
{
	int num1, num2, ret;

	printf("input 1 number : ");
	scanf("%d",&num1);

	printf("input 2 number : ");
	scanf("%d",&num2);

	sum(&num1,&num2,&ret);

	printf("%d\n",ret);

	return 0;
}

void sum(int *i, int *j, int *ret)
{
	*ret = *i+*j;
}
