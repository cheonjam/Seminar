#include "head.h"

int Calculate()
{
	static char infix[MAX], postfix[MAX], tmp[MAX];
	double result;
	top=-1;

	printf("Input Calculation expression\n");
	fgets(infix,sizeof(infix),stdin);
	printf("===================================\n\n");
	if(strlen(infix)-1>MAX)
		return err_print("Fomula is very long",'_');

	infix[strlen(infix)-1]='\0';

	Delete_Space(infix, tmp);

	if(exception(tmp)==-1)
	{
		printf("\n===================================\n");
		return -1;
	}

	set(tmp);

	change(tmp,postfix);
	printf("postfix:%s\n",postfix);


	if(operate(postfix,&result))
	{
		printf("\n===================================\n");
		return -1;
	}

	printf("\033[32m   result:\033[0m %g\n",result);
	printf("\n===================================\n");

	return 0;
}
