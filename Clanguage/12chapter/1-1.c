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
void sort();
void changenode();

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
		{
			printf("%p\n",head);
			printf("%p\n",head->next);
			printf("====\n");
			sort();	
		}
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
	struct node *move, *select, *tmp=0;
	char selectname[50];

	for(select=head;select->next;select=select->next)
	{
		tmp=select;
		for(move=select->next;move;move=move->next)
		{
		printf("%s  6\n",move->name);
		printf("%s  7\n",move->next->name);				
		printf("%s  8\n",tmp->name);				
			if(strcmp(tmp->name,move->name)>0)
				tmp=move;
			printf("\n");
			sleep(1);
		}
		printf("%s  1\n",tmp->name);
		printf("%s  2\n",tmp->next->name);				
		printf("%s  3\n",move->name);
		printf("%s  4\n",select->name);
		printf("%s  5\n",select->next->name);
		printf("\n\n\n\n\n");
		changenode(select,tmp);
	
	}

}


void changenode(struct node *a, struct node *b)
{
	struct node *tmp, *a_prev, *b_prev;

	printf("%s  1\n",a->name);
	printf("%s  2\n",head->name);
	if(head!=a)
	{	
		for(a_prev=head ; a_prev->next!=a ; a_prev=a_prev->next)
			;
	}

	for(b_prev=head ; b_prev->next!=b ; b_prev=b_prev->next)
		;
	printf("\n");
	sleep(1);
	printf("%s  a_prev\n",a_prev->name);
	printf("%s  b_prev\n",b_prev->name);
	printf("%s  a_prev->next\n",a_prev->next->name);
	printf("%s  b_prev->nexxt\n",b_prev->next->name);
	printf("%s  a\n",a->name);
	printf("%s  b\n",b->name);
	printf("\n");	

	printf("%s  a->next\n",a->next->name);
	printf("%s  b->next\n",b->next->name);
	printf("===  (a->next  <-> b->next) ==== \n");
	tmp=a->next;
	a->next=b->next;
	b->next=tmp;		// a->next  <->  b->next
	printf("%s  a->next\n",a->next->name);
	printf("%s  b->next\n",b->next->name);
	printf("\n\n\n");
	
	sleep(1);
	printf("%s  a\n",a->name);
	printf("%s  b\n",b->name);
	printf("====  (a  <-> b) ==== \n");
	tmp=a;
	a=b;
	b=tmp;				//a  <->  b
	printf("%s  a\n",a->name);
	printf("%s  b\n",b->name);
	printf("\n\n\n");
	
	if(b==head)			// b_prev->next = b;
	{
		b_prev->next=b;
		head=a;
	}
	else				// a_prev->next <-> b_prev->next
	{
	printf("3\n");
		tmp=a_prev->next;
		a_prev->next=b_prev->next;
		b_prev->next=tmp;
	}
}











