#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[50];
	char number[30];
	struct node *next;
}*head;

void insert(char *name, char *number);
void print();
void find(char *name);
int samename(char *name);

int main()
{
	char command[10],name[50],number[30];
	int a;	
	while(1)
	{
		printf("command(print,find,insert,quit)?\n");
		scanf("%s",command);

		if(!strcmp(command,"quit"))
			return 0;
		else if(!strcmp(command,"find"))
		{
			printf("Find name : ");
			scanf("%s",name);
			find(name);
		}
		
		else if(!strcmp(command,"insert"))
		{
			printf("Insert Name : ");
			scanf("%s",name);
			a=samename(name);
			if(a==-1)
				continue;			
			printf("Insert Number : ");
			scanf("%s",number);
			insert(name,number);
		}
		else if(!strcmp(command,"print"))
			print();
				
		else
			printf("Incorrect command!!\n");
	}	
}

void insert(char *name, char *number)
{
	static struct node *last=0;
	struct node *p=malloc(sizeof(struct node));

	strcpy(p->name,name);
	strcpy(p->number,number);
	p->next=NULL;

	if(head==0)
		head=p;

	if(last==0)
		last=p;
	else
		last->next=p;

	last=p;
}
	
void print()
{
	struct node *p=head;

	while(p)
	{
		printf("%s    %s \n",p->name,p->number);
		p=p->next;
	}
}

void find(char *name)
{
	struct node *p = head;

	while(p)
	{		
		if(!strcmp(name,p->name))
		{
			printf("Find number : %s\n",p->number);
			return ;
		}
		p=p->next;
	}

	printf("Not Find name !!\n");
}
int samename(char *name)
{
	struct node *p=head;

	while(p)
	{
		if(!strcmp(name,p->name))
		{
			printf("Samename is exist !!\n");
			return -1;
		}	
		p=p->next;
	}
	return 0;
}
