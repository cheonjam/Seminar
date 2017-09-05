#include <stdio.h>
#include <ctype.h>

void Reverse(char *argv, int argc);
void change(char **argv, int argc);

int main(int argc, char *argv[])
{
	int i;
	change(&argv[1],argc);
//	Reverse(*argv,argc);
	for(i=0;i<argc;i++)
		printf("%s",argv[i]);
}

void change(char **argv, int argc)
{
		
}
