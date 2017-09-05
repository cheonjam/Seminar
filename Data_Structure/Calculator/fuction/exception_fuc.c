#include "head.h" 

int dot_exception(char tmp, int initialize)
{
	static int dot_flag=0, dot_number=0;

	if(initialize)
	{
		dot_flag=0;
		dot_number=0;
	}

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

	return 0;
}

int brackets_exception(char tmp, int flag, int initialize)
{
	static int s_count=0, m_count=0 ;


	if(initialize) // initialize
	{
		s_count=0;
		m_count=0;
	}

	if(flag) // in a While
	{
		if(tmp=='(')
			s_count++;
		else if(tmp=='{')
		{
			if(s_count>0)
				return err_print("A small bracket is appear before a middle bracket.",'_');
			m_count++;
		}
		else if(tmp==')')
			s_count--;
		else if(tmp=='}')
		{
			m_count--;
			if(s_count>0 && m_count==0)
				return err_print("A middle bracket early close",'_');
		}
		
		if(s_count<0)
			return err_print("A close small bracket error.",'_');
	
		if(m_count<0)
			return err_print("A close middle bracket error.",'_');
	}	
	else // While end
	{
		if(s_count!=0)
			return err_print("The number of small brackets is not right.",'_');
		if(m_count!=0)
			return err_print("The number of middle brackets is not right.",'_');
	}

	return 0;
}

int operator_exception(char buffer, char tmp, int initialize)
{
	static int flag=0, minus_flag=0;

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
			if(tmp=='!')
				flag=1;
			else if(tmp=='-')
				minus_flag=1;
			else if(!char_parity(tmp,".0123456789|^&<>=+-*/%)}"))
				return err_print("num next error",'_');
			break;

		case '(':
		case '{':
			if(!char_parity(tmp,"0123456789({!~-+"))
				return err_print("bracket next error",'_');
			if(tmp=='+')
				flag=1;
			break;
		case ')':
		case '}':
			if(tmp=='!')
				flag=1;
			else if(!char_parity(tmp,"|^&<>=+-*/%)}"))
				return err_print("Close bracket next error",'_');
			break;

		case '+':
			if(flag)
			{
				if(tmp!='+')
					return err_print("is error",buffer);
			}

		case '-':
		case '&':
		case '|':
			if(minus_flag)
			{
				if(tmp=='-')
					return err_print("next error",buffer);
				minus_flag=0;
			}

			if(flag)
			{
				if(tmp==buffer)
					return err_print("operator many used",'_');
				else if(!char_parity(tmp,"0123456789({"))
					return err_print("next error",buffer);
				flag=0;
			}

			if(tmp==buffer)
				flag=1;
			else if(!char_parity(tmp,"0123456789({"))
				return err_print("next error",buffer);
			break;

		case '*':
		case '/':
		case '%':
		case '^':
		case '~':
			if(!char_parity(tmp,"0123456789({"))
				return err_print("next error",buffer);
			break;

		case '<':
		case '>':
			if(flag)
			{
				if(tmp==buffer)
					return err_print("operator many used",'_');
				else if(!char_parity(tmp,"0123456789({"))
					return err_print("next error",buffer);
				flag=0;
			}

			if(tmp==buffer || tmp=='=')
				flag=1;
			else if(!char_parity(tmp,"0123456789({"))
				return err_print("next error",buffer);
			break;
			
		case '!':
			if(flag && tmp!='=')
				return err_print("next error",buffer);
			else if(!char_parity(tmp,"0123456789({="))
				return err_print("next error",buffer);
			if(tmp=='=')
				flag=1;
			else
				flag=0;
			break;

		case '=':
			if(flag)
			{
				if(tmp=='=')
					return err_print("operator many used",'_');
				else if(!char_parity(tmp,"0123456789({"))
					return err_print("next error",buffer);
				flag=0;
			}
			else
			{
				if(tmp=='=')
					flag=1;
				else
					return err_print("next error",buffer);
			}
			break;


		default :
			return err_print("not operator\n",'_');
	}

	return 0;
}
