#include "head.h"

int main()
{
	int exep=0;
	char infix[MAX]={}, postfix[MAX]={}, tmp[MAX]={};
	double result;
	BTreeNode *bt;
	top=-1;

	while(1)
	{
		printf("Input Calculation expression\n");
		fgets(infix,sizeof(infix),stdin);
		printf("===================================\n\n");

		if(strlen(infix)-1>MAX)
		{
			err_print("Fomula is very long",'_');
			continue;
		}
	
		infix[strlen(infix)-1]='\0';
		
		Delete_Space(infix, tmp);
	
		if(exception(tmp)==-1)
		{
			printf("\n===================================\n");
			memset(infix,'\0',sizeof(infix));
			memset(tmp,'\0',sizeof(tmp));
			top=-1;
			continue;
		}
	
		set(tmp);
		change(tmp,postfix);
		
		//printf("postfix : %s\n",postfix);

		bt=MakeTree(postfix);
		printf("[Preorder] :");
		PreorderTraverse(bt);
		printf("\n");
		printf("[Inorder]  :");
		InorderTraverse(bt);
		printf("\n");
		printf("[Postorder]:");
		PostorderTraverse(bt);
		printf("\n\n");

		result=Calculate(bt,&exep);		
		if(exep==-1)
		{
			exep=0;
			printf("\n===================================\n");
			AllNodeFree(bt);
			continue;
		}
			
		printf("\033[32m \tresult:\033[0m %g\n",result);
		printf("\n===================================\n");
		
		AllNodeFree(bt);
		memset(infix,'\0',sizeof(infix));
		memset(tmp,'\0',sizeof(tmp));
		memset(postfix,'\0',sizeof(postfix));
		top=-1;
	}
		return 0;
}
