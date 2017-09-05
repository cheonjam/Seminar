#include <stdio.h>

int findChar(char *str, char ch);

int main()
{
	char str[100],ch;

	printf("Input string : ");
	scanf("%s",str);
	getchar();
	printf("Find Character : ");
	scanf("%c",&ch);

	printf("return : %d\n",findChar(str,ch));

	return 0;
}

int findChar(char *str, char ch)
{
	int i;

	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==ch)
		{
			printf("Find character is the %d times\n",i+1);
			return 4;
		}
	}
	return -1;
}
