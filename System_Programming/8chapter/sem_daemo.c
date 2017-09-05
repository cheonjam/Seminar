#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void semaphore_handler(char *);
void semaphore_racing(int, char *);
int semaphore_up(int);
int semaphore_down(int);
int init_semaphore(char *);

static struct sembuf lock = {0, -1, SEM_UNDO};
static struct sembuf unlock = {0, 1, SEM_UNDO};
extern int errno;

void main(int argc, char *argv[])
{
	int sem_id;

	if( (sem_id = init_semaphore(argv[1])) < 0 )
	{
		printf("init_semaphore fail!!\n");
		exit(1);
	}
	semaphore_handler(argv[1]);
	printf("[%d]:Parent:all child terminated!\n", getpid());
	msgctl(sem_id, IPC_RMID, 0);
	exit(0);
}

void semaphore_handler(char *path)
{
	int i=0, pid=0, status=0;

	for(i=0; i<5; i++)
	{
		if( (pid = fork()) == -1 )
		{
			perror("fork : ");
			break;
		}
		else if(pid==0)
		{
			pid=getpid();
			printf("\t[%d] Create Process\n", pid);
			semaphore_racing(pid, path);
			printf("\t[%d] process terminate!\n", pid);
			exit(0);
		}
	}

	while( wait(&status)!= -1);
}

void semaphore_racing(int p_id, char *path)
{
	int semid=0;

	if( (semid=init_semaphore(path)) < 0 )
	{
		perror("");
		return ;
	}

	printf("\t\t[%d] process before critical section\n", p_id);
	if( semaphore_down(semid) < 0 )
	{
		perror("");
		return ;
	}

	printf("*******************************************\n");
	printf("[%d] process in critical section!\n", p_id);
	printf("*******************************************\n");
	sleep(5);

	if( semaphore_up(semid) < 0)
	{
		perror("");
		return ;
	}
	printf("\t\t[%d] process leave critical section!\n",p_id);
}

int semaphore_up(int semid)
{
	if(semop(semid, &unlock, 1)==-1)
	{
		perror("");
		return -1;
	}
	return 0;
}

int semaphore_down(int semid)
{
	if(semop(semid, &lock, 1)==-1)
	{
		perror("");
		return -1;
	}
	return 0;
}

int init_semaphore(char *path)
{
	int semid=0;
	key_t key;

	if( (key=ftok(path,'s')) == -1 )
	{
		perror("ftok : ");
		return -1;
	}

	if( (semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666)) == -1 )
	{
		if(errno==EEXIST)
		{
			if( (semid = semget(key, 1, 0)) == -1 )
			{
				perror("semget : ");
				return -1;
			}
			return semid;
		}
	}
	else
	{
		if(semctl(semid, 0, SETVAL, 1)==-1)
		{
			perror("semctl : ");
			return -1;
		}
	}

	return semid;
}

