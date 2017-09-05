#include <stdio.h>

int main()
{
	int i ;

	for(i=1 ;i<=1000; i++)
	{	
		if((i%19)==0)
			printf("%3d\t",i);
	}

	printf("\n");

	return 0;
}
