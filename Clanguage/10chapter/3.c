#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[50];
	char number[30];
	struct node *next;
}*head;

void insert(struct node *head);
void print(struct node *head);
void find(struct node *head);

int main()
{
	char command[10];
	
	while(1)
	{
		printf("command(print,find,insert,quit)?\n");
		scanf("%s",command);

		if(!strcmp(command,"quit"))
			return 0;
		else if(!strcmp(command,"find"))
			find(head);
		else if(!strcmp(command,"insert"))
		{
			insert(head);
			printf("aahead name:%s\n",head->name);
			printf("aahead number : %s\n",head->number);
		}
		else if(!strcmp(command,"print"))
			print(head);
				
		else
			printf("Incorrect command!!\n");
	}	


}

void insert(struct node *head)
{
	static struct node *last=0;
	struct node *p=(struct node *)malloc(sizeof(struct node));
	
	printf("Input Name : ");
	scanf("%s",p->name);
	printf("Input Number : ");
	scanf("%s",p->number);
	p->next=NULL;

	if(head==0)
	{
		printf("head!!\n");
		head=p;
	}
	if(last==0)
	{
		last=p;
	}
	else
		last->next=p;

		printf("head name:%s\n",head->name);
		printf("head number : %s\n",head->number);
		printf("last name:%s\n",last->name);
		printf("last number:%s\n",last->number);
		printf("p name:%s\n",p->name);
		printf("p number:%s\n",p->number);

	last=p;
}
	
void print(struct node *head)
{
//	printf("%s\n",head->name);
//	printf("%s\n",head->number);

	while(head)
	{
//		printf("n\n");
		printf("%s\n",head->name);
		printf("%s\n",head->number);
		head=head->next;
	}
}

void find(struct node *head)
{
	char Fname[20];

	printf("Find name : ");
	scanf("%s",Fname);

	while(head)
	{
//		printf("aa\n");
		if(!strcmp(Fname,head->name))
		{
			printf("Fine name : %s\n",head->name);
			printf("Find number : %s\n",head->number);
			return ;
		}
	}

	printf("Not Find name !!\n");
}
	
