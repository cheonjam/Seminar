#include <stdio.h>
#include <string.h>

int main ()
{
/*	char name[] = "Cheon Jae Min";
	int length=0;

	length = strlen(name);
	printf("length = %d\n", length);

	-----------------------------------
*/
	int i;
	char str1[]="aabcdef" , str2[]="babcdef";
	i=strcmp(str1,str2);
	
	printf("%d\n",i);

//	---------------------------------

/*
	char str1[]="abcd", str2[]="efgh";

	strcat(str1,str2);

	printf("%s\n",str1);
	---------------------------------
*/
//	char name[20];
//	gets(name);
//	puts("puts!!!!!!!");

//
//---------------------------------
/*
	char name[20];

	printf("What your name : ");
	fgets(name,sizeof(name),stdin);
	fputs(name,stdout);
*/
	return 0;
}

