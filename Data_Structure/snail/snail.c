#include <stdio.h>

int main()
{
	int num=1,x,y,i,j,k,l,a,g,h, arr[1000][1000]={};

	printf("input number :");
	scanf("%d",&a);

	x=a-1;
	y=a-1;
	for(i=1,arr[x][y]=num;i<=a;i++)
	{
		if(i>1)
			arr[x][++y]=++num;
		
		for(k=1;k<i-1;k++)
			arr[--x][++y]=++num;
			
		for(h=1;h<i;h++)
			arr[--x][--y]=++num;
		
		for(l=1;l<i;l++)
			arr[++x][--y]=++num;
		
		for(g=1;g<i;g++)
			arr[++x][++y]=++num;
	}

	for(i=0;i<2*a-1;i++)
	{
		for(j=0;j<2*a-1;j++)
		{
			if(arr[i][j]==0)
				printf(" \t ");
			else
				printf(" %d\t ",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
