#include <stdio.h>

struct student
{
	char name[20];
	int number;
	int korea;
	int english;
	double everage;
};

void readData(struct student *std);
void calAverage (struct student *std);
void printData(struct student *std);

int main()
{
	struct student std[3];

	printf("%d\n",sizeof(std[0]));
//	readData(std);
//	calAverage(std);
//	printData(std);

	return 0;
}


void readData(struct student *std)
{
	int i;

	for(i=0;i<3;i++)
	{
		printf("Student%d Name :",i+1);
		scanf("%s",std[i].name);
		printf("Student%d number : ",i+1);
		scanf("%d",&std[i].number);
		printf("Stduent%d korean score : ",i+1);
		scanf("%d",&std[i].korea);
		printf("Student%d english score : ",i+1);
		scanf("%d",&std[i].english);
	}	
}


void calAverage (struct student *std)
{
	int i,a,b;

	for(i=0;i<3;i++)
	{
		a=std[i].korea;
		b=std[i].english;
		std[i].everage = (a+b)/2.0;
		printf("Student%d everage : %lf\n",i+1, std[i].everage);
	}
}		


void printData(struct student *std)
{
	int i;

	for(i=0;i<3;i++)
	{
		printf("\t<Student%d>\n",i+1);
		printf("Name    : %s\n",std[i].name);
		printf("Number  : %d\n",std[i].number);
		printf("Korea   : %d\n",std[i].korea);
		printf("English : %d\n",std[i].english);
		printf("Everage : %.2lf\n",std[i].everage);
	}
}
