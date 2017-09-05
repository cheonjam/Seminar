#include <stdio.h>

int main(void)
{
	double korean , english;
	
	printf("Insert of Koerean Score : ");
	scanf(" %lf", &korean);

	printf("Insert of English Score : ");
	scanf(" %lf", &english);

	
	printf("Everage of Korean Score & English Score : %.2lf  \n", (korean+english)/2);

	return 0;
}

