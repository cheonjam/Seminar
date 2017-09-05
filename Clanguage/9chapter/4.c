#include <stdio.h>

int main(int argc, char * argv[])
{
	FILE * fp=fopen(argv[1],"rt");
	FILE * fc=fopen(argv[2],"wt");

	int ch;

	if(fp==NULL || fc==NULL)
	{
		puts("File open error!!");
		return -1;
	}

	while((ch=fgetc(fp))!=EOF)
		fputc(ch, fc);

	fclose(fp);
	fclose(fc);

	return 0;
}
