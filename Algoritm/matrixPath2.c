#include <stdio.h>

#define MAX 4
#define PATH_COUNT 7

int matrixPath(int matrix[MAX][MAX]);

void main()
{
	int matrix[MAX][MAX]={{6,7,12,5},{5,3,11,18},{7,17,3,3},{8,10,14,9}};
	int max;
	
	max=matrixPath(matrix);
	printf("max : %d\n",max);
}

int matrixPath(int matrix[MAX][MAX])
{
	int i,j,c[MAX][MAX];
	int path[PATH_COUNT][2],count,max;

	c[0][0]=matrix[0][0];

	for(i=1;i<MAX;i++)
		c[i][0]=matrix[i][0]+c[i-1][0];

	for(j=1; j<MAX; j++)
		c[0][j]=matrix[0][j]+c[0][j-1];

	for(i=1; i<MAX; i++)
	{
		for(j=1 ; j<MAX ; j++)
		{
			c[i][j]=matrix[i][j];

			if(c[i-1][j] > c[i][j-1])
				c[i][j]+=c[i-1][j];
			else
				c[i][j]+=c[i][j-1];
		}
	}

	i=MAX-1;
	j=MAX-1;
	count=PATH_COUNT-1;

	path[count][0]=i;
	path[count][1]=j;

	while(1)
	{
		printf("i : %d j : %d count : %d\n",i,j,count);
		sleep(1);
		if(i==0)
			j--;
		else if(j==0)
			i--;
		else
		{
			if(c[i-1][j]>c[i][j-1])
				i--;
			else
				j--;
		}
		path[--count][0]=i;
		path[count][1]=j;

		if(count==0)
			break;
	}
		
	for(count=0; count<PATH_COUNT; count++)
		printf("(%d,%d) ",path[count][0]+1,path[count][1]+1);
	printf("\n");
	for(i=0; i<MAX; i++)
	{
		for(j=0 ;j<MAX; j++)
			printf("%2d ",c[i][j]);
		printf("\n");
	}

	return c[MAX-1][MAX-1];
}
