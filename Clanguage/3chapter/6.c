#include <stdio.h>

int main()
{
	int Question ;
	int number;
	int age;
	double a,b;
	double korean, english, math;

	printf("you want question(1~4) : ");
	scanf("%d",&Question);

	switch(Question)
	{

	case 1://Question1

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

	break;

	case 2://Question2

			printf("First number : ");
	       	scanf("%lf",&a);
	       	printf("Second number : ");
       		scanf("%lf",&b);

	        if(a>b)
	                printf("A high number : %.lf\n",a);
        	else
                	printf("A high number : %.lf\n",b);

        break;	


	case 3://Question3

        printf("Insert of your Korean score :");
        scanf("%lf",&korean);
        printf("Insert of your English score :");
        scanf("%lf",&english);
        printf("Insert of your Math score :");
        scanf("%lf",&math);

        if(korean < 0 || english <0 || math <0)
        	printf("Wrong Score!! (score>0)\n");
		else if(korean >100 || english >100 || math >100)
			printf("Wrong Score!! (Score<100)\n");
        else if(korean>=60 && english>=60 && math>=60 && (korean*math/3)>=70)
        	printf("your pass!!\n");
        else
      		printf("your not pass!!\n");

		break;

	case 4://Question4

        printf("Insert of number : ");
        scanf("%d",&number);

        switch(number%2)
        {
                case 1:
                case -1:
                printf("Odd number%d\n",number%2);
                break;

                case 0:
                printf("Even number\n");
                break;
        }

	break;

	default:
		printf("Wrong Number!!(1~4)\n");
	}
		
	return 0;
}
	
