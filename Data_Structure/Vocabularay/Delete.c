#include "head.h"

BTreeNode *Delete(BTreeNode *bt, char *word)
{
	BTreeNode *tmp;

	if(*word=='\0' || bt==NULL)
	{
		*word='\0';
		return NULL;
	}

	if(*word == bt->word)
	{
		if(*(word+1))
			bt->child=Delete(bt->child,word+1);
		else
		{
			if(*bt->explain)
				memset(bt->explain,'\0',sizeof(bt->explain));
			else
				*word='\0';
		}
		if( !(bt->child) && !(*bt->explain) )
		{
			tmp=bt->sibling;
			free(bt);
			return tmp;
		}
	}
	else if(*word > bt->word)
		bt->sibling=Delete(bt->sibling,word);
	else
		*word='\0';
	return bt;
}


void AllDelete(BTreeNode *bt)
{
	if(bt==NULL)
		return ;
	
	AllDelete(bt->child);
	AllDelete(bt->sibling);
	free(bt);
}

