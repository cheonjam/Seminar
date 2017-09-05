#include "head.h"

void set(char* infix)
{
	int i,j=0,neg_flag=0;
	char char_stack[MAX],tmp[MAX];

	if(infix[0]=='-' && char_parity(infix[1],".0123456789({"))
		tmp[j++]='0';

	for(i=0;infix[i+1]!='\0';i++)
	{
		if(neg_flag)
		{
			if(infix[i+1]!='-')
			{
				tmp[j++]='0';
			}
			neg_flag=0;
		}

		if((infix[i]=='(' || infix[i]=='{') && infix[i+1]=='-')
			neg_flag=1;
		if(infix[i]=='&' && infix[i+1]=='&')
		{
			tmp[j++]='A';
			i++;
			continue;
		}
		if(infix[i]=='|' && infix[i+1]=='|')
		{
			tmp[j++]='O';
			i++;
			continue;
		}
		if(infix[i]=='=' && infix[i+1]=='=')
		{
			tmp[j++]='S';
			i++;
			continue;
		}
		if(infix[i]=='!' && infix[i+1]=='=')
		{
			tmp[j++]='D';
			i++;
			continue;
		}
		if(infix[i]=='<' && infix[i+1]=='=')
		{
			tmp[j++]='X';
			i++;
			continue;
		}
		if(infix[i]=='>' && infix[i+1]=='=')
		{
			tmp[j++]='Z';
			i++;
			continue;
		}
		if(infix[i]=='<' && infix[i+1]=='<')
		{
			tmp[j++]='L';
			i++;
			continue;
		}
		if(infix[i]=='>' && infix[i+1]=='>')
		{
			tmp[j++]='R';
			i++;
			continue;
		}
		if(infix[i]=='+' && infix[i+1]=='+')
		{
			tmp[j++]='P';
			i++;
			continue;
		}
		if(infix[i]=='-' && infix[i+1]=='-')
		{
			tmp[j++]='M';
			i++;
			continue;
		}
	
		tmp[j++]=infix[i];
	}
	tmp[j++]=infix[i];
	tmp[j]='\0';
	memset(infix,'\0',sizeof(infix));
	strcpy(infix,tmp);
}
