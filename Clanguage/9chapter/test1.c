#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *pc=(char *)malloc(100*sizeof(char));
	int i;
	memset(pc,0,100*sizeof(char));

	for(i=0;i<26;i++)
	{
		pc[i]='a'+i;
	}

	pc[i]=0;

	printf("%s\n",pc);

	free(pc);
	sleep(10);
	printf("\n");
	printf("%s\n",pc);

	return 0;
}
