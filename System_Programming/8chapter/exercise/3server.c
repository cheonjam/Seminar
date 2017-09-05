#include "header3.h"

void mian(int argc, char *argv[])
{
	SHARE_MEMORY *shm_ptr;
	int fd;

	/* share memory init */
	if((shm_id=shmget((key_t)1234, sizeof(SHARE_MEMORY), IPC_CREAT|0666))==-1)
	{
		perror("shmget :");
		exit(0);
	}

	if((shm_ptr=(SHARE_MEMORY *)shmat(shm_id, (void *)0, 0))==(SHARE_MEMORY *)-1)
	{
		perror("shmat :");
		exit(1);
	}

	/* semaphore init */
	{

	}

	while(1)
	{
		if(shm_ptr->status == REQUESTED)
		{
			/* lock entire block*/
			{

			}

			if((fd=open(&(shm_ptr->filename),O_RDONLY))==-1)
			{
				perror("open :");
				exit(2);
			}
			while(read(fd,shm_ptr.data_area,1024));
			
			shm_ptr->status = PROCESSED;
			close(fd);

			/* unlock entire block */
			{

			}
		}

	}

	/* detach memory */
	{

	}
}
