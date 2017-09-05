#include "head.h"

void set(char *fomula, polyNode **array)
{
	int state=STATE_COEF,i=0;
	char coef[MAX]={}, expo[MAX]={};

//	printf("set fomula:%s\n",fomula);

	for(;*fomula!='\0';fomula++)
	{
		switch(state)
		{
			case STATE_COEF: // coef state
				if(char_parity(*fomula,"0123456789."))
					coef[i++]=*fomula;
				else if(char_parity(*fomula,"x"))
				{
					if(coef[0]=='\0' || (coef[0]=='-'&&coef[1]=='\0'))
						coef[i++]='1';
					state=STATE_EXPO;
					i=0;
				}
				break;

			case STATE_EXPO: // expo state
				if(char_parity(*fomula,"^"))
					fomula++;

				if(char_parity(*fomula,"012345789"))
					expo[i++]=*fomula;
				break;
		}
		
	   	if(char_parity(*fomula,"+-)"))
		{
//				printf("*fomula%c\n",*fomula);
			if(coef[0]=='\0' && *fomula=='-')
			{
				coef[i++]='-';
				continue;
			}

			if(expo[0]=='\0')
			{
				if(state==STATE_EXPO)
					expo[0]='1';
				else
					expo[0]='0';
			}

			addPolyNode(array,atof(coef),atoi(expo));
			memset(coef,'\0',sizeof(coef));
			memset(expo,'\0',sizeof(expo));
			state=STATE_COEF;
			i=0;
			
			if(*fomula=='-')
				coef[i++]='-';
		}
	}

//	for(p=array;p;p=p->next)
//		printf("[%f] [%d] \n",p->coef,p->expo);
}
