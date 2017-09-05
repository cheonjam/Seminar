#include "head.h"

int exception(char *tmp)
{
	int initialize=1;
	char buffer;

	dot_exception(0,1);

	if(*tmp=='\0')
		return err_print("No fomula\n",'_');

	if(!char_parity(*tmp,".0123456789({+-!~"))
		return err_print("First operator error",'_');
	if(*tmp=='+' && *(tmp+1)!='+')
		return err_print("first plus error",'_');

	if(brackets_exception(*tmp,1,1))
		return -1;
	buffer=*tmp++;

	while(*tmp!='\0')
	{
		if(dot_exception(*tmp,0))
			return -1;

		if(brackets_exception(*tmp,1,0))
			return -1;

		if(operator_exception(buffer,*tmp, initialize))
			return -1;	

		buffer=*tmp++;
		initialize=0;
	}

	if(char_parity(buffer,"|^&<>=+-*/%~!"))
		return err_print("Final operator error",'_');

	if(brackets_exception(buffer,0,0))
		return -1;

}
