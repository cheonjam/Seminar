#include <stdio.h>

int main()
{
	int month;

	printf("insert of month :");
	scanf("%d",&month);

	if(month>12)
		printf("month limit 12\n");
	else
	{
		printf("month:%d\n",month);
		printf("day:%d\n",month*30);
		printf("hour:%d\n",month*30*24);
		printf("minute:%d\n",month*30*24*60);
		printf("second:%d\n",month*30*24*60*60);
	}
	return 0;
}

