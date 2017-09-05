#include "head.h"

void addPolyNode(polyNode **head, float coef, int expo)
{
	polyNode *new, *last;

	new=(polyNode*)malloc(sizeof(polyNode));
	new->coef=coef;
	new->expo=expo;
	new->next=NULL;

	if(!(*head))
		*head=new;	
	else
	{
		for(last=*head;last->next;last=last->next)
			;
		last->next=new;
	}

}

void printNode(polyNode **head)
{
	polyNode *p;
	int flag=0;

	for(p=*head; p; p=p->next)
	{
		if(!p->coef)
			continue;
		flag=1;
/*
		if(p->coef==1)
		{
			if(p->expo==0)
			{
				if(p==*head)
					printf("%g",p->coef);
				else
					printf("%+g",p->coef);
			}
			
		}
		else
		{
			if(p==*head)
				printf("%g",p->coef);
			else
				printf("%+g",p->coef);
		}
*/	
		if(p==*head)
		{
			if(!p->expo)
				printf("%g",p->coef);
			else
			{
				if(p->coef == -1)
					printf("-");
				else if(p->coef !=1)
					printf("%g",p->coef);
			}
		}
		else
			printf("%+g",p->coef);


		if(p->expo==1)
			printf("x");
		else if(p->expo>1)
			printf("x^%d",p->expo);
			
	}
	if(!flag)
		printf("0");
		

	printf("\n");
}

void changeNode(polyNode **head, polyNode *a, polyNode *b)
{
	polyNode *a_prev, *b_prev, *tmp;

	if(a!=*head)
		for(a_prev=*head; a_prev->next!=a; a_prev=a_prev->next);
	
	for(b_prev=*head; b_prev->next!=b; b_prev=b_prev->next);

	if(a->next == b)
	{
		a->next = b->next;
		b->next = a;
	}
	else
	{
		tmp=a->next;
		a->next=b->next;
		b->next=tmp;

		b_prev->next=a;
	}

	if(a==*head)
		*head=b;
	else
		a_prev->next=b;		
	
}

void sortNode(polyNode **head)
{
	polyNode *a,*b,*tmp;

	for(a=*head;a->next;a=a->next)
	{
		for(b=a->next;b;b=b->next)
		{
			if(a->expo < b->expo)
			{
				changeNode(head,a,b);
				tmp=a;
				a=b;
				b=tmp;
			}
		}
	}
}


void settingNode(polyNode **head)
{
	polyNode *last, *tmp;
	float sum_coef=0;

	for(last=*head; last->next;last=last->next)
	{
		/*	 coef == 0
		 *
		if(!last->coef)
		{
			if(last==*head)
			{
				tmp=last->next;
				free(last);
				last=tmp;
				*head=last;
			}
			else
			{
				for(tmp=*head;tmp->next!=last;tmp=tmp->next)
					;
				tmp->next=last->next;
				free(last);
				last=tmp->next;
			}
		}
		*/
		if(last->expo == last->next->expo)
		{
			sum_coef=last->coef;
			tmp=last->next;
			while(tmp && last->expo == tmp->expo)
			{
				sum_coef+=tmp->coef;
				last->next=tmp->next;
				free(tmp);
				tmp=last->next;
			}
			
			last->coef=sum_coef;
		}
		if(!last->next)
			break;
	}
}

void freeNode(polyNode *head)
{
	polyNode *last=head,*tmp;

	while(last)
	{
		tmp=last->next;
		free(last);
		last=tmp;
	}
}
