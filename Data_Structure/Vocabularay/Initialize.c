#include "head.h"

BTreeNode *Initialize(FILE *fp)
{
	char str1[MAX], str2[MAX];
	BTreeNode *ROOT=NULL;
	
	while(1)
	{
		if(feof(fp))
			break;

		fscanf(fp,"%s\t : %[^\n]\n",str1,str2);
		ROOT=Search(ROOT,str1,str2);
	}

	return ROOT;
}
