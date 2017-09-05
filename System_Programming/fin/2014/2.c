#include <sys/time.h>
#include <string.h>

unsigned int myalarm(unsigned int seconds)
{
	struct itimerval *old, *new;

	memset(&old, 0x00, sizeof(old));
	memset(&new, 0x00, sizeof(new));

	new.it_value.tv_sec=seconds;
	setitimer(ITIMER_REAL, &new, &old);

	if(old.it_value.tv_sec==0 && old.it_value.tv_usec==0)
		return 0;
	else
		return old.it_value.tv_sec+(old.it_value.tv_usec<500000?0:1);
	free(old);
}

