#include "phonebook.h"

void main(int argc, char **argv)
{
	int fd=0, size=0;
	char index[10];
	PHONEBOOK phonebook;

	if( argc < 2)
	{
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(-1);
	}

	if( (fd = open(argv[1], O_RDONLY)) < 0 )
	{
		perror(argv[1]);
		exit(-2);
	}

	while(1)
	{
		memset(&phonebook, 0x00, sizeof(PHONEBOOK));
		memset(index, 0x00, sizeof(index));

		fprintf(stderr, "Insert Customer Name : ");
		fflush(stderr);
		
		if((size=read(0, index, sizeof(index))) < 0)
			break;

		index[size]='\0';
		if( atoi(index) < 0 )
		{
			fprintf(stderr, "#### invaild Record Number ####\n");
			break;
		}

		lseek(fd, (long) atoi(index)*sizeof(PHONEBOOK), SEEK_SET);

		if( read(fd, (char *)&phonebook, sizeof(PHONEBOOK)) <= 0 )
			break;

		printf("Customer Name : %-50s, Phone NUmber : %-20s\n",phonebook.name, phonebook.phonenumber);
	}
	
	close(fd);
	exit(0);
}
