#include <stdio.h>
#include <stdlib.h>
#include "stack_head.h"

#define TRUE 1
#define FALSE 0 

#define PATH '0' // ' '
#define WALL '1' // '@'
#define ENTER '4' // '>'
#define NOW '5' // '*'
#define PAST '6' // ' '
#define OUT '7' // '>'

void set(); // set.c
void print();// print.c
void save(); // move.c

int row,col;
char maze[14][18];
