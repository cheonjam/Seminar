#include "header.h"

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

	if( (msg_id = msgget(key, 0))==-1 )
	{
		perror("[Client] msgget() : ");
		exit(2);
	}

	while(1)
	{
		memset(&msg_buf, 0x00, sizeof(MSG_BUF));
		if( (size = read(0, msg_buf.mdata, MAXSIZE)) < 0 )
		{
			perror("[Client] : read : ");
			break;
		}

		msg_buf.mtype = SERVER_TYPE;
		
		if( msgsnd(msg_id, &msg_buf, strlen(msg_buf.mdata)+1, 0)==-1 )
		{
			perror("[Client] : msgsnd : ");
			break;
		}

		if( (size=msgrcv(msg_id, &msg_buf, MAXSIZE+1, CLIENT_TYPE, 0))==-1)
		{
			perror("[Client] : msgrcv() : ");
			break;
		}

		printf("%s",msg_buf.mdata);
	}
	exit(0);
}
