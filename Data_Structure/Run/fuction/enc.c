#include "head.h"

void Encoding(char *save)
{
	FILE *bin_fp=fopen("binary","r");
	FILE *enc_fp=fopen(save,"w");

	char new_char,now_char,first=-1;
	int now,prev,i=1;
	
	same=1;diff=0;

	while(1)
	{
		now_char=fgetc(bin_fp);
		now=ctoi(now_char); // Character -> integer 

		if(first==-1)
			first=now;
		else
		{	
			new_char=enc_pattern(prev,now,first,now_char);
			if(new_char)
			{
				fprintf(enc_fp,"%c",new_char);
				first=now;
			}
		}
		prev=now;

		if(now_char==EOF)
			break;
		if(now_char=='\n')
			break;
	}

	fclose(bin_fp);
	fclose(enc_fp);
}
