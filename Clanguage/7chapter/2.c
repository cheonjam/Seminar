#include <stdio.h>
#include <stdlib.h>
#define phi 3.141592

double cir(double rad);

int main()
{
	double result;
	int rad;
	printf("Input radious : ");
	scanf("%d",&rad);

	if(rad<0)
		printf("Incorrect radious !!\n");

	result = cir(rad);

	printf("The extent of circle : %lf\n",result);
	return 0;
}

double cir(double rad)
{
	return rad * rad * phi; 
}
