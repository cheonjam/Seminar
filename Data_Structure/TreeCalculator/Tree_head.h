#include <stdio.h>
#include <stdlib.h>

typedef struct _bTreeNode
{
	double data;
	char oper;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
} BTreeNode;

	/* BinaryTree.c*/
BTreeNode* MakeBTreeNode(void);
void PreorderTraverse(BTreeNode *bt);
void InorderTraverse(BTreeNode *bt);
void PostorderTraverse(BTreeNode *bt);
void AllNodeFree(BTreeNode *bt);

	/*MakeTree.c*/
BTreeNode* MakeTree(char *postfix);
int oper_check(char token);

	/*Calculate.c*/
double Calculate(BTreeNode *bt, int *exep);
double double_cal(double op1, double op2, char oper, int **exep);
double single_cal(double op1, char oper, int **exep);
