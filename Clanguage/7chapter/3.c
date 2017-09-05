#include <stdio.h>
#include <stdlib.h>
int Credits(int i);

int main()
{
	int result,score;

	printf("Input your score : ");
	scanf("%d",&score);
	result=Credits(score);

	printf("=======================\n");
	printf("100 >= Score >= 90 : A\n");
	printf("90 > Score >= 80   : B\n");
	printf("80 > Score >= 70   : C\n");
	printf("70 > Score >= 60   : D\n");
	printf("60 > Score         : F\n");
	printf("=======================\n");

	if(result==0)
		printf("Incorrect Score (0 < score <=100)\n");
	else
		printf("Your credits : %c\n",result);
	
	return 0;
}

int Credits(int i)
{
	int result;
	if(i>100 || i< 0)
		result = 0;
	else if(i<=100 && i>=90)
		result= 'A';
	else if(i<90 && i>=80)
		result= 'B';
	else if(i<80 && i>=70)
		result= 'C';
	else if(i<70 && i>=60)
		result= 'D';
	else if(i<60)
		result= 'F';

	return result;
}
	
