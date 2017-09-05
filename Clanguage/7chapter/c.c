#include <stdio.h>

int main()
{
	char str2[10]="abcdefg" ,  str3[10]="bcccdefasg";
	int i=0;	
	while(1)
	{
		if(*(str2+i)=='\0' && *(str3+i)=='\0')
			return 0;
		
		else if(*(str2+i)>*(str3+i))
			return 1;
		
		else if(*(str2+i)<*(str3+i))
			return -1;
		
		else if(*(str2+i)==*(str3+i))
		{	
			i++;
			continue;
		}


	}
}
