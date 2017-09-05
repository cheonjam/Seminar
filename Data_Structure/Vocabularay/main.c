#include "head.h"

int main()
{
	BTreeNode *ROOT=NULL, *tmp=NULL;
	FILE *fp;
	char word[20], str1[100];
	int i=0;

	system("clear");
	while(1)
	{
		system("clear");
		memset(str1,'\0',sizeof(str1)); //Initialize str1
		memset(word,'\0',sizeof(word)); //Initialize word
		switch(menu())
		{
			case 1://Insert
					printf("Input Word :");
					scanf("%s",word);
					getchar();

					printf("Input Explain :");
					fgets(str1,sizeof(str1),stdin);

					str1[strlen(str1)-1]='\0';
					ROOT=Search(ROOT,word,str1);
					break;
					
			case 2://Find
				  	printf("Find word : ");
					scanf("%s",word);

					tmp=Find(ROOT,word);
					if(tmp)
						printf("%s : %s\n",word,tmp->explain);
					else
						printf("\033[31mNot Find \033[0m%s \n",word);
						
					break;

			case 3: //Delete
					printf("Delete word : ");
					scanf("%s",word);
					getchar();

					strcpy(str1,word);
					ROOT=Delete(ROOT,str1);

					if(!strcmp(str1,word))
						printf("\033[32mDelete is complete \033[0m%s \n",word);
					else
						printf("\033[31mNot Delete \033[0m%s \n",word);

					break;

			case 4: //Print
					system("clear");
					printf("===============Print===============\n");
					if(!ROOT)
						printf("\033[31mData is empty \033[0m%s \n",word);
					else
						Print(ROOT,str1);
					printf("===================================\n");
					getchar();
					break;

			case 5://Save
					printf("Save file name : ");
					scanf("%s",str1);

					if(!(fp=fopen(str1,"w")))
					{
						printf("file open error\n");
						return -1;
					}

					Save(ROOT,word,fp);
					fclose(fp);

					break;

			case 6:	//Initialize


					printf("Initialize file name : ");
					scanf("%s",str1);

					if(!(fp=fopen(str1,"r")))
					{
						printf("file open error\n");
						return -1;
					}

					AllDelete(ROOT);
					ROOT=Initialize(fp);

					fclose(fp);
					break;

			case 7: //Exit
					return 0;
			
			default :
					printf("Incorrect Number \n");
					break;

		}
		printf("Press Enter..");
		getchar();
	}
}

int menu()
{
	int num;

	printf("<Start Vocabulary>\n");
	printf("========Select menu=========\n");
	printf("1.Insert\n");
	printf("2.Find\n");
	printf("3.Delete\n");
	printf("4.Print\n");
	printf("5.Save\n");
	printf("6.Initialize\n");
	printf("7.exit\n");
	printf("============================\n");
	printf("Choice number : ");
	scanf("%d",&num);

	return num;
}
