#include "head.h"

BTreeNode *Find(BTreeNode *bt, char *word)
{

	if(*word=='\0' || bt==NULL)
		return NULL;
	
	if(*word == bt->word)
	{
		if(*(word+1))
			bt=Find(bt->child,word+1);
		else
		{
			if(*bt->explain)
				return bt;
			else
				return NULL;
		}
	}
	else if(*word > bt->word)
		bt=Find(bt->sibling,word);
	else
		return NULL;	

	return bt;
}


