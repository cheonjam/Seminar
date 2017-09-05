#include "head.h"

void binary_change(char *enc)
{
	FILE *org_fp=fopen(enc,"r");
	FILE *bin_fp=fopen("binary","w");

	int i;
	char c;

	while(1)
	{
		if((fscanf(org_fp,"%c",&c))==EOF)
			break;

		for(i=7;i>=0;i--)
			fprintf(bin_fp,"%d",getbits(c,i,1));//bit.c
	}

	fclose(org_fp);
	fclose(bin_fp);
}

