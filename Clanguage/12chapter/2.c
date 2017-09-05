#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[50];
	char number[30];
	struct node *next;
	struct node *prev;
}*head;

void insert(char *name, char *number);
void print();
void find(char *name);
int samename(char *name);
void delete(char *name);
void save(char *fileName);
void initialize(char *fileName);
void sort();
void doublechange();

int main(int argc, char *argv[])
{
	char command[10],name[50],number[30],fileName[20];
	FILE *fp;
	if(fp=fopen(argv[1],"r"))
	{
		struct node *p=head,*pp;
		while(1)
		{
			if(feof(fp))
				break;
			p=malloc(sizeof(struct node));
			if(head==NULL)
			{
				fscanf(fp,"%s %s\n",p->name,p->number);
				head=p;
				pp=p;
			}
	
			else
			{
				fscanf(fp,"%s %s\n",p->name,p->number);
				pp->next=p;
				pp=p;
			}
			p->next=0;
		}
		print();
	}
	
	while(1)
	{
		printf("command(print,find,insert,delete,save,initialize,quit)?\n");
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
			if(samename(name)==-1)
				continue;			
			printf("Insert Number : ");
			scanf("%s",number);
			insert(name,number);
		}
		else if(!strcmp(command,"print"))
			print();

		else if(!strcmp(command,"delete"))
		{
			printf("delete name : ");
			scanf("%s",name);
			delete(name);
		}
		
		else if(!strcmp(command,"save"))
		{
			printf("Save filename : ");
			scanf("%s",fileName);
			save(fileName);
		}		
		else if(!strcmp(command,"initialize"))
		{
			printf("Initial filename : ");
			scanf("%s",fileName);
			initialize(fileName);
		}	
		else if(!strcmp(command,"sort"))
			sort();	
		else
			printf("Incorrect command!!\n");
	}	
}

void insert(char *name, char *number)
{
	struct node *last,*new=malloc(sizeof(struct node));

	strcpy(new->name,name);
	strcpy(new->number,number);
	new->next=NULL;
	if(head==0)
		head=new;
	else
	{
		for(last=head;last->next;last=last->next)
			;
		last->next=new;
	}
}
	
void print()
{
	struct node *last;

	for(last=head;last;last=last->next)
		printf("%s    %s \n",last->name,last->number);
}

void find(char *name)
{
	struct node *last;
	for(last=head;last;last=last->next)
	{
		if(!strcmp(name,last->name))
		{
			printf("Find number : %s\n",last->number);
			return ;
		}
	}

	printf("Not Find name !!\n");
}
int samename(char *name)
{
	struct node *last;

	for(last=head;last;last=last->next)
	{
		if(!strcmp(name,last->name))
		{
			printf("Samename is exist !!\n");
			return -1;
		}	
	}
	return 0;
}

void delete(char *name)
{
	struct node *last_prev=0,*last;

	for(last=head;last;last_prev=last,last=last->next)
	{
		if(!strcmp(last->name,name))
		{
			if(last_prev==0)
				head=last->next;
			else
			{
				last_prev->next=last->next;
				free(last);
			}
			return ;
		}
	}
	printf("Not find delete name!!\n");
}

void save(char *fileName)
{
	FILE *fp;
	struct node *last=head;

	if((fp=fopen(fileName,"w"))==NULL)
	{
		printf("file open error\n");
		return ;
	}
	for(last=head;last;last=last->next)
		fprintf(fp,"%s %s\n",last->name,last->number);

	fclose(fp);
}
void initialize(char *fileName)
{
	struct node *last=head, *last_prev;
	FILE *fp;

	if((fp=fopen(fileName,"r"))==NULL)
	{
		printf("Not find file !!\n");
		return ;
	}

	while(last)
	{
		last_prev=last;
		last=last->next;
		free(last_prev);
	}
	free(last);
	
	head=0;
	while(1)
	{
		if(feof(fp))
			break;
		last=malloc(sizeof(struct node));
		if(head==NULL)
		{
			fscanf(fp,"%s %s\n",last->name,last->number);
			head=last;
			last_prev=last;
		}

		else
		{
			fscanf(fp,"%s %s\n",last->name,last->number);
			last_prev->next=last;
			last_prev=last;
		}
	}
	
	print();
}
void sort()
{
	struct node *first, *second, *tmp=0;
	int a=1;

	for(first=head;first;first=first->next)
	{
		for(second=first->next;second;second=second->next)
		{
			if(strcmp(first->name,second->name)>0)
			{
				doublechange(first,second);
				tmp=first;
				first=second;
				second=tmp;
			}
		}
	
	}

}


void doublechange(struct node *a,struct node *b)
{
	struct node *tmp;
	
	if(a->prev==NULL)
	{
		if(b->next==NULL)
			head=b;
		else
		{
			b->next->prev=a;
			head=b;
		}
	}
	else if(b->next==NULL)
		a->prev->next=b;	
	else
	{	
		a->prev->next=b;
		b->next->prev=a;
	}

	if(a->next==b)
	{
		tmp=a->next;
		a->next=b->next;
		b->next=b->prev;
		b->prev=a->prev;
		a->prev=tmp;
	}
	else
	{
		a->next->prev=b;
		b->prev->next=a;

		tmp=a->next;
		a->next=b->next;
		b->next=tmp;

		tmp=a->prev;
		a->prev=b->prev;
		b->prev=tmp;
	}
}
	
