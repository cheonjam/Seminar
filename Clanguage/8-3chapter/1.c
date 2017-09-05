#include <stdio.h>

int myStrlen(char *string);

int main()
{
	char str[100];
	int a,b;

	printf("Input string : ");
	scanf("%s",str);

	printf("String length : %d\n",myStrlen(str));

	return 0;
}
int myStrlen(char *string)
{
	int i;

	for(i=0;*(string+i)!='\0';i++)
		;

	return i;
}
