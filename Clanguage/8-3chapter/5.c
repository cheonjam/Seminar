#include <stdio.h>
#include <string.h>

void reverse(char *str);

int main()
{
	char str[100];

	printf("Input string : ");
	scanf("%s",str);

	reverse(str);
	printf("%s\n",str);

	return 0;
}

void reverse(char *str)
{
	int i;
	char Newstr[100]={};

	for(i=0;str[i]!='\0';i++)
		Newstr[i]=str[strlen(str)-(i+1)];

	Newstr[i]='\0';

	strcpy(str,Newstr);	
//	for(i=0;Newstr[i]!='\0';i++)
//		str[i]=Newstr[i];
}

