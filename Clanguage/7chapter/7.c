#include <stdio.h>
#include <string.h>

void descending(int *num, int length);

int main()
{
	int sort[100], i,num[100],j;
	char command=0,length;

	while(1)
	{
		printf("number lenth : ");
		scanf("%d",&length);
	
		if(length<=0||length>100)
			{
				printf("Incorrect length!\n");
				continue;
			}
		break;
	}

for(i=0;i<length;i++)
	{
		printf("Input %dnumber : ",i+1);
		scanf("%d",&num[i]);
	}

	
	descending(num,length);

	for(j=0;j<i;j++)
		printf("%d ",num[j]);

	printf("\n");
	return 0;
}

void descending(int *num, int length)
{
	int i,j, temp;
	for(i=0;i<length;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(num[i]<num[j])
			{
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}
}

