#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct{
	int coef;
	int degree;
	struct polyNode* link;
} polyNode;

void Delete_Space(char *infix, char *tmp);
int exception(char *tmp);
int operator_exception(char buffer, char tmp, int initialize);
int dot_bracket_exception(char tmp, int initialize);
int err_print(char *err_str);
int char_parity(char tmp, char *ok_char);

