#include "head.h"

void print()
{
	int i,j;
	
	system("clear");

	printf("\n\n\t   \033[0;41m< M A Z E >\033[0m\n\n");
	for(i=0;i<14;i++)
	{
		printf("\t");
		for(j=0;j<18;j++)
		{
			if(maze[i][j]=='0')
				printf(".");
			else if(maze[i][j]=='1')
				printf("\033[0;43m \033[0m");
			else if(maze[i][j]=='2')
				printf("\033[0;47m=\033[0m");
			else if(maze[i][j]=='3')
				printf("\033[0;47m \033[0m");
			else if(maze[i][j]=='4')
				printf("\033[0;36m>\033[0m");
			else if(maze[i][j]=='5')
				printf("\033[0;31m*\033[0m");
			else if(maze[i][j]=='6')
				printf(" ");
			else if(maze[i][j]=='7')
				printf("\033[0;36m>\033[0m");
			else
				printf("%c",maze[i][j]);
		}
	}
	printf("\n\n");
}
