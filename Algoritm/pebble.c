#include <stdio.h>

#define MAX 8
void main()
{
	int w[4][MAX]={{6,7,12,-5,5,3,11,3},{-8,10,14,9,7,13,8,5},{11,12,7,4,8,-2,9,4}};
	int route[MAX];
	int p,i,j,max,peb[4][MAX];


	for(i=0;i<MAX;i++)
		w[3][i]=w[0][i]+w[2][i];

	printf("\n\n");
	for(p=0; p<4; p++)
	{
		for(i=0; i<MAX; i++)
			printf("%4d ",w[p][i]);
		printf("\n");
	}
	printf("\n\n");

	for(p=0; p<3; p++)
		peb[p][0]=w[p][0];
	peb[3][0]=w[0][0]+w[2][0];

	for(i=1;i<MAX;i++)
	{
		for(p=0;p<4;p++)
		{
			peb[p][i]=w[p][i];
			switch(p)
			{
				case 0:
					if(peb[1][i-1]>peb[2][i-1])
						max=peb[1][i-1];
					else
						max=peb[2][i-1];
					break;

				case 1:
					if(peb[0][i-1]>peb[2][i-1])
					{
						if(peb[0][i-1]>peb[3][i-1])
							max=peb[0][i-1];
						else
							max=peb[3][i-1];
					}
					else
					{
						if(peb[2][i-1]>peb[3][i-1])
							max=peb[2][i-1];
						else
							max=peb[3][i-1];
					}
					break;

				case 2:
					if(peb[0][i-1]>peb[1][i-1])
						max=peb[0][i-1];
					else
						max=peb[1][i-1];
					break;

				case 3:
					max=peb[1][i-1];
					break;
			}
			peb[p][i]+=max;
		}
	}


	max=peb[0][MAX-1];
	for(p=0; p<4; p++)
	{
		if(max<peb[p][MAX-1])
			max=peb[p][MAX-1];
	}

	for(p=0; p<4; p++)
	{
		for(i=0; i<MAX; i++)
			printf("%4d ",peb[p][i]);
		printf("\n");
	}
	printf("\n\n");


	for(i=0; i<4; i++)
	{
		if(max==peb[i][MAX-1])
			route[MAX-1]=i;
	}

	for(i=MAX-2; i>=0 ; i--)
	{
		switch(route[i+1])
		{
			case 0:
				if(peb[1][i]>peb[2][i])
					route[i]=1;
				else
					route[i]=2;
				break;

			case 1:
				if(peb[0][i]>peb[2][i])
				{
					if(peb[0][i]>peb[3][i])
						route[i]=0;
					else
						route[i]=3;
				}
				else
				{
					if(peb[2][i]>peb[3][i])
						route[i]=2;
					else
						route[i]=3;
				}
				break;

			case 2:
				if(peb[0][i]>peb[1][i])
					route[i]=0;
				else
					route[i]=1;

					break;

			case 3:
				route[i]=1;
				break;
		}
	}
	
	for(i=0; i<MAX; i++)
		printf("%d ",route[i]+1);
	printf("\n");


	printf("max %d\n",max);
}
