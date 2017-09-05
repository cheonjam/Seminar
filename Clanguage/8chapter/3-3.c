#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data
{
	char name[20];
	char tel[20];
}data;

void add(data *person);
void find(data *person);
void all(data *person);

int i=0;

int main()
{
	char command[7];
	int a=0;
	data person[10]={};
	
	while(1)
	{
		printf("What do you want Command(add, find, all):");
		scanf("%s",command);
	
		if(!strcmp(command,"add"))
		{
			if(i<10)
				add(person);
			else
				printf("person too much!!\n"); // too much
		}
		else if(!strcmp(command,"find"))
			find(person);
		else if(!strcmp(command,"all"))
			all(person);
		else
			printf("Incorrect command!!\n");
		
	}
}

void add(data *person)
{
	int j,k;
	printf("Add name : ");
	scanf("%s",person[i].name);
	if(person[i].name[0]=='.') 
		exit(0);		
	for(j=0;j<i;j++) //samename//
	{
		if(!strcmp(person[i].name,person[j].name))
		{
			printf("Same name is exist.\n");
			return ;
		}
	}		
	printf("Add telephone : ");
	scanf("%s",person[i].tel);
	i++;
}


void find(data *person)
{
	char findname[20];
	int j;

	printf("Find name : ");
	scanf("%s",findname);

	if(findname[0]=='.')
		exit(0);
	for(j=0;j<10;j++)
	{
		if(!strcmp(person[j].name,findname))
		{
			printf("telephone : %s\n",person[j].tel);
			return ;
		}
	}
	
	printf("Not find name!!\n");
}

void all(data *person)
{
	int j;
	
	for(j=0;j<i;j++)
		printf("[%d]Name:%s     \t tel:%s \n",j+1,person[j].name,person[j].tel);

}

