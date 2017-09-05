#include "head.h"

void change(char *tmp, char *postfix)
{
	char pop_char;
	char char_stack[MAX_STACK_SIZE];

	while(*tmp!='\0')
	{
		/*operand*/
		if(*tmp >= '0' && *tmp <= '9' || *tmp == '.')
			*postfix++=*tmp;
		/*single operator*/
		else if(*tmp =='P' || *tmp =='M' || *tmp =='~' || *tmp=='!')
			*postfix++=*tmp;
		/*operator*/
		else
		{
			/*stack is empty or '('*/
			if(top==-1 || *tmp=='(' || *tmp=='{')
			{
				if(*tmp!='(' && *tmp != '{')
					*postfix++=' ';
				push(char_stack,*tmp);
				tmp++;
				continue;
			}
			if(*tmp==')')
			{
				while(1)
				{
					if((pop_char=pop(char_stack))=='(')
						break;
					*postfix++=' ';
					*postfix++=pop_char;
				}
			}

			else if(*tmp=='}')
			{
				while(1)
				{
					if((pop_char=pop(char_stack))=='{')
						break;
					*postfix++=' ';
					*postfix++=pop_char;
				}
			}
			else
			{	
				while(1)
				{
					*postfix++=' ';
					if(priority(*tmp)>priority(char_stack[top]))
					{
						push(char_stack,*tmp);
						break;
					}
					else
						*postfix++=pop(char_stack);
				}
			}

		}
		tmp++;
	 }

	while(top!=-1)
	{
		*postfix++=' ';
		*postfix++=pop(char_stack);
	}

	*postfix++=' ';
	*postfix='\0';
}

int priority(char token)
{
	switch(token)
	{
		case '(':
			return 0;

		case '{':
			return 1;

		case 'O':
			return 4;

		case 'A':
			return 5;

		case '|':
			return 6;
		
		case '^':
			return 7;
		
		case '&':
			return 8;

		case 'S':
		case 'D':
			return 9;

		case '<':
		case '>':
		case 'X':
		case 'Z':
			return 10;

		case 'L':
		case 'R':
			return 11;

		case '+':
		case '-':
			return 12;

		case '*':
		case '/':
		case '%':
			return 13;

		case 'N':
		case '~':
		case '!':
		case 'P':
		case 'M':
			return 15;
	}
}

/*
 *	|| = O
 *	&& = A
 *	== = S
 *	!= = D
 *	<= = X
 *	>= = Z
 *	<< = L
 *	>> = R
 *	(-A) = N
 *	-- = P
 *	++ = M
 */
