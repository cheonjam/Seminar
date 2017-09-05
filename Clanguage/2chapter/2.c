#include <stdio.h>

int main()
{
	double Midscore , Finscore;
	
	printf("insert of Midscore :");
	scanf("%lf",&Midscore);
	printf("insert of Finscore :");
	scanf("%lf",&Finscore);
	printf("Everage of score : %.2lf \n",(Midscore+Finscore)/2);

	return 0;
}
