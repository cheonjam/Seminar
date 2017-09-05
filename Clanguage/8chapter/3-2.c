#include <stdio.h>

typedef struct tag_data
{
	char name[20];
	char tel[20];
}data;

int add(data *person, int i);
int find(data *person);
void all(data *person, int i);

int main()
{
	data person[10];
	char command[10];
	int a=0;
	int i=0;

	while(1)
	{
		printf("What do you want command(add, find, all)");
		scanf("%s",command);
		
		if(!strcmp(command,"add"))
			a=add(person,i);
		else if(!strcmp(command,"find"))
			a=find(person);
		else if(!strcmp(command,"all"))
			all(person,i);

	printf("%d\n",a);
		if(a==-1)
			return 0;
	}				
}

int add(data *person, int i)
{
	printf("Input name : ");
	scanf("%s",person[i].name);

	printf("Input number : ");
	scanf("%s",person[i].tel);
	i++;

	if(person[i].name[0]=='.')
		return -1;

	return 0;
}

int find(data *person)
{
	char findname[20];
	int j;

	printf("Find name : ");
	scanf("%s",findname);
	
	if(findname[0]=='.');
		return -1;
	
	for(j=0;j<10;j++)
	{
		if(!strcmp(person[j].name,findname))	
		{
			printf("%s",person[j].tel);
			return 0;
		}
	}
	
	printf("No you find name!!\n");
}

void all(data *person, int i)
{
	int j;

	for(j=0;j<=i;j++)
		printf("[%d]Name: %s     \t tel : %s \n",j+1,person[j].name,person[j].tel);
}
