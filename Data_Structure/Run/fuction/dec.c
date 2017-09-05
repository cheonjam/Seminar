#include "head.h"

void Decoding(char *dec)
{
	FILE *dec_fp=fopen(dec,"r");
	FILE *new_fp=fopen("binary2", "w");

	char word;
	int i,j,num1,num2;

	while(1)
	{
		if((fscanf(dec_fp,"%c",&word)==EOF)) //loading char
			break;
		
		if(getbits(word,7,1)) // type1
		{
			for(i=6;i!=0;i--)
			{
				num1=getbits(word,i,1);
				num2=getbits(word,i-1,1);

				if(num1==num2)
				{
					for(j=6;j>=i;j--)
						fprintf(new_fp,"%d",getbits(word,j,1));

					break;
				}
			}
		}
		else // type0
		{
			num1=getbits(word,6,6); // counting 
			num2=getbits(word,0,1); // 0bit number 

			for(i=0;i<num1;i++)
				fprintf(new_fp,"%d",num2);
		}
	}
	
	fclose(dec_fp);
	fclose(new_fp);
}
