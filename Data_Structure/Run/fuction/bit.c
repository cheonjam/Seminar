#include "head.h"

unsigned setbits(unsigned char *x, unsigned p, unsigned n, unsigned v)
{
	if((p+1)<n)
	{
		printf("error!!( n > p+1)\n");
		return 0;
	}
	else if(~(~0<<n) < v)
	{
		printf("error!!( v > n )\n");
		return 0;
	}

	*x = (*x & (~(~0 << p-n+1))) | (*x & (~0 << p+1)) | ((v & ~(~0 <<n))<<p-n+1);
}

unsigned char getbits(unsigned char x, int p, int n)
{
	 return (x >> p-n+1) & ~(~0 << n);	
}
