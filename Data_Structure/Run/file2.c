#include "head.h"

void character_change(char *save)
{
	FILE *new_fp=fopen("binary2","r");
	FILE *new2_fp=fopen(save,"w");

	char bit,word=0;
	int i;

	while(1)
	{
		for(i=7;i>=0;i--)
		{
			bit=fgetc(new_fp);
			if(bit==EOF)
				break;
			setbits(&word,i,1,ctoi(bit));		
		}

		if(bit==EOF)
			break;

		fprintf(new2_fp,"%c",word);
	}

	fclose(new_fp);
	fclose(new2_fp);
}


				
