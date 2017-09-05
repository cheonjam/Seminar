#include <stdio.h>
#include <limits.h>

int main()
{
	printf("Size of int \t: %d byte\n",sizeof(int));
	printf("Size of long \t: %d byte\n",sizeof(long));
	printf("Size of float \t: %d byte\n",sizeof(float));
	printf("Size of double \t: %d byte\n\n",sizeof(double));
	
	printf("Int_Max \t: %d\n",INT_MAX);
	printf("long_Max \t: %ld\n",LONG_MAX);

	return 0;
}

