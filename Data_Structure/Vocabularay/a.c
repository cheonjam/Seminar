#include <stdio.h>
#include <unistd.h>

int main()
{
	char str[100], str2[100], str3[100];
	FILE *fp;
	int i=0;

	printf("initialize file name : ");
	scanf("%s",str);

	printf("zz\n");
	if(!(fp=fopen(str,"r")))
	{
		printf("file open error\n");
		return -1;
	}

	printf("%d\n",fscanf(fp,"%s\t : %s\n",str2,str3));
	printf("start\n");
	while(fscanf(fp,"%s\t : %s\n",str2,str3))
	{
		printf("%st : %s\n",str2,str3);
		sleep(1);
	}

	

	fclose(fp);
	return 0;
}
