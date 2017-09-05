#include "echo.h"

void main()
{
	int size=0, msg_id=0;
	key_t key;
	MSG_BUF msg_buf;

	if( (key = ftok(".",'a'))==-1 )
	{
		perror("[Server] ftok() : ");
		exit(1);
	}

	if( (msg_id = msgget(key, IPC_CREAT | 0666))==-1 )
	{
		perror("[Server] msgget() : ");
		exit(2);
	}

	while(1)
	{
		if( (size=msgrcv(msg_id, &msg_buf, MAXSIZE+1, SERVER_TYPE, 0))==-1 )
		{
			perror("[Server] msgrcv() : ");
			break;
		}
		else if( size==0 )
		{
			printf("size 0 stop\n");
							
			break;
		}

		msg_buf.mtype = CLIENT_TYPE;

		if( msgsnd(msg_id, &msg_buf, strlen(msg_buf.mdata)+1, 0)==-1 )
		{
			perror("[Server] msgsnd() : ");
			break;
		}
	}

	msgctl(msg_id, IPC_RMID, 0);
	exit(0);
}
			
		
