#include <stdio.h>

void myEnc(char *str);
void myDec(char *str);

int main()
{
	char str[100];

	printf("Input String : ");
	scanf("%s",str);

	myEnc(str);

	printf("Encoding String : %s\n",str);

	myDec(str);

	printf("Decoding String : %s\n",str);

	return 0;
}

void myEnc(char *str)
{
	int i;
	
	for(i=0;str[i]!='\0';i++)
		str[i]+=3;
}

void myDec(char *str)
{
	int i;
	
	for(i=0;str[i]!='\0';i++)
		str[i]-=3;
}

