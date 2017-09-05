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
void doublechange(struct node *a,struct node *b);

int main(int argc, char *argv[])
{
	char command[10],name[50],number[30],fileName[20];
	FILE *fp=fopen(argv[1],"r");
	if(fp)
	{
		struct node *p,*last;
		while(1)
		{
			if(feof(fp))
				break;
			p=malloc(sizeof(struct node));
			p->next=p->prev=0;
			if(!head)
			{
				fscanf(fp,"%s %s\n",p->name,p->number);
				head=p;
			}
	
			else
			{
				fscanf(fp,"%s %s\n",p->name,p->number);
				for(last=head;last->next;last=last->next)
					;
				last->next=p;
				p->prev=last;
			}
		}
		last=p;
		print();
	}
	while(1)
	{
		printf("command(print,find,insert,delete,save,initialize,sort,quit)?\n");
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
	new->next=new->prev=NULL;

	if(!head)
	{
		head=new;
		return ;
	}
	for(last=head;last->next;last=last->next)
		;
	last->next=new;
	new->prev=last;
	
}
	
void print()
{
	struct node *p;

	for(p=head;p;p=p->next)
		printf("%s    %s \n",p->name,p->number);
}

void find(char *name)
{
	struct node *p;

	for(p=head;p;p=p->next)
	{
		if(!strcmp(name,p->name))
		{
			printf("Find number : %s\n",p->number);
			return ;
		}
	}
	printf("Not Find name !!\n");
}
int samename(char *name)
{
	struct node *p=head;

	for(p=head;p;p=p->next)
	{
		if(!strcmp(name,p->name))
		{
			printf("Samename is exist !!\n");
			return -1;
		}
	}
	return 0;
}

void delete(char *name)
{
	struct node *p;

	for(p=head;p;p=p->next)
	{
		if(!strcmp(name,p->name))
		{	
			if(!p->prev) //p->prev == 0
			{	
				head=p->next;
				if(head) 
					head->prev=0;
			}
			else 
			{
				p->prev->next=p->next;
				if(p->next)
					p->next->prev=p->prev;
				free(p);
			}
			return ;
		}
	}
	printf("Not find delete name!!\n");
}

void save(char *fileName)
{
	FILE *fp;
	struct node *p;

	if((fp=fopen(fileName,"w"))==NULL)
	{
		printf("file open error\n");
		return ;
	}
	
	for(p=head;p;p=p->next)
		fprintf(fp,"%s %s\n",p->name,p->number);

	fclose(fp);
}
void initialize(char *fileName)
{
	struct node *last,*p;
	FILE *fp;

	if((fp=fopen(fileName,"r"))==NULL)
	{
		printf("Not find file !!\n");
		return ;
	}
	if(head)
	{
		while(head->next)
		{
			delete(head->name);
			free(head->prev);
			head->prev=0;
		}
		free(head);
	}

	head=0;
	while(1)
	{
		if(feof(fp))
			break;
		p=malloc(sizeof(struct node));
		p->next=p->prev=0;
		if(!head)
		{
			fscanf(fp,"%s %s\n",p->name,p->number);
			head=p;
		}

		else
		{
			fscanf(fp,"%s %s\n",p->name,p->number);
			for(last=head;last->next;last=last->next)
				;
			last->next=p;
			p->prev=last;
		}
	}
	last=p ;
	
	print();
}		

void sort()
{
	struct node *fast=0, *slow;

	for(slow=head;slow->next!=NULL;slow=slow->next)
	{
		printf("1slowname %s\n",slow->name);
		printf("1fastname %s\n\n",fast->name);
		for(fast=slow->next;fast!=NULL;fast=fast->next)
		{
			printf("2slowname %s\n",slow->name);
			printf("2fastname %s\n\n",fast->name);
			if(strcmp(slow->name,fast->name)>0)
			{
				doublechange(slow,fast);
				printf("3slowname %s\n",slow->name);
				printf("3fastname %s\n\n",fast->name);
			}
		}
	}
	print();
}

void doublechange(struct node *a,struct node *b)
{
	struct node *tmp;

	if(a->next == b)
	{
		tmp=a->next;
		a->next=b->next;
		b->next=b->prev;
		b->prev=a->prev;
		a->prev=tmp;

		if(b->prev==NULL)
			a->next->prev=a;
		else if(a->next==NULL)
			b->prev->next=b;
		else
		{
			b->prev->next=b;
			a->next->prev=a;
		}
	}
	else
	{
		tmp=a->next;
		a->next=b->next;
		b->next=tmp;
	
		tmp=a->prev;
		a->prev=b->prev;
		b->prev=tmp;
	
		if(b->prev==NULL)
		{
			a->prev->next=a;
			a->next->prev=a;
			b->next->prev=b;
		}
		else if(a->next==NULL)
		{
			a->prev->next=a;
			b->prev->next=b;
			b->next->prev=b;
		}
		else		
		{
			a->prev->next=a;
			a->next->prev=a;
			b->prev->next=b;
			b->next->prev=b;
		}
	}
}
	

