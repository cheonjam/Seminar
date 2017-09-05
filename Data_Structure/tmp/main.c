#include "head.h"

int main()
{
	polyNode *result;
	static char fomula[MAX], tmp[MAX];

	while(1)
	{
		printf("Input Polynomial expression\n");
		fgets(fomula,sizeof(fomula),stdin);
		fomula[strlen(fomula)-1]='\0';

		if(exception(tmp,fomula))
			continue;
//		printf("exeption\n");
		postfix(tmp);
//		printf("postfix\n");
		result=Calculator(tmp);
//		printf("calculator\n");

		sortNode(&result);
		settingNode(&result);

		printf("===========result=========\n");
		printNode(&result);

		freeNode(result);
		memset(fomula,'\0',sizeof(fomula));
		memset(tmp,'\0',sizeof(tmp));
		result=NULL;

	}
		
	return 0;
}
