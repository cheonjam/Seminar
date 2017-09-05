#include <stdio.h>

struct data
{
	char name[20];
	char tel[20];
};

int find(struct data *person);

int main()
{
	struct data person[10]={{"aaa","bbb","ccc","ddd","eee","fff","ggg","hhh","iii","jjj"},{"010-0000-0000","010-1111-1111","010-2222-2222","010-3333-3333","010-4444-4444","010-5555-5555","010-6666-6666","010-7777-7777","010-8888-8888","010-9999-9999"}};

	int a;

	while(1)
	{
		a=find(person);
	
		if(a==-1)
			return 0;
		else
			continue;
	}				
}

int find(struct data *person)
{
	char findname[20];
	int i;

	printf("Find name : ");
	scanf("%s",findname);
	
	if(findname[0]=='.');
		return -1;
	
	for(i=0;i<10;i++)
	{
		if(!strcmp(person[i].name,findname))	
			printf("%s",person[i].tel);
	}
	
	return 0;
}
