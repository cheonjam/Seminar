#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <wait.h>
#include <unistd.h>

typedef struct {
	char data_area[1024];
	char filename[128];
	int status;
} SHARE_MEMORY;

int shm_id;
#define INVALID 1
#define REQUESTED 2
#define PROCESSED 3
