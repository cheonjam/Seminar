#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc!=2)
	{	
		printf("file name enterd one!\n");
		return -1;
	}

	FILE * fp=fopen(argv[1],"wt");
	char str[100];

	if(fp==NULL)
	{
		printf("file open error\n");
		return -1;
	}

	while(1)
	{
		puts("Input Strings:");
		fgets(str,100,stdin);
		fputs(str,fp);

		if(str[0]=='.')
			break;
		memset(str,0x00,sizeof(str));
	}

	fclose(fp);
	return 0;
}
