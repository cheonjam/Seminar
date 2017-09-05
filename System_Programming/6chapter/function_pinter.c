#include <stdio.h>

int myfunction(char *name)
{
	printf("\t-->[%s]\n",name);
	return(123);
}

void main()
{
	int i;
	int (*fp)(char *);

	fp=myfunction;
	i=(*fp)("This");
	printf("%d\n",i);
}
