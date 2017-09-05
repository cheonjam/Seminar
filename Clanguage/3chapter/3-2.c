#include <stdio.h>

int main()
{
	double korean, english, math;
	
	printf("Insert of your Korean score :");
	scanf("%lf",&korean);
	printf("Insert of your English score :");
	scanf("%lf",&english);
	printf("Insert of your Math score :");
	scanf("%lf",&math);

	
	if(korean>=60 && english>=60 && math>=60 && (korean*math/3)>=70)
	{
		if(english>=60)
		{
			if(math>=60)
			{
				if(korean*english*math/3>=70)
					printf("Success!!\n");
				else
					printf("Fail!!\n");
			}
			else
				printf("Fail!!\n");
		}
		else printf("Fail!!\n");
	}
	else printf("Faill!!\n");
	
	return 0;
}

