#include <stdio.h>
#include <string.h>

int myStrlen(char *str)
{
	int i,count;

	for(i=0,count=0; str[i]; i++)	
		count++;

	return count;
}


void main()
{
	printf("[%d]\n",myStrlen("This"));
	printf("[%d]\n",myStrlen("This is"));
	printf("[%d]\n",myStrlen("This is test."));
}
