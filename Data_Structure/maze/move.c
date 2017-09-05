#include "head.h"

void save()
{
	element item;

	item.row=row;
	item.col=col;
	push(item);
}

int nextpath()
{
	element item;

	item=parity();

	if(item.row==0 && item.col==0)
		return FALSE;
	else
		return TRUE;
}

int ending()
{
	if(maze[row-1][col-1]==OUT)
		return TRUE;
	else if(maze[row-1][col]==OUT)
		return TRUE;
	else if(maze[row-1][col+1]==OUT)
		return TRUE;
	else if(maze[row][col-1]==OUT)
		return TRUE;
	else if(maze[row][col+1]==OUT)
		return TRUE;
	else if(maze[row+1][col-1]==OUT)
		return TRUE;
	else if(maze[row+1][col]==OUT)
		return TRUE;
	else if(maze[row+1][col+1]==OUT)
		return TRUE;
	return FALSE;
}

element parity()
{
	element next;
	int nextrow,nextcol;

	if(maze[row-1][col]==PATH)
	{
		next.row=row-1;
		next.col=col;
		return next;
	}
	else if(maze[row][col+1]==PATH)
	{
		next.row=row;
		next.col=col+1;
		return next;
	}
	else if(maze[row+1][col]==PATH)
	{
		next.row=row+1;
		next.col=col;
		return next;
	}
	else if(maze[row][col-1]==PATH)
	{
		next.row=row;
		next.col=col-1;
		return next;
	}
	else if(maze[row-1][col+1]==PATH)
	{
		next.row=row-1;
		next.col=col+1;
		return next;
	}
	else if(maze[row+1][col+1]==PATH)
	{
		next.row=row+1;
		next.col=col+1;
		return next;
	}
	else if(maze[row+1][col-1]==PATH)
	{
		next.row=row+1;
		next.col=col-1;
		return next;
	}
	else if(maze[row-1][col-1]==PATH)
	{
		next.row=row-1;
		next.col=col-1;
		return next;
	}
	else
	{
		next.row=0;
		next.col=0;
		return next;
	}
	/*
	 *		8	1	5
	 *		4		2
	 *		7	3	6
 	*/
}
