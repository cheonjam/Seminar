#include <stdio.h>

int main()
{
	int age;
	
	printf("Your age: ");
	scanf("%d",&age);

	if(age>0)
	{
		switch(age)
		{
			case 1: 
			case 2:
			case 3:
				printf("Admission Fees : free\n");
				break;
	
			case 4:
			case 5:
			case 6:
			case 7:
				printf("Admission Fees : 100Won\n");
				break;
		
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
				printf("Admission Fees : 250Won\n");
				break;
		
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			case 18:
				printf("Admission Fees : 350Won\n");
				break;
			default:
				printf("Admission Fees : 500Won\n");
		}
	}
	else
		printf("Age more than 0 !!  \n");
	

	return 0;
}

