#include <stdio.h>

int main()
{
	int i , j ;
	char chr[]="It is useful Where a statement Is needed sYntactically, but no action is reQUired";

	
	for( i=0; chr[i]!='\0';i++ )
	{
		if(chr[i]==' ')
		{
			chr[i]=chr[i+1];
			for(j=i+1;chr[j]!='\0';j++)
				chr[j]=chr[j+1];
		}
	}

	printf("%s\n",chr);

	return 0;
}
