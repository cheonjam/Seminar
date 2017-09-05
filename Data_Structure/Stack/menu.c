#include "head.h"

int menu()
{
	int num;

	printf("=======MENU=========\n");
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.exit\n");
	printf("====================\n");
	printf("Choice number : ");
	scanf("%d",&num);
	getchar();

	return num;
}
