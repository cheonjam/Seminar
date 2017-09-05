#include <stdio.h>
#include <string.h>

int main()
{
	char command[10];
	int a,b,c,i;
	while(1)
	{
		printf("Input command: add, subtract, divide, multiply, quit\n");
		scanf("%s",command);

		if(!strcmp(command,"quit"))
			return 0;
		else if(!strcmp(command,"add"))
			c=1;	
		else if(!strcmp(command,"subtract"))
			c=2;
		else if(!strcmp(command,"multiply"))
			c=3;
		else if(!strcmp(command,"divide"))
			c=4;
		else
		{	
			printf("Incorrect command!!\n");
			continue;
		}	
		printf("Input numbers(number1 number2)\n");
		scanf("%d %d",&a,&b);

		if(c==1)
			printf("%d + %d = %d \n",a,b,a+b);
		if(c==2)
			printf("%d - %d = %d \n",a,b,a-b);
		if(c==3)
			printf("%d * %d = %d \n",a,b,a*b);
		if(c==4)
		{
			if(b!=0)
				printf("%d / %d = %d \n",a,b,a/b);
			else		
				printf("divide by 0\n");
		}
	}
	
}
