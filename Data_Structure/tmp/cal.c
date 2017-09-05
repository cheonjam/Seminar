#include "head.h"

polyNode* Calculator(char *fomula)
{
	int i=-1,j=0;
	char tmp[MAX]={};
	polyNode *array[MAX]={};
	polyNode *a;

	while(*fomula)
	{
//			printf("\n\n\n%c\n",*fomula);
		switch(*fomula)
		{
			case '(':
				tmp[j++]=*fomula++;
				while(*fomula!=')')
					tmp[j++]=*fomula++;
				tmp[j++]=*fomula;
				tmp[j]='\0';
				set(tmp,&array[++i]);
		//		printNode(array);
				
				memset(tmp,'\0',sizeof(tmp));
				j=0;
				break;

			case '+':
				i-=1;	
				array[i]=sumpolyNode(array[i],array[i+1]);
				array[i+1]='\0';
				break;

			case '-':
				i-=1;
				array[i]=subpolyNode(array[i],array[i+1]);
				array[i+1]='\0';
				break;

			case '*':
				i-=1;
				array[i]=mulpolyNode(array[i],array[i+1]);
				array[i+1]='\0';
				break;
		}
//		printf("next fomula %c\n",*fomula);
		fomula++;
	}

	return array[0];
}

polyNode* sumpolyNode(polyNode *headA, polyNode *headB)
{
	polyNode *last, *NodeA, *NodeB;

//	printf("sumpoly start\n");
	NodeA=headA;
	NodeB=headB;

//	printNode(&NodeA);
//	printNode(&NodeB);
	for(NodeA=headA;NodeA;NodeA=NodeA->next)
	{
		for(NodeB=headB;NodeB;NodeB=NodeB->next)
		{
			if(NodeA->expo == NodeB->expo)
			{
				NodeA->coef=(NodeA->coef+NodeB->coef);
				if(NodeB == headB)
				{
					if(!headB->next)
					{
						free(headB);
						headB=NULL;
						break;
					}
					headB=NodeB->next;
					free(NodeB);
					NodeB=headB;
				}
				else
				{
					for(last=headB; last->next!=NodeB ; last=last->next)
						;
					last->next=NodeB->next;
					free(NodeB);
					NodeB=last;
				}
			}
		}
	}

	for(last=headA; last->next ; last=last->next)
		;
	last->next=headB;

//	printf("sumpoly end\n");
	return headA;
}

polyNode* subpolyNode(polyNode *headA, polyNode *headB)
{
	polyNode *last, *NodeA, *NodeB;

	NodeA=headA;
	NodeB=headB;

	for(NodeA=headA;NodeA;NodeA=NodeA->next)
	{
		for(NodeB=headB;NodeB;NodeB=NodeB->next)
		{
			if(NodeA->expo == NodeB->expo)
			{
				NodeA->coef=(NodeA->coef-NodeB->coef);
				if(NodeB == headB)
				{
					if(!headB->next)
					{
						free(headB);
						headB=NULL;
						break;
					}
					headB=NodeB->next;
					free(NodeB);
					NodeB=headB;
				}
				else
				{
					for(last=headB; last->next!=NodeB ; last=last->next)
						;
					last->next=NodeB->next;
					free(NodeB);
					NodeB=last;
				}
			}
		}
	}

	for(last=headA; last->next ; last=last->next)
		;
	last->next=headB;

	return headA;
}

polyNode* mulpolyNode(polyNode *headA, polyNode *headB)
{
	polyNode *mulNode,*NodeA, *NodeB, *last, *tmp; 
	float sum_coef=0;

	mulNode=(polyNode *)malloc(sizeof(polyNode));
	mulNode->next=NULL;
	
	for(NodeA=headA;NodeA;NodeA=NodeA->next)
	{
		for(NodeB=headB;NodeB;NodeB=NodeB->next)
			addPolyNode(&mulNode,(NodeA->coef*NodeB->coef),(NodeA->expo+NodeB->expo));
	}

	freeNode(NodeA);
	freeNode(NodeB);
	
	return mulNode;
}
