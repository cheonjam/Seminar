#include <stdio.h>

int deleteChar(char *str, char ch);

int main()
{
	char str[100],ch;
	int a;

	printf("Input string : ");
	scanf("%s",str);
	getchar();
	printf("delete Character : ");
	scanf("%c",&ch);

	if(!(a=deleteChar(str, ch)))
		printf("%s\n",str);
	else 
		printf("Not find delete Character\n");
	printf("return : %d\n",a);
	return 0;
}

int deleteChar(char *str, char ch)
{
	int i,j;

	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==ch)
		{
			for(j=i;str[j]!='\0';j++)
				str[j]=str[j+1];

			return 0;
		}
	}
	return -1;
}

