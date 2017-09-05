#include <stdio.h>

int main(int argc, char * argv[])
{
	FILE * fp=fopen(argv[1],"rt");

	char ch;

	if(fp==NULL)
	{
		puts("File open error!!");
		return -1;
	}

	while((ch=fgetc(fp))!=EOF)
		fputc(ch, stdout);

	fclose(fp);

	return 0;
}
