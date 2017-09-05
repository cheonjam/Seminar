#include "BinarySearchTree.h"

int main()
{
	BSTNode *Tree = BST_CreateNode(123);
	BSTNode *Node = NULL;

	BST_InsertNode(Tree, BST_CreateNode(22));
	BST_InsertNode(Tree, BST_CreateNode(9916));
	BST_InsertNode(Tree, BST_CreateNode(424));
	BST_InsertNode(Tree, BST_CreateNode(17));
	BST_InsertNode(Tree, BST_CreateNode(3));

	BST_InsertNode(Tree, BST_CreateNode(98));
	BST_InsertNode(Tree, BST_CreateNode(34));

	BST_InsertNode(Tree, BST_CreateNode(760));
	BST_InsertNode(Tree, BST_CreateNode(317));
	BST_InsertNode(Tree, BST_CreateNode(1));

	BST_InorderPrintTree(Tree);
	printf("\n");

	printf("Removing 98...\n");

	Node = BST_RemoveNode(Tree,NULL,98);
	BST_DestroyNode(Node);

	BST_InorderPrintTree(Tree);
	printf("\n");

	printf("Inserting 111..\n");

	BST_InsertNode(Tree, BST_CreateNode(111));
	BST_InorderPrintTree(Tree);
	printf("\n");

	BST_DestroyTree(Tree);

	return 0;
}

BSTNode *BST_CreateNode(ElementType NewData)
{
	BSTNode *NewNode = (BSTNode *)malloc(sizeof(BSTNode));
	NewNode->left = NULL;
	NewNode->right= NULL;
	NewNode->data = NewData;

	return NewNode;
}

void BST_DestroyNode(BSTNode *Node)
{
	free(Node);
}

void BST_DestroyTree(BSTNode *Tree)
{
	if(Tree->right != NULL)
		BST_DestroyTree(Tree->right);

	if(Tree->left != NULL)
		BST_DestroyTree(Tree->left);

	Tree->left = NULL;
	Tree->right= NULL;

	BST_DestroyNode(Tree);
}

BSTNode *BST_SearchNode(BSTNode *Tree, ElementType Target)
{
	if(Tree==NULL)
		return NULL;

	if(Tree->data < Target)
		return BST_SearchNode(Tree->left, Target);
	else if(Tree->data > Target)
		return BST_SearchNode(Tree->right, Target);
	else
		return Tree;
}

BSTNode *BST_SearchMinNode(BSTNode *Tree)
{
	if(Tree==NULL)
		return NULL;

	if(Tree->left == NULL)
		return Tree;
	else
		return BST_SearchMinNode(Tree->left);
}

void BST_InsertNode(BSTNode *Tree, BSTNode *Child)
{
	if(Tree->data < Child->data)
	{
		if(Tree->right == NULL)
			Tree->right = Child;
		else
			BST_InsertNode(Tree->right, Child);
	}
	else if(Tree->data > Child->data)
	{
		if(Tree->left == NULL)
			Tree->left = Child;
		else
			BST_InsertNode(Tree->left, Child);
	}
}

BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *Parent, ElementType Target)
{
	BSTNode *Removed=NULL;

	if(Tree==NULL)
		return NULL;

	if(Tree->data > Target)
		Removed = BST_RemoveNode(Tree->left, Tree, Target);
	else if(Tree-> data < Target)
		Removed = BST_RemoveNode(Tree->right, Tree, Target);
	else
	{
		Removed=Tree;

		if(Tree->left == NULL && Tree->right == NULL)
		{
			if(Parent->left == Tree)
				Parent->left=NULL;
			else
				Parent->right = NULL;
		}
		else
		{
			if(Tree->left !=NULL && Tree->right != NULL)
			{
				BSTNode *MinNode = BST_SearchMinNode(Tree->right);
				MinNode = BST_RemoveNode(Tree, NULL, MinNode->data);
				Tree->data = MinNode->data;
			}
			else
			{
				BSTNode *Temp = NULL;
				if(Tree->left != NULL)
					Temp=Tree->left;
				else
					Temp=Tree->right;

				if(Parent->left == Tree)
					Parent->left=Temp;
				else
					Parent->right=Temp;
			}
		}
	}

	return Removed;
}

void BST_InorderPrintTree(BSTNode *Node)
{
	if(Node ==NULL)
		return ;

	BST_InorderPrintTree(Node->left);

	printf("%d ",Node->data);

	BST_InorderPrintTree(Node->right);
}



