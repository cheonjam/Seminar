#include <stdio.h>

int main()
{
	int i=0,n,sum=0;


	printf("Input Number:");
	scanf("%d",&n);
	if(n<0)
		printf("Number < 0 !!!\n");
	else
	{

	for(i=1;i<=n;i++)
		sum += i;

/*	while(i<=n)
	{
		sum += i;
		i++;
	}
*/

/*		do
		{
			sum += i;
			i ++;
		}while(i<=n);	
*/	
	}

		printf("Sum : %d\n",sum);
	

	return 0;
}
	
