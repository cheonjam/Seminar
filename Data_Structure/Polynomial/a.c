#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode
{
	int coef;
	int degree;
	struct polyNoode* next;
}polyNode;

polyNode b;

int main()
{
	polyNode c;

	printf("%d\n",b.coef);
	printf("%d\n",b.degree);
	printf("%d\n",c.next);
}

