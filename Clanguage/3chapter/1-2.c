#include <stdio.h>

int main()
{
	int age;

	printf("your age : ");
	scanf("%d",&age);

	if(age<0)
		printf("Youger than 0 years old\n");
	else if(age<=3)
		printf("Admission fees : Free\n");
	else if(age<=7)
		printf("Admission fees : 100Won\n");
	else if(age<=12)
		printf("Admission fees : 250Won\n");
	else if(age<=18)
		printf("Admission fees : 350Won\n");
	else
		printf("Admission fees : 500Won\n");

	return 0;
}
