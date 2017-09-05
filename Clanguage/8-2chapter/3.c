#include <stdio.h>

int main()
{
	typedef int * p;
	typedef int INT;

	INT b=3;
	p a=&b;

	printf("%d\n",*a);
}
