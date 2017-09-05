#include <stdio.h>

int main()
{
	int score[10]={60 , 10 , 20 , 40 , 50 , 89 , 100 , 20 , 75};
	int sum=0, i;
	
	for(i=0;i<10;i++)
		sum += score[i];
	

	printf("Avarage : %d \n",sum/10);

	return 0;
}

