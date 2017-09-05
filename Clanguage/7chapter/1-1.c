#include <stdio.h>
#include <stdlib.h>

//int sum(int i , int j);

int main(int argc, char *argv[])
{
	int i,j,result;
	i = atoi(argv[1]);
	j = atoi(argv[2]);

	printf("%d,%d",i,j);
	//result=sum(i,j);
	//printf("%d",result);

	return 0;	
}

/*int sum(int i, int j)
{
	int result = i+j;
	return result;
}
*/
