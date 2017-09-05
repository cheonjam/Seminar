#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

#define MAX_STACK_SIZE 100 
#define MAX 100

int top;

void push(char *stack, char item); //stack.c
void stackFULL(); // stack.c
char pop(char *stack); // stack.c
void stackEmpty(); // stack.c

void set(char *infix); //set.c
int Calculate(); // Calculate.c
void change(char *tmp, char *postfix); // change.c
int priority(char token); // change.c

double operate(char *postfix, double *result); // operate.c
double double_oper(double op1, double op2, char operate, double **result); // operate.c
double single_oper(double op1, char operate, double **result); // operate.c

int exception(char *tmp); // exception.c
int brackets_exception(char tmp, int flag, int initialize); // sub_exception.c
int dot_exception(char tmp, int initialize); // sub_exception.c
int operator_exception(char buffer, char tmp, int initalize);// sub_exception.c

void Menual(); // etc.c
int err_print(char *err_print, char tmp); // etc.c
void Delete_Space(char *infix, char *tmp); // etc.c
int char_parity(char tmp, char *ok_char); // etc.c


