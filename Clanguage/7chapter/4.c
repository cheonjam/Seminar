#include <stdio.h>

int second(int hour, int min, int sec);

int main()
{
	int result, hour, min, sec;

	printf("Input Hour : ");
	scanf("%d",&hour);
	printf("Input Minute : ");
	scanf("%d",&min);
	printf("Input Second : ");
	scanf("%d",&sec);

	result = second(hour, min, sec);
	printf("%d(sec)\n",result);

	return 0;
}

int second(int hour, int min, int sec)
{
	int result;
	result = (hour * 3600) + (min * 60) + sec ;
	return result;
}

