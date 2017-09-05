#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 100
#define STATE_COEF 1
#define STATE_EXPO 2

struct PolyNode{
	float coef;
	int expo;
	struct PolyNode* next;
};

typedef struct PolyNode polyNode;

void Delete_Space(char *infix, char *tmp);
int operator_exception(char buffer, char tmp, int initialize);
int dot_bracket_exception(char tmp, int initialize);
int err_print(char *err_str);
int char_parity(char tmp, char *ok_char);

void set(char *fomula, polyNode **array);

void addPolyNode(polyNode **head, float coef, int expo);
void printNode(polyNode **head);

polyNode* Calculator(char *fomula);
polyNode* sumpolyNode(polyNode *headA, polyNode *headB);
polyNode* subpolyNode(polyNode *headA, polyNode *headB);
polyNode* mulpolyNode(polyNode *headA, polyNode *headB);

void changeNode(polyNode **head, polyNode *a, polyNode *b);
void sortNode(polyNode **head);
void settingNode(polyNode **head);
void freeNode(polyNode *head);

void postfix(char *fomula);
int priority(char token);

int exception(char *tmp, char *fomula);
