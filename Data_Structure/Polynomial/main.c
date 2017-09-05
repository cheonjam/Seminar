#include "head.h"

int main()
{
	static polyNode* array[MAX];
	static char init_fomula[MAX], tmp[MAX], one_fomula[MAX];
	int i,j=0,k=0;

	//0.Delete space
	//1.exception
	//2.setting	(1+3x) + (5x^2 - 3) ==> (1x^0 + 3x^1) + (5x^2 - 3^1)
	//			(1+3x) - (5x^2 - 3) ==> (1^1 + 3x^1) + (-5x^2 + -3x^1)
	//			(-3x^3 - 3x -6)*(2x^2 + 1) ==> (-3x^3 - 3x^1 -6^1) * (2x^2 + 1^1)
	//			(-3x^3 - 3)/(2x^2 + 1) ==> (-3x^3 - 3^1) * (2x^-2 + 1^-1)
	//3.Linked list 
	//4.sort
	//5.Calculate
	//
	
	while(1)
	{
		memset(init_fomula,'\0',sizeof(init_fomula));
		memset(tmp,'\0',sizeof(tmp));

		printf("Input Polynomial expression\n");
		fgets(init_fomula,sizeof(init_fomula),stdin);
		init_fomula[strlen(init_fomula)-1]='\0';
	
//		Delete_Space(init_fomula,tmp);
//		if(exception(tmp)==-1)
//			continue;
		for(i=0; tmp[i]!='\0';i++)
		{
			if(tmp[i]=='(')
			{
				i++;
				while(tmp[i]!=')')
					one_fomula[j++]=tmp[i++];
				set(one_fomula,array[k++]);
			}
		}
		
	}
	
	return 0;

}
