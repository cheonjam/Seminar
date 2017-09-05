#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	FILE * fp=fopen(argv[1],"r");
	char ch,word[100];
	int i=0,a=0;

	while(1)
	{
		fscanf(fp,"%s",word);
		if(feof(fp))
			break;
		if(!(a=strcmp(word,argv[2])))
			break;
	}
	
	if(!a)
		printf("string is exist!!\n");
	else
		printf("stirng isn't exist!! \n");

	fclose(fp);
}	
