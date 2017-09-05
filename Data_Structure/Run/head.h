#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char getbits(unsigned char x, int p, int n); // bit.c
unsigned setbits(unsigned char *x, unsigned p, unsigned n, unsigned v); //bit.c
char type0(unsigned char first, unsigned char same); // type.c
char type1(unsigned char first, unsigned char diff); // type.c
void binary_change(char *); // file.c
void Encoding(char *); // enc.c
char enc_pattern(int prev, int now, char first, char now_char);// pattern.c
int negative(int one); // neg.c
void Decoding(char *); // dec.c
int ctoi(char); // ctoi.c
void character_change(char *save); // file2.c

char same,diff;

