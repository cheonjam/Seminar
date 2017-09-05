#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct data
{
	char name[20];
	char tel[20];
}data;

int add(data *person, int i);
void delete(data *person);
void find(data *person);
void all(data *person, int i);

int main(int argc, char *argv[])
{
	char command[7],ch;
	int i=0,a;
	data person[MAX];

	FILE * fp=fopen(argv[1],"w");
	if(fp==NULL)
	{
		printf("file open error\n")
		return -1;
	}
	while(1)
	{
		printf("What do you want Command(add, delete, find, all, quit):");
		scanf("%s",command);
	
		if(!strcmp(command,"quit"))
		{
			while((ch=fgetc(fp))!=EOF)
				fprintf(fp,"%c",
			return 0;
		}		
		else if(!strcmp(command,"add"))
		{
			if(i>=MAX)
				printf("Full data!!\n");
			else
			{	
				a=add(person,i);
				if(!a)
					i++;
			}
		}
		else if(!strcmp(command,"delete"))
		{
			delete(person);
			i--;
		}
		else if(!strcmp(command,"find"))
			find(person);
		else if(!strcmp(command,"all"))
			all(person,i);
		else
			printf("Incorrect command!!\n");
	}
}

int add(data *person, int i)
{
	int j;

	printf("Add name : ");
	scanf("%s",person[i].name);

	for(j=0;j<i;j++)
	{
		if(!strcmp(person[i].name,person[j].name))
		{
			person[i].name[0]='\0';
			printf("Same name is exist!!\n");
			return -1;
		}
	}	

	printf("Add telephone : ");
	scanf("%s",person[i].tel);
		
	return 0;
}

void delete(data *person)
{
	char delname[20];
	int j,k;

	printf("Delete name : ");
	scanf("%s",delname);

	for(j=0;j<MAX;j++)
	{
		if(!strcmp(person[j].name,delname))
			{
				person[j].name[0]='\0';
				person[j].tel[0]='\0';
				break;
			}
	}
	
	for(;j<MAX;j++)
	{
		for(k=0;k<20;k++)
		{
			person[j].name[k]=person[j+1].name[k];
			person[j].tel[k]=person[j+1].tel[k];
		} 
	}
}

void find(data *person)
{
	char findname[20];
	int j;

	printf("Find name : ");
	scanf("%s",findname);

	for(j=0;j<MAX;j++)
	{
		if(!strcmp(person[j].name,findname))
			{
				printf("telephone : %s\n",person[j].tel);
				break;
			}
		else if(j==(MAX-1))
			printf("No you find name!!\n");
	}
}

void all(data *person, int i)
{
	int j;
	
	for(j=0;j<i;j++)
		printf("[%d]Name:%s     \t tel:%s \n",j+1,person[j].name,person[j].tel);
}
