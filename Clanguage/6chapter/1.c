#include <stdio.h>

int main()
{
	int *p, q;

	q=3;
	printf("%d\n",q);

	p=&q;
	printf("%x\n",p);
	printf("%x\n",&q);
	printf("%d\n",*p);

	*p=*p*3;
	printf("%d\n",*p);

	*p=*p*q;
	printf("%d\n",*p);

	return 0;

}
