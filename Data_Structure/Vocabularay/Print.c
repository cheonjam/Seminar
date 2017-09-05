#include "head.h"

void Print(BTreeNode *bt, char *tmp)
{
	if(bt==NULL)
		return ;

	tmp[strlen(tmp)]=bt->word;

	if(*bt->explain)
		printf("%s\t : %s\n",tmp,bt->explain);
	Print(bt->child,tmp);
	tmp[strlen(tmp)-1]='\0';
	Print(bt->sibling,tmp);
}

