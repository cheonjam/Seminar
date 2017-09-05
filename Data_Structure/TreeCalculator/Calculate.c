#include "head.h"

double Calculate(BTreeNode *bt, int* exep)
{
	double op1,op2;

	if(*exep==-1)
		return -1;

	if(!bt->oper)
		return bt->data;

	op1=Calculate(bt->left, exep);

	if(oper_check(bt->oper)==DOUBLE)
	{
		op2=Calculate(bt->right,exep);
		return double_cal(op1,op2,bt->oper,&exep);
	}
	else if(oper_check(bt->oper)==SINGLE)
		return single_cal(op1,bt->oper,&exep);

}

double single_cal(double op1, char oper, int **exep)
{
		switch(oper)
		{
			case '~':
				if(op1!=(int)op1)
				{
					**exep=-1;
					return err_print("wrong type argument to bit-complement",'_');
				}
				return ~(int)op1;

			case '!':
				return !op1;

			case 'M':
				return --op1;

			case 'P':
				return ++op1;
		}
}
	
double double_cal(double op1, double op2, char oper, int **exep)
{
		
		switch(oper)
		{
			case '+':
				return op1+op2;
				
			case '-':
				return op1-op2;

			case '*':
				return op1*op2;

			case '/':
				if(!op2)
				{
					**exep=-1;
					return err_print("Not divide by 0",'_');
				}
				return op1/op2;

			case '%':
				if(op1!=(int)op1 || op2!=(int)op2)
				{
					**exep=-1;
					return err_print("invlaide operands to binary",'_');
				}
				return (int)op1%(int)op2;

			case 'O':
				return op1||op2;

			case 'A':
				return op1&&op2;

			case '|':
				if(op1!=(int)op1 || op2!=(int)op2)
				{
					**exep=-1;
					return err_print("invlaide operands to binary",'_');
				}
				return (int)op1|(int)op2;

			case '^':
				if(op1!=(int)op1 || op2!=(int)op2)
				{
					**exep=-1;
					return err_print("invlaide operands to binary",'_');
				}
				return (int)op1^(int)op2;

			case '&':
				if(op1!=(int)op1 || op2!=(int)op2)
				{
					**exep=-1;
					return err_print("invlaide operands to binary",'_');
				}
				return (int)op1&(int)op2;

			case 'S':
				return op1==op2;

			case 'D':
				return op1!=op2;

			case '<':
				return op1<op2;

			case '>':
				return op1>op2;

			case 'X':
				return op1<=op2;

			case 'Z':
				return op1>=op2;

			case 'L':
				if(op1!=(int)op1 || op2!=(int)op2)
				{
					**exep=-1;
					return err_print("invlaide operands to binary",'_');
				}
				return (int)op1<<(int)op2;

			case 'R':
				if(op1!=(int)op1 || op2!=(int)op2)
				{
					**exep=-1;
					return err_print("invlaide operands to binary",'_');
				}
				return (int)op1>>(int)op2;
		}
}
