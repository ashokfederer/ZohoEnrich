#include <stdio.h>

int main(void) {
	// your code goes here
	int n,res=0;
	scanf("%d",&n);
	while(n!=0)
	{
		n=n/2;
		res++;
	}
	printf("\nNumber of bits : %d",res);
	
	
	
	
	return 0;
}
