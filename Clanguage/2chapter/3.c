#include <stdio.h>

int main()
{
	int price , pen , money ;

	printf("pen price :");
	scanf("%d",&price);
	
	printf("number of pen :");
	scanf("%d",&pen);

	printf("money :");
	scanf("%d",&money);

	if(money<0)
		printf("You Don't have Money!!!\n");
	else if(price*pen<=money)
		printf("change : %d\n" , money-price*pen);
	else
		printf("need of money : %d\n", price*pen-money);
		
	return 0;
}

