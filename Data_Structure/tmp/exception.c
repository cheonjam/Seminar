#include "head.h"

int exception(char *tmp, char *fomula)
{
	int bracket=1, expo=0;

	while(*fomula==' ')
		fomula++;

	if(*fomula=='\0')
		return err_print("No fomula\n");

	if(*fomula!='(')
		return err_print("Starting Fomula is only '('\n");
	*tmp=*fomula++;

	while(*fomula)
	{
		if(*fomula==' ')
		{
			fomula++;
			continue;
		}
		
		if(*fomula =='(')
			bracket++;
		if(*fomula ==')')
			bracket--;

		switch(*tmp)
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
				if(!char_parity(*fomula,".0123456789x)+-")&&!expo)
					return err_print("num next error");
				if(!char_parity(*fomula,"0123456789x)+-")&&expo)
					return err_print("num next error");
				break;
			case 'x' :
				if(!char_parity(*fomula,"^)+-"))
					return err_print("'x' next error");
				break;
		
			case '^' :
				expo=1;
				if(!char_parity(*fomula,"123456789"))
					return err_print("'^' next error");
				break;
	
			case '(' :
				if(!char_parity(*fomula,"012346789-x)"))
					return err_print("open bracket next error");
				break;
	
			case ')' :
				expo=0;
				if(!char_parity(*fomula,"+-*"))
					return err_print("close bracekt next error");
				break;
				
			case '+' :
				expo=0;
				if(!char_parity(*fomula,"0123456789x("))
					return err_print("'+' next error");
				break;
	
			case '-' :
				expo=0;
				if(!char_parity(*fomula,"0123456789x("))
						return err_print("'-' next error");
				break;
	
			case '*' :
				expo=0;
				if(!char_parity(*fomula,"012345789x("))
					return err_print("'*' next error");
				break;
		
			default :
				return err_print("not operator\n");
		}

		if(bracket<0 || bracket >2)
			return err_print("bracket error");

		*++tmp=*fomula++;
	}
	return 0;
}
