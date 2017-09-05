#include "Tree_head.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->oper='\0';
	nd->data='\0';
	nd->left=NULL;
	nd->right=NULL;
	return nd;
}

void PreorderTraverse(BTreeNode *bt)
{
	if(bt==NULL)
		return ;

	if(bt->oper)
		printf("%c ",bt->oper);
	else
		printf("%g ",bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void InorderTraverse(BTreeNode *bt)
{
	if(bt==NULL)
		return ;

	InorderTraverse(bt->left);
	if(bt->oper)
		printf("%c ",bt->oper);
	else
		printf("%g ",bt->data);
	InorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode *bt)
{
	if(bt==NULL)
		return ;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	if(bt->oper)
		printf("%c ",bt->oper);
	else
		printf("%g ",bt->data);
}

void AllNodeFree(BTreeNode *bt)
{
	if(bt==NULL)
		return ;

	AllNodeFree(bt->left);
	AllNodeFree(bt->right);
	free(bt);
}
