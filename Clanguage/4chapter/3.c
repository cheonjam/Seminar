#include <stdio.h>

int main()
{
    int i, n, count=12*30;
	float sum=.0;
	double rate;

	printf("interest rate:");
	scanf("%lf",&rate);
	
	if(rate<0)
		printf("rate more than 0 !!\n");
    else
	{
		for(i=1; i <= count ; i++)
   		{
			if((i%12)==0)
			{
				sum *= 1+rate;
				sum += 100;
			}
			else 
				sum = sum + 100;
    	}
         
		printf("Save money:%.f\n",sum);
	}
        return 0;
}

