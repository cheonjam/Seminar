#include <stdio.h>
#include <string.h>

typedef struct data
{
	char name[20];
	char tel[20];
}data;

void add(data *person);
void delete(data *person);
void find(data *person);

int main()
{
	int i;
	char command[7];
	data person[50]={};
	while(1)
	{
		printf("What do you want Command(add, delete, find, quit):");
		scanf("%s",command);
	
		if(!strcmp(command,"quit"))
			return 0;
		
		else if(!strcmp(command,"add"))
			add(person);

		else if(!strcmp(command,"delete"))
			delete(person);

		else if(!strcmp(command,"find"))
			find(person);

		else
			printf("Incorrect command!!\n");
	}
}

void add(data *person)
{
	int i;
		printf("a1a\n");
	for(i=0;i<50;i++)
	{
		printf("%s\n",person[i].name);
		if(!person[i].name)
		{
			printf("a\n");
			printf("Add name : ");
			scanf("%s",person[i].name);
			printf("Add telephone : ");
			scanf("%s",person[i].tel);
		}	
	}
}


void delete(data *person)
{
	char delname[20];
	int i;

	printf("Delete name : ");
	scanf("%s",delname);

	for(i=0;i<50;i++)
	{
		if(!strcmp(person[i].name,delname))
			{
				person[i].name[0]='\0';
				person[i].tel='\0';
				break;
			}
	}
}

void find(data *person)
{
	char findname[20];
	int i;

	printf("Find name : ");
	scanf("%s",findname);

	for(i=0;i<50;i++)
	{
		if(!strcmp(person[i].name,findname))
			{
				printf("telephone : %s",person[i].tel);
				break;
			}
	}
}

