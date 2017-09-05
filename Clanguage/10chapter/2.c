#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address
{
	char name[40];
	struct address *next;
};

void store(struct address *item);
void display(struct address *top);

int main()
{
	struct address *head=0, *tmp;

	head=tmp=(struct address *)malloc(sizeof(struct address));
	strcpy(tmp->name,"HONG GIL DONG");
	store(tmp);
	tmp=(struct address *)malloc(sizeof(struct address));
	strcpy(tmp->name, "KIM CHUL SU");
	store(tmp);
	display(tmp);
}

void store(struct address *item)
{
	static struct address *last =0;

	if(last ==0)
		last=item;
	else
		last->next = item;

	item->next =0;
	last = item;
}

void display(struct address *top)
{
	while(top)
	{
		printf("%s\n",top->name);
		top=top->next;
		printf("a\n");
	}
}
