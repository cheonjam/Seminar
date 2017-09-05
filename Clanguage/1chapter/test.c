#include <stdio.h>

int main()
{
	double height = 0;
	char blood = 0;

	printf("insert of height & blood \n");
	scanf("%.2lf , %.c" , &height , &blood);
	printf(" %.2lf , %c ", height , blood);

	return 0;
}

