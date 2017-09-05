#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int score;
	char *name;
	struct node *prev;
	struct node *next;
}*head;

void insert(int score, char *name);
int delete(char *name);
int find(char *name);
void print();

int main()
{
	int num,score;
	char name[100];	

	while(1)
	{
		printf("Input Command: 1(addition), 2(delete), 3(find), 4(print) 5(exit)\n");
		scanf("%d",&num);

		switch(num)
		{
			case 1: 
					printf("input score\t");
					scanf("%d",&score);
					if(score<0)
					{
						printf("score > 0 \n");
						continue;
					}
					printf("input name\t");
					scanf("%s",name);
					insert(score,name);
					break;
			case 2: 
					printf("name for deletion\t");
					scanf("%s",name);
					if(!delete(name))
						printf("deleted %s\n",name);
					else
						printf("no such name\n");

					break;
			case 3:
					printf("name for find\t");
					scanf("%s",name);
					if((score=find(name))>-1)
						printf("The score for %s is %d\n",name,score);
					else
						printf("no such name\n");
					break;
			case 4:
					print();
					break;
			case 5:
					return 0;

			default :
					printf("Incorrect number\n");
					break;
		}
	}
}

void insert(int score, char *name)
{
	struct node *ptr, *tmp;

	ptr=malloc(sizeof(struct node));
	ptr->score=score;
	ptr->name=malloc(sizeof(name));
	strcpy(ptr->name,name);
	ptr->next=NULL;

	if(!head)
	{
		ptr->prev=NULL;
		head=ptr;
	}
	else
	{
		for(tmp=head;tmp->next;tmp=tmp->next)
			;
		ptr->prev=tmp;
		tmp->next=ptr;
	}
}
		

int delete(char *name)
{
	struct node *ptr;

	if(!head)
		return -1;
	else
	{
		for(ptr=head;ptr;ptr=ptr->next)
		{
			if(!strcmp(ptr->name,name))
			{
				if(ptr==head)
					head=ptr->next;
				else
					ptr->prev->next=ptr->next;
				if(ptr->next)
					ptr->next->prev=ptr->prev;
				free(ptr->name);
				free(ptr);
				return 0;
			}
		}
	}

	return -1;
}

int find(char *name)
{
	struct node *ptr;

	if(!head)
		return -1;
	else
	{
		for(ptr=head;ptr;ptr=ptr->next)
		{
			if(!strcmp(ptr->name,name))
				return ptr->score;
		}
	}

	return -1;
}

void print()
{
	struct node *ptr;

	if(!head)
	{
		printf("No data\n");
		return ;
	}
	else
	{
		for(ptr=head; ptr ; ptr=ptr->next)
			printf("%s : %d \n",ptr->name,ptr->score);
	}
}
