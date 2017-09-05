#include <stdio.h>
#include <string.h>

int myStrlen(char *string);
int myStrcmp(char *str2, char *str3);

int main()
{
	char str1[100], str2[100], str3[100];

	printf("Input String: ");
	scanf("%s",str1);

	printf("myStrlen : %d\n",myStrlen(str1));
	printf("strlen : %d\n",strlen(str1));	
	printf("==============================\n");
	printf("Input String1: ");
	scanf("%s",str2);
	printf("Input String2: ");
	scanf("%s",str3);		

	printf("myStrcmp : %d\n",myStrcmp(str2,str3));
	printf("strcmp : %d\n",strcmp(str2,str3));
	
	return 0;
}

int myStrlen(char *string)
{
	int i;

	for(i=0;*(string+i)!='\0';i++)
		;

	return i;
}
	
int myStrcmp(char *str2, char *str3)
{
	int i=0;
	
	while(1)
	{
		if(*(str2+i)=='\0' && *(str3+i)=='\0')
			return 0;
		
		else if(*(str2+i)>*(str3+i))
			return 1;
		
		else if(*(str2+i)<*(str3+i))
			return -1;

		else if(*(str2+i)==*(str3+i))
		{
			i++;
			continue;
		}
	}
}	
