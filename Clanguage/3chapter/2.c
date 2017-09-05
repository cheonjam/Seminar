#include <stdio.h>

int main()
{
	double a, b;

	printf("First number : ");
	scanf("%lf",&a);
	printf("Second number : ");
	scanf("%lf",&b);

	if(a>b)
		printf("A high number : %.lf\n",a);
	else
		printf("A high number : %.lf\n",b);
	
	return 0;
}

