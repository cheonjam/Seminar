#include "head.h"

void Save(BTreeNode *bt, char *tmp, FILE *fp)
{
	if(bt==NULL)
		return ;

	tmp[strlen(tmp)]=bt->word;

	if(*bt->explain)
		fprintf(fp,"%s\t : %s\n",tmp,bt->explain);
	Save(bt->child,tmp,fp);
	tmp[strlen(tmp)-1]='\0';
	Save(bt->sibling,tmp,fp);
}
