#include "head.h"

double operate(char *postfix, double *result)
{
	double op1,op2,double_stack[MAX_STACK_SIZE], tmp2;
	int i=0,count=0;
	char tmp[20],single_stack[MAX_STACK_SIZE];

	while(*postfix!='\0')
	{
		if( (*postfix>='0' && *postfix<='9') || *postfix=='.')
			tmp[i++]=*postfix;
		else if(*postfix==' ' && i>0)
		{
			double_stack[++top]=atof(tmp);
			memset(tmp,0,sizeof(tmp));
			i=0;

			if(count>0)
			{
				while(count!=0)
				{
					op1=double_stack[top--];
					if(single_oper(op1,single_stack[top--],&result))
						return -1;
					double_stack[++top]=*result;
					count--;
				}
			}
		}
		else if(*postfix!=' ')
		{
			if(*postfix=='P'||*postfix=='M'||*postfix=='!'||*postfix=='~')
			{
				single_stack[++top]=*postfix++;
				count++;			
				continue;
			}
			op2=double_stack[top--];
			op1=double_stack[top--];
			if(double_oper(op1,op2,*postfix,&result))
				return -1;
			double_stack[++top]=*result;
		
		}
		postfix++;
	}
	*result=double_stack[top];
	return 0;
}


double double_oper(double op1, double op2, char operator, double **result)
{
	switch(operator)
	{
		case 'O': 
			**result=(op1 || op2);
			break;
		case 'A':
		   	**result=(op1 && op2);
			break;
	
		case '|':
			if(op1!=(int)op1 || op2!=(int)op2)
				return err_print("invalide operands to binary",'_');
			**result= ((int)op1 | (int)op2);
			break;

		case '^':
			if(op1!=(int)op1 || op2!=(int)op2)
				return err_print("invalide operands to binary",'_');
			**result=((int)op1 ^ (int)op2);
			break;
		case '&':
			if(op1!=(int)op1 || op2!=(int)op2)
				return err_print("invalide operands to binary",'_');
			**result=((int)op1 & (int)op2);
			break;
		case 'S':
			**result=(op1 == op2);
			break;

		case 'D':
			**result=(op1 != op2);
			break;

		case '<':
			**result=(op1 < op2);
			break;

		case '>':
			**result=(op1 > op2);
			break;

		case 'X':
			**result=(op1 <= op2);
			break;

		case 'Z':
			**result=(op1 >= op2);
			break;

		case 'L':
			if(op1!=(int)op1 || op2!=(int)op2)
				return err_print("invalide operands to binary",'_');
			**result=((int)op1 << (int)op2);
			break;
		case 'R':
			if(op1!=(int)op1 || op2!=(int)op2)
				return err_print("invalide operands to binary",'_');
			**result=((int)op1 >> (int)op2);
			break;
		case '+':
			**result=(op1 + op2);
			break;

		case '-':
			**result=(op1 - op2);
			break;

		case '*':
			**result=(op1 * op2);
			break;

		case '/':
			if(op2 == 0)
				return err_print("Not divide by 0",'_');
			**result=(op1 / op2);
			break;

		case '%':
			if(op1!=(int)op1 || op2!=(int)op2)
				return err_print("invalide operands to binary",'_');
			else if(op2 == 0)
				return err_print("Not mod by 0",'_');
			**result=((int)op1 % (int)op2);
			break;
	}
	return 0;
}

double single_oper(double op1, char operator, double **result)
{
	switch(operator)
	{
		case '~':
			if(op1!=(int)op1)
				return err_print("wrong type argument to bit-complement",'_');
			**result=~((int)op1);
			break;
		case '!':
			**result=(!op1);
			break;
		case 'M':
			**result=(--op1);
			break;
		case 'P':
			**result=(++op1);
			break;
	}
	return 0;
}
