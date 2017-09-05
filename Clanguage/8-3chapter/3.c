#include <stdio.h>
#include <string.h>

int changeChar(char *str, int i, char ch);

int main()
{
	char str[100],ch;
	int i;

	printf("Input string : ");
	scanf("%s",str);
	printf("Change number : ");
	scanf("%d",&i);
	getchar();
	printf("Change Character : ");
	scanf("%c",&ch);

	if(!changeChar(str,i,ch))
		printf("%s\n",str);
	else 
		printf("Number higher than string length!!\n");

	return 0;
}

int changeChar(char *str, int i, char ch)
{
	if(strlen(str)>=i)	
	{
		str[i-1]=ch;
		return 0;
	}
	
	return -1;
}
