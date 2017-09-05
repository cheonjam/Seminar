#include <stdio.h>
#define SIZE 5

int main()
{
	int i;
	int buffer[SIZE];
	FILE *fp = NULL;

	fp= fopen("binary","rb");
	
	fread(buffer, sizeof(int), SIZE, fp);

	for(i=0; i<SIZE; i++)
		printf("%d ",buffer[i]);

	fclose(fp);
	return 0;
}	
