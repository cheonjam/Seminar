#include <stdio.h>
#include <string.h>

int main()
{
	char a[4]="ABC", b[4]="abc";
	int i;

	i=strcmp(a,b);
	printf("%d\n",i);

	return 0;
}
