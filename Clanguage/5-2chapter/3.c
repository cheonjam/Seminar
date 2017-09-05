#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i;
    char chr[]="It is useful Where a statement Is needed sYntactically, but no action is reQUired";
	
/*	for(i=0;chr[i]!='\0';i++)
	{
		if(chr[i]>='A'&&chr[i]<='Z')
			chr[i]+=32;
		else if(chr[i]>='a'&&chr[i]<='z')
			chr[i]-=32;
		putchar(chr[i]);
	}
	printf("\n");
*/
	for(i=0;chr[i]!='\0';i++)
	{
		if(chr[i]>='A'&&chr[i]<='Z')
			chr[i]=tolower(chr[i]);
		else if((chr[i]>='a')&&(chr[i]<='z'))
			chr[i]=toupper(chr[i]);
		putchar(chr[i]);
	}
	printf("\n");

	return 0;
}


