#include <stdio.h>

int main()
{
	int score ;

	printf("Insert of you score :");
	scanf("%d",&score);
	if(score>100)
		printf("Score < 100 !!\n");
	else if(score<0)
		printf("Score > 0 !!\n");
	else if(score>=90)
		printf("A\n");
	else if(score>=80)
		printf("B\n");
	else if(score>=70)
		printf("C\n");
	else if(score>=60)
		printf("D\n");
	else
		printf("F\n");
	
	return 0;
}

