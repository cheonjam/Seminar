#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct PolyNode{
	float coef;
	int expo;
	struct PolyNode* next;
}polyNode;

void addPolyNode(polyNode *head, float coef, int expo)
{
	polyNode *new, *last;

	new=(polyNode*)malloc(sizeof(polyNode));
	new->coef=coef;
	new->expo=expo;
	if(!head)
		head->next=new;	
	else
	{
		for(last=head;last->next;last=last->next)
			;
		last->next=new;
	}
}

void changeNode(polyNode *head, polyNode *a, polyNode *b)
{
	polyNode *a_prev, *b_prev, *tmp;

	if(a!=head)
		for(a_prev=head; a_prev->next!=a; a_prev=a_prev->next);
	
	for(b_prev=head; b_prev->next!=b; b_prev=b_prev->next);

	tmp=a->next;
	a->next=b->next;
	b->next=tmp;

	if(a==head)
	{
		b_prev->next=a;
		head=b;
	}
	else
	{
		tmp=a_prev->next;
		a_prev->next=b_prev->next;
		b_prev->next=tmp;
	}

	tmp=a;
	a=b;
	b=tmp;
}

void sortNode(polyNode *head)
{
	polyNode *a,*b,*tmp;

	for(a=head;a->next;a=a->next)
	{
		for(b=a->next;b;b=b->next)
		{
			if(a->expo < b->expo)
				changeNode(head,a,b);
		}
	}
}
		

polyNode* sumpolyNode(polyNode *headA, polyNode *headB)
{
	polyNode *sumNode, *last, *NodeA, *NodeB;
	sumNode=(polyNode*)malloc(sizeof(polyNode));
	NodeA=headA;
	NodeB=headB;

	while(NodeA!=NULL && NodeB!=NULL)
	{
		if(NodeA->expo > NodeB->expo)
		{
			addPolyNode(sumNode,NodeA->coef,NodeA->expo);
			NodeA = NodeA->next;
		}
		else if(NodeA->expo < NodeB->expo)
		{
			addPolyNode(sumNode,NodeB->coef,NodeB->expo);
			NodeB = NodeB->next;
		}
		else
		{
			addPolyNode(sumNode, (NodeA->coef+NodeB->coef), NodeA->expo);
			NodeA = NodeA->next;
			NodeB = NodeB->next;
		}
	}

	while(NodeA!=NULL)
	{
		addPolyNode(sumNode,NodeA->coef,NodeA->expo);
		NodeA = NodeA->next;
	}
			
	while(NodeB!=NULL)
	{
		addPolyNode(sumNode,NodeB->coef,NodeB->expo);
		NodeB = NodeB->next;
	}

	return sumNode;
}

polyNode* mulpolyNode(polyNode *headA, polyNode *headB)
{
	polyNode *mulNode,*NodeA, *NodeB, *last, *tmp; 
	float sum_coef=0;

	mulNode=(polyNode *)malloc(sizeof(polyNode));


	for(NodeA=headA;NodeA;NodeA=NodeA->next)
	{
		for(NodeB=headB;NodeB;NodeB=NodeB->next)
			addPolyNode(mulNode,(NodeA->coef*NodeB->coef),(NodeA->expo+NodeB->expo));
	}

	sortNode(mulNude);

	for(last=mulNode;last->next;last=last->next)
	{
		if(last->expo==last->next->expo)
		{
			sum_coef=last->coef;
			tmp=last->next;
			while(last->expo==tmp->expo)
			{
				sum_coef+=tmp->coef;
				last->next=tmp->next;
				free(tmp);
				tmp=last->next;
			}
		}
	}
	
	return mulNode;
}


int main()
{
	polyNode* array[MAX]={};
	char tmp[MAX];

	printf("Input pomula1 :");
	scanf("%s",tmp);

	//NodeSetting(array,tmp);
}	
