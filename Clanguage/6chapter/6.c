#include <stdio.h>

int main()
{
	int i,sum=0,num[5]={6, 9, 1, 4, 5};
	int *a=num;

	for(i=0;i<5;i++)
		sum+=*(a+i);

	printf("Sum:%d, everage:%d\n",sum,sum/5);

	return 0;
}
