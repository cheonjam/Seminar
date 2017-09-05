#include "head.h"

BTreeNode* MakeTree(char *postfix)
{
	BTreeNode *stack[MAX], *pnode, *op1, *op2;
	char tmp[MAX];
	int i=0;

	top=-1;
	while(*postfix)
	{
		if(oper_check(*postfix)==NUM)
			tmp[i++]=*postfix;
		else if(*postfix==' ' && i>0)
		{
			pnode=MakeBTreeNode();
			pnode->data=atof(tmp);
			stack[++top]=pnode;

			memset(tmp,0,sizeof(tmp));
			i=0;
		}
		else
		{
			pnode=MakeBTreeNode();

			if(oper_check(*postfix)==DOUBLE)
			{
				pnode->oper=*postfix;
				pnode->right=stack[top--];
				pnode->left=stack[top--];

				stack[++top]=pnode;
			}
			else if(oper_check(*postfix)==SINGLE)
			{
				pnode->oper=*postfix;
				pnode->left=stack[top--];

				stack[++top]=pnode;
			}
		}
		postfix++;
	}

	return stack[top];
}

int oper_check(char token)
{
	switch(token)
	{
			case 'A':
			case 'O':
			case 'S':
			case 'D':
			case 'X':
			case 'Z':
			case 'L':
			case 'R':
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '&':
			case '|':
			case '^':
				return DOUBLE;
							
			case '!':
			case '~':
			case 'P':
			case 'M':
				return SINGLE;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '.':
				return NUM;
	}
}



				



