#include <stdio.h>

int main()
{
	int i , j, k;
	char chr[]="It is useful Where a statement Is needed sYntactically, but no action is reQUired";

	
	for(i=0; chr[i]!='\0';i++)
	{
		if(chr[i]==' ')
		{
			for(j=i;chr[j]!='\0';j++)
				chr[j]=chr[j+1];	
		}
	}
	chr[i]='\0';
	printf("%s\n",chr);

	return 0;
}

