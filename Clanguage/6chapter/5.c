#include <stdio.h>
#include <string.h>
int main()
{
	char word[100];
	char *a=word;
	int i;	

	printf("Input word : ");
	scanf("%s",word);

	printf("%s\n",word);

	for(i=strlen(a);i>=0;i--)
		printf("%c",*(a+i));

	printf("\n");

	return 0;
}
