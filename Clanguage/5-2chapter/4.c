#include <stdio.h>
#include <string.h>

int main()
{
	char command[10];
	int a,b,i;
	printf("Input command: add, subtract, divide, multiply, quit\n");
	scanf("%s",command);
	while(1)
	{
		if(!strcmp(command,"quit"))
			break;
		else
		{
			printf("Input numbers(number1 number2)\n");
			scanf("%d %d",&a,&b);
			
			if(!strcmp(command,"add"))
				printf("%d + %d = %d \n",a,b,a+b);
		
			else if(!strcmp(command,"subtract"))
				printf("%d - %d = %d \n",a,b,a-b);
			
			else if(!strcmp(command,"multiply"))
				printf("%d * %d = %d \n",a,b,a*b);
		
			else if(!strcmp(command,"divide"))
			{
					if(b!=0)
						printf("%d / %d = %d \n",a,b,a/b);
					else		
						printf("divide by 0\n");
			}
			else
				printf("Incorrect command!!\n");
		}
	
		printf("command(add, subtract, divide, multiply, quit)?\n");
		scanf("%s",command);
	}
	return 0;
}

