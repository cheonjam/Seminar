#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *link;
}DATA , *PDATA;

PDATA nodeAlloc(int data);
PDATA insertNode(PDATA head, int data);
PDATA print(PDATA head);

int main()
{
	PDATA head = NULL, p=NULL;
	head = insertNode(head,10);
	head = insertNode(head,20);
	head = insertNode(head,30);
	head = insertNode(head,40);
	print(head);

	return 0;
}


PDATA nodeAlloc(int data)
{
	PDATA p=(PDATA)malloc(sizeof(DATA));
	p->data = data;
	p->link = NULL;
	return p;
}

PDATA insertNode(PDATA head, int data)
{
	PDATA p=head, n=nodeAlloc(data);

	if(head==NULL)
		return n;

	while(p->link)
		p=p->link;

	p->link = n;

	return head;
}

PDATA print(PDATA head)
{
	PDATA p=NULL;

	for(p=head;p;p=p->link)
		printf("%d\n",p->data);
}
