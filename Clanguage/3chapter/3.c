#include <stdio.h>

int main()
{
	double korean, english, math;
	
	printf("Insert of your Korean score :");
	scanf("%lf",&korean);
	printf("Insert of your English score :");
	scanf("%lf",&english);
	printf("Insert of your Math score :");
	scanf("%lf",&math);

	if(korean < 0 || english <0 || math <0)
		printf("Wrong Score!! (score>0)\n");
	else if(korean >100 || english >100 || math >100)
		printf("Wrong Score!! (Score<100)\n");
	else if(korean>=60 && english>=60 && math>=60 && (korean*math/3)>=70)
		printf("your pass!!\n");
	else
		printf("your not pass!!\n");
	
	return 0;
}

