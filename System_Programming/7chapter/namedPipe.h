#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct message {
	char privfifo[15];
	char filename[100];
};

#define PUBLIC "Public"
#define LINESIZE 512
#define NUMTRIES 3

