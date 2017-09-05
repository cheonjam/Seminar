#include "head.h"

void set()
{
	FILE *fp=fopen("map","r");
	int i,j;

	top=-1;row=1;col=0;

	for(i=0;i<14;i++)
	{
		for(j=0;j<18;j++)
		{
			fscanf(fp,"%c",&maze[i][j]);
		}
	}

	fclose(fp);
}	
