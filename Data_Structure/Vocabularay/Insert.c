#include "head.h"

BTreeNode *Search(BTreeNode *bt, char *word, char *explain)
{
	static int i=0;
	BTreeNode *tmp=NULL;

	if(!bt)
		bt=Insert(bt,word,explain);
	else if(*word > bt->word)
		bt->sibling=Search(bt->sibling,word,explain);
	else if(!(*(word+1)))
	{
		if(bt->word != *word)
		{
			tmp=Insert(tmp,word,explain);
			tmp->sibling=bt;
			return tmp;
		}
		else if(*bt->explain)
			printf("\033[31mError : \033[0malready exist word\n");
		else
			bt=Insert(bt,word,explain);
	}
	else if(*word == bt->word)
		bt->child=Search(bt->child,word+1,explain);
	else if(*word < bt->word)
	{
		tmp=Insert(tmp,word,explain);
		tmp->sibling=bt;
		return tmp;
	}

	return bt;
}

BTreeNode *Insert(BTreeNode *bt, char *word, char *explain)
{
	static int i=0;

	if(*word=='\0')
		return NULL;
	
	if(bt)
	{
		strcpy(bt->explain,explain);
		return bt;
	}

	bt= (BTreeNode *)malloc(sizeof(BTreeNode));
	memset(bt,'\0',sizeof(BTreeNode));
		
	bt->word=*word;
	if(!(*(word+1)))
		strcpy(bt->explain,explain);
	bt->child=Insert(bt->child,word+1,explain);

	return bt;
}

