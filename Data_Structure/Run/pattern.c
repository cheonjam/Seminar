#include "head.h"

char enc_pattern(int prev, int next, char first, char now_char)
{
	if(now_char==EOF)
	{
		if(same>=2)
			return type0(first,same);
		else
			return type1(first,++diff);
	}// File end encoding 

	if(prev==next)
	{
		same++;
		if(same==64)
			return type0(first,--same);

		if(diff>=1)
			return type1(first,diff);
	}
	else
	{
		diff++;
		if(diff==6)
			return type1(first,diff);

		if(same>=2)
			return type0(first,same);
	}
	return 0;
}
