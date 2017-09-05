#include "head.h"

void set(char *fomula, polyNode *array)
{
	int ceof_flag=1, expo_flag=0, minus_flag=0, i=0;
	static char ceof[MAX],expo[MAX];

	for(;*fomula!='\0';fomula++)
	{
		if(char_parity(*fomula,"0123456789."))
		{
			if(ceof_flag)
				ceof[i++]=*fomula;
			else
				expo[i++]=*fomula;
		}

		else if(ceof_flag && char_parity(*fomula,"x"))
		{
			if(i==0)
				*ceof=1;
			ceof_flag=0;
			i=0;
		}

		else if(char_parity(*fomula,"^"))		
			expo_flag=1;

		else if(char_parity(*fomula,"+-"))
		{
			if(*fomula=='-' && !ceof[0])
			{
				minus_flag=1;
				continue;
			}

			if(minus_flag)
				addPolyNode(array,-atof(ceof),atoi(expo));
			else
				addPolyNode(array,atof(ceof),atoi(expo));

			expo_flag=0;
			ceof_flag=1;
			if(*fomula=='+')
				minus_flag=0;
		}
	}
}
