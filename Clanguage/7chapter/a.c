#include <stdio.h>

int Add(int i, int j);

int main()
{
	int result;
	result = Add(3,4);
	printf("%d",result);
}

int Add(int i, int j)
{
	int result = i + j;
	return result;
}
