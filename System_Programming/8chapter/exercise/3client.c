#include "header3.h"

void main(int argc, char *argv[])
{
	/* share memory init */
	if((shm_id=shmget((key_t)1234,sizeof(SHARE_MEMORY),0))==-1)
	{
		perror("shmget :");
		exit(0);
	}

	if( (shm_ptr=(SHARE_MEMORY)shmat(shm_id, (void *)0, 0)) == (SHARE_MEMORY *)-1)
	{
		perror("shmat : ");
		exit(1);
	}

	/*semaphore init */
	{

	}

	while(1)
	{
		if(shm_ptr->status == PROCEED)
		{
			/* read data */	
			{

			}

			/* lock filename & status */
			{

			}

			memset(&(shm_ptr->filename), 0, sizeof(&(shm_ptr->filename)));
			shm_ptr->status = INVALID;
			
			/* unlock filename & status */
			{
			
			}
		}
		else if(shm_ptr->status == INVALID)
		{
					
			/*write filename & status*/
			{

			}

			shm_ptr->status = REQUESTED;

			/* filename & status nulock */
			{

			}
		}
	}		
}

