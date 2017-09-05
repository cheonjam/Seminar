#include "head.h"

void postfix(char *init_fomula)
{
	char stack[MAX],tmp[MAX];
	char *fomula=init_fomula;
	int top=-1,i=0;

	while(*fomula)
	{
		if(*fomula=='(')
		{
			while(*fomula!=')')
				tmp[i++]=*fomula++;
			tmp[i++]=*fomula;
		}
		else if(char_parity(*fomula,"+-*"))
		{
//			tmp[i++]=' ';
			if(top==-1)
				stack[++top]=*fomula;
			else
			{
				while(1)
				{
					if(priority(*fomula)>priority(stack[top]))
					{
						stack[++top]=*fomula;
						break;
					}
					else
						tmp[i++]=stack[top--];
				}
			}
		}
		fomula++;
	}
		
	while(top!=-1)
	{
//		tmp[i++]=' ';
		tmp[i++]=stack[top--];
	}
	tmp[i]='\0';
	strcpy(init_fomula,tmp);
}	

int priority(char token)
{
	switch(token)
	{
		case '+':
		case '-':
			return 1;
			
		case'*':
			return 2;
			
		default:
			return -1;
	}
}
