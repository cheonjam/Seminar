#include <stdio.h>
#include <ctype.h>

int main()
{
	char a1=9, a2='c', a3='A';
	int result1, result2, result3;

	result1=isalnum(a1);
	result2=isupper(a2);
	result3=islower(a3);

	printf("%d %d %d \n", result1, result2, result3);

	return 0;
}	
