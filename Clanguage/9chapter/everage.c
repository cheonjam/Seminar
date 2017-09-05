#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char fname[100];
	int number,count =0;
	char name[20];
	float score, total = 0.0;

	printf("Input scorefile name: ");
	scanf("%s",fname);
	
	if( (fp=fopen(fname,"w")) == NULL )
	{
		fprintf(stderr,"%s Not open !!\n",fname);
		exit(1);
	}

	while(1)
	{	
		printf("Input Number, Name and Score : ");
		scanf("%d",&number);
		if(number<0) break;
		scanf("%s" "%f",name, &score);
		fprintf(fp,"%d %s %f \n", number, name, score);
	}
	fclose(fp);

	if( (fp=fopen(fname,"r"))==NULL)
	{
		fprintf(stderr,"%s Not open !!\n",fname);
		exit(1);
	}
	
	while(!feof(fp))
	{
		fscanf(fp, "%d %s %f",&number,name,&score);	
		total+=score;
		count++;
	}

	printf("everage = %f\n" ,total/count);
	fclose(fp);

	return 0;
}
