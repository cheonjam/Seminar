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
void delete(char *name);
void save(char *fileName);
void initialize(char *fileName);

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
		else
			printf("Incorrect command!!\n");
	}	
}

void insert(char *name, char *number)
{
	struct node *last,*p=malloc(sizeof(struct node));

	strcpy(p->name,name);
	strcpy(p->number,number);
	p->next=NULL;
	if(head==0)
		head=p;
	else
	{
		for(last=head;last->next;last=last->next)
			;
		last->next=p;
	}
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
	struct node *p;

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
	struct node *pp=0,*p;

	for(p=head;p;pp=p,p=p->next)
	{
		if(!strcmp(p->name,name))
		{
			if(pp==0)
				head=p->next;
			else
			{
				pp->next=p->next;
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
	struct node *p=head;

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
	struct node *p=head, *pp;
	FILE *fp;
	int i=1;

	if((fp=fopen(fileName,"r"))==NULL)
	{
		printf("Not find file !!\n");
		return ;
	}

	while(p)
	{
		pp=p;
		p=p->next;
		free(pp);
	}
	free(p);
	
	head=0;
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
	}
	
	print();
}		
