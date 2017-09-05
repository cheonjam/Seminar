void main(argc,argv)
int argc;
char *argv[];
{
	int fork(), wait();

	if(fork() ==0)
		execl("/bin/echo","echo","this is","message one",(char *)0);
	if(fork() ==0)
		execl("/bin/echo","echo","this is","message two",(char *)0);
	printf("parent: wating for children\n");

	while(wait((int *) 0) != -1);

	printf("paretn : all children terminated\n");
	exit(0);
}

