#include "head.h"

char type0(unsigned char first, unsigned char s)
{
	int i;

	setbits(&first,6,6,s); // bit.c

	same=1;diff=0; // initialize type0 

	return first;

}
							
char type1(unsigned char first, unsigned char d)
{
	char c=0;
	int i,j,a;

	setbits(&c,7,1,1);

	for(i=6;i>=0;i--)
	{
		setbits(&c,i,1,first);
		if(d>1)
		{
			d--;
			first=negative(first);
		}
	}

	if(diff==6)
	{
		same=1;diff=0; // diff==6 initialize
	}
	else
	{
		same=2;diff=0; // initialize type1
	}
	
	return c;
}

