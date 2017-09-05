#include <stdio.h>

struct sinfo
{
	char *name;
	char *address;
	char *socialnum;
	int *age;
	char sex;
	char phoneNo[20];
};

struct score
{
	int korea;
	int english;
};
	
struct student
{
	struct sinfo *studentInfo;
	struct score *scoreInfo;
	struct student *next;
	struct student *prev;
};

int main()
{
	char command[10];

	while(1)
	{

	printf("	
