#include "head.h"


int main()
{
	char com[20],enc[20],dec[20],save[20];

	while(1)
	{
		printf("==========MENU===========\n");
		printf("1. Encoding \n");
		printf("2. Decoding \n");
		printf("=========================\n");
		printf("Choice ( enc or dec)  : ");
		scanf("%s",com);
	
		if(!strcmp(com,"enc"))
		{
			printf("Encoding file name : ");
			scanf("%s",enc);
			printf("Saving file name : ");
			scanf("%s",save);
			binary_change(enc); // file.c
			Encoding(save);// enc.c
			printf("Successful encoding!!\n");
			system("rm binary");
			break;
		}		
		else if(!strcmp(com,"dec"))
		{
			printf("Decoding file name : ");
			scanf("%s",dec);
			printf("Saving file name : ");
			scanf("%s",save);
			Decoding(dec); // dec.c
			character_change(save); // file2.c
			printf("Successful decoding!!\n");
			system("rm binary2");
			break;
		}
		else
		{
			printf("Incorrect Command !!!!!!\n");
			printf("your choice 'enc' or 'dec' \n\n");
		}
	}

}

