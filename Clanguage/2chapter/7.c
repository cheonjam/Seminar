#include <stdio.h>

int main()
{
	double height;


	printf("Insert of height (centimeter) : ");
	scanf("%lf",&height);
	
	printf("(height - 100) * 0.9 = %lf\n",(height-100)*0.9);
	
	return 0;
}

