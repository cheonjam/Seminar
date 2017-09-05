#include <stdio.h>

int main()
{
	int price ,credit;

	printf("price per crdit:");
	scanf("%d",&price);
	printf("apply for crdits:");
	scanf("%d",&credit);

	printf("A school fee:%d\n",price*credit);

	return 0;
}
