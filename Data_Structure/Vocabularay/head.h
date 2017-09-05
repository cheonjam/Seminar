#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100

typedef struct _bTreeNode
{
	char word;
	char explain[100];
	struct _bTreeNode *child;
	struct _bTreeNode *sibling;
}BTreeNode;

BTreeNode* Search(BTreeNode *bt, char *word, char *explain); //Insert.c
BTreeNode* Insert(BTreeNode *bt, char *word, char *explain); //Insert.c
void Print(BTreeNode *bt, char *tmp); //Print.c
BTreeNode* Find(BTreeNode *bt, char *word); //Find.c
BTreeNode* Delete(BTreeNode *bt, char *word); //Delete.c
void Save(BTreeNode *bt, char *tmp, FILE *fp); //Save.c
BTreeNode *Initialize(FILE *fp); //Save.c

void AllDelete(BTreeNode *bt); //Delete.c

int menu(); //main.c
