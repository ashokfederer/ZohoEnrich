#include <stdio.h>

int main(void) {
	// your code goes here
	int n,res=0;
	scanf("%d",&n);
	do
	{
		n=n/2;
		res++;
	}while(n!=0);
	printf("\nNumber of bits : %d",res);
	
	
	
	
	return 0;
}
