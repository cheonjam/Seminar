#include "head.h"

int main()
{
	element item;
	int startflag=1,endflag=0;

	set();
	print();
	printf("Next move(press ENTER)");
	getchar();

	while(1)
	{
		/* START FLAG*/
		if(startflag)
		{
			maze[row][col]=ENTER;
			startflag=FALSE;
		}
		else
			maze[row][col]=PAST;
	
		/* FIND ENDING */
		if(maze[row][col+1]==OUT)
		{
			maze[row][++col]=NOW;
			endflag=TRUE;
		}	

		/* FIND PATH */
		if(maze[row-1][col]==PATH)
		{
			save();
			row--;
		}
		else if(maze[row][col+1]==PATH)
		{
			save();
			col++;
		}
		else if(maze[row+1][col]==PATH)
		{
			save();
			row++;
		}
		else if(maze[row][col-1]==PATH)
		{
			save();
			col--;
		}
		else if(maze[row-1][col+1]==PATH)
		{
			save();
			row--;
			col++;
		}
		else if(maze[row+1][col+1]==PATH)
		{
			save();
			row++;
			col++;
		}
		else if(maze[row+1][col-1]==PATH)
		{
			save();
			row++;
			col--;
		}
		else if(maze[row-1][col-1]==PATH)
		{
			save();
			row--;
			col--;
		}
		/* NO PATH*/
		else
		{
			item=pop();
			row=item.row;
			col=item.col;
		}
		
		/* ENDING */
		if(endflag)
		{
			print();
			printf("\t    \033[0;45m< E N D >\033[0m \n");
			return 0;
		}
		/* CONTINUE */
		else
		{	
			maze[row][col]=NOW;
			print();
			printf("Next move(press ENTER)");
			getchar();
		}
	}
}
