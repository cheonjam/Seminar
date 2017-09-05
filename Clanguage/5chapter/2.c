#include <stdio.h>

int main()
{
	int std[5][3];
	int i,j,Average[5];
	int Max,Min;

	for(i=0;i<5;i++)
	{		
		printf("Student%d Number , Korean score , Eglish Score(sequence input)\n",i+1);

		for(j=0;j<3;j++)
		{
			printf("Student%d: ",i+1);
			scanf("%d",&std[i][j]);
		}
	}

	for(i=0;i<5;i++)
	{
		Average[i]=(std[i][1]+std[i][2])/2;
		printf("<Student%d>\tNumber:%d\tKorean:%d\tEnglish:%d\tAverage Score:%d\n",i+1,std[i][0],std[i][1],std[i][2],Average[i]);
	}

	Max=Average[0];
	Min=Average[0];
	

	for(i=0;i<5;i++)
	{
		if(Average[i]>Max)
			Max=Average[i];
		if(Average[i]<Min)
			Min=Average[i];
	}
	
	printf("Max Score:%d\n",Max);
	printf("Min Score:%d\n",Min);
		
	return 0;
}
