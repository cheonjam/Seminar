#include <stdio.h>

int main()
{
	FILE * file=fopen("test.txt","w");

	char ch;

	fputc('1',file);
	fputc('2',file);
	fputc((char)255,file);
	fputc('3',file);

	fclose(file);

	file=fopen("test.txt","r");

	while(1)
	{
		ch=fgetc(file);

		if(ch==-1)
			break;
		printf("%c \n",ch);
	}

	fclose(file);

	return 0;
}

