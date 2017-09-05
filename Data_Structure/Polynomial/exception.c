#include "head.h"

int exception(char *tmp)
{
	int initialize=1;
	char buffer;

	if(*tmp=='\0')
		return err_print("No fomula\n");

	if(!char_parity(*tmp,"0123456789(x-"))
		return err_print("First operator error");

	if(dot_bracket_exception(*tmp,1))
		return -1;
	buffer=*tmp++;

	while(*tmp!='\0')
	{
		if(dot_bracket_exception(*tmp,1,0))
			return -1;

		if(operator_exception(buffer,*tmp, initialize))
			return -1;	

		buffer=*tmp++;
		initialize=0;
	}

	if(!char_parity(buffer,"0123456789x)"))
		return err_print("Final operator error");

	if(dot_bracket_exception(buffer,-1))
		return -1;

}

int operator_exception(char buffer, char tmp, int initialize)
{
	static int flag=0;

	if(initialize)
		flag=0;

	switch(buffer)
	{
		case '0' :
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' :
		case '.' :
			if(!char_parity(tmp,".0123456789x)+-*/"))
				return err_print("num next error");
			break;

		case 'x' :
			if(!char_parity(tmp,"^)+-*/"))
				return err_print("'x' next error");
			break;

		case '^' :
			if(!char_parity(tmp,"0123456789-"))
				return err_print("'^' next error");
			break;

		case '(' :
			if(!char_parity(tmp,"0123456789(-x"))
				return err_print("open bracket next error");
			break;

		case ')' :
			if(!char_parity(tmp,"+-*/"))
				return err_print("Close bracket next error");
			break;

		case '+' :
			if(!char_parity(tmp,"0123456789x("))
				return err_print("'+' next error");
			break;
			
		case '-' :
			if(!char_parity(tmp,"0123456789x("))
				return err_print("'-' next error");
			break;

		case '*':
			if(!char_parity(tmp,"0123456789x("))
				return err_print("'-' next error");
			break;

		case '/':
			if(!char_parity(tmp,"0123456789x("))
				return err_print("'-' next error");
			break;

		default :
			return err_print("not operator\n",'_');
	}

	return 0;
}


int dot_bracket_exception(char tmp, int initialize)
{
	static int dot_flag=0, dot_number=0, s_count=0;

	if(initialize==1)
	{
		dot_flag=0;
		dot_number=0;
		s_count=0;
	}

	else if(initialize==0)
	{
		if(char_parity(tmp,".123456789"))
			dot_flag=1;
		else
			dot_flag=0;
	
		if(dot_flag)
		{
			if(tmp=='.')
				dot_number++;
			if(dot_number>1)
				return err_print("dot number error",'_');
		}
		else
			dot_number=0;

		if(tmp=='(')
			s_count++;
		else if(tmp==')')
			s_count--;

		if(s_count<0)
			return err_print("A close small bracket error.");
	}
	else if(initialize==-1)
	{
		if(s_count!=0)
			return err_print("The number of small brackets is not right");
	}

	return 0;
}
