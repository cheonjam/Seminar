#include "head.h"

void Menual()
{
	printf("===========MENUAL===========\n");
	printf("menu\n");
	printf("============================\n");
}

int err_print(char *err_str , char tmp)
{
	if(tmp=='_')
		fprintf(stderr,"   \033[31merror:\033[0m %s\n",err_str);
	else
		fprintf(stderr,"   \033[31merror:\033[0m  \033[33m'%c' \033[0m %s\n",tmp,err_str);
	return -1;
}

int char_parity(char tmp, char *ok_char)
{
	while(*ok_char!='\0')
	{
		if(tmp == *ok_char)
			return 1;
	
		ok_char++;
	}
	
	return 0;
}

void Delete_Space(char *infix, char *tmp)
{
	for(;*infix!='\0';infix++)
	{
		if(*infix!=' ')
			*tmp++=*infix;
	}
	*tmp=0;
}
