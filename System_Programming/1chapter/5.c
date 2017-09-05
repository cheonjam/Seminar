#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct single
{
	char word[100];
	struct single *next;
}*head;

void add();
void print();
int main()
{
	int num;
	
	while(1)
	{
		printf("Input Command: 1(addition), 2(print)\n");
		scanf("%d",&num);

		switch(num)
		{
			case 1: 
					add();
					break;
	
			case 2:
					print();
					break;
	
			case 3:
					return 0;

			default :
					printf("Incorrect number\n");
					break;
		}
	}
}

void add()
{
	struct single *new, *tmp;
	new=malloc(sizeof(struct single));
	memset(new,'\0',sizeof(struct single));

	printf("Input a word:");
	scanf("%s",new->word);

	if(!head)
		head=new;
	else
	{
		for(tmp=head; tmp->next ; tmp=tmp->next)
			;
		tmp->next=new;
	}

}

void print()
{
	struct single *tmp;

	for(tmp=head; tmp ; tmp=tmp->next)
		printf("%s ",tmp->word);

	printf("\n");
}
