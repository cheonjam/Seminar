#include <stdio.h>

unsigned setbits(unsigned int *x, unsigned p, unsigned n, unsigned v)
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

int getbits(int x, int p, int n)
{
	 return (x >> p-n+1) & ~(~0 << n);	
}

int main()
{
	int j,i,num,a;
j=0;
	while(1)
	{
		j=!j;
		printf("%d ",j);
	}
/*
	num=0;
	printf("num :%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n");
	
	num=~0;
	printf("~num:%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n");

	num=!0;
	printf("!num:%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",);
	}
	printf("\n\n");
	
	num=999999999999999999;
	printf("num :%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n");

	num=~14;
	num=~999999999999999999;
	printf("~num:%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n");

	num=!14;
	num=!999999999999999999;
	printf("!num:%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n\n");

	
	num=192;
	printf("num :%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n");

	num=~192;
	printf("~num:%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n");

	num=!192;
	printf("!num:%d\n",num);
	printf("getbits:");
	for(i=32;i>0;i--)
	{
		if(i%8==0)
			printf(" ");
		printf("%d",getbits(num,i,1));
	}
	printf("\n\n");
*/}
