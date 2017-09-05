#include <stdio.h>
#include <string.h>

int sum(int *p, int lenth);

int main()
{
	int result, i, num[100],j;
	char command=0,length;

	printf("number lenth : ");
	scanf("%d",&length);

	for(i=0;i<length;i++)
	{
		printf("Input %dnumber : ",i+1);
		scanf("%d",&num[i]);
	}	

	printf("=========================================\n");
	for(j=0;j<length;j++)
		printf("%d  ",num[j]);
	printf("\n");
	printf("=========================================\n");
	result=sum(num,length);
	printf("lenth : %d, sum : %d\n", length, result);
	
	return 0;
}

int sum(int *num, int length)
{
	int i, result=0;
	for(i=0;i<length;i++)
		result += num[i];
	return result;
}
