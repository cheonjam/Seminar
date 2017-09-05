#include <stdio.h>

int main()
{
	char str[100];
	char *a=str;
	int i,b;
	while(1)
	{
		printf("Input strings(quit : 'q' or 'Q') : ");
		scanf("%s",str);
		
		if(!strcmp(a,"q")||!strcmp(a,"Q"))
			return 0;

		for(i=0;*(a+i)!='\0';i++)
		{
			if(*(a+i)>='A'&&*(a+i)<='Z')
				*(a+i)+=32;
		
			else if(*(a+i)>='a'&&*(a+i)<='z')
				*(a+i)-=32;
			
		}
	
		for(i=0;*(a+i)!='\0';i++)
			printf("%c", *(a + i));
		printf("\n");	
	}
}
