#include <stdio.h>

int mySumAscii(char *str)
{
	int count=0;

	for(count=0; *str; str++)
		count+=*str;

	return count;
}

void main()
{
	printf("[%d]\n",mySumAscii("A"));
	printf("[%d]\n",mySumAscii("ABC"));
	printf("[%d]\n",mySumAscii("ABCDE"));
}
