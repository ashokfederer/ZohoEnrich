#include <stdio.h>

int main(void) {
	// your code goes here
	int n,i,temp,res=0,trail=0,rem;
	scanf("%d",&n);
	temp=n;
	
	do						// calculating the number of trailing zeros
	{
		rem=temp%10;
		if(rem==0)
			trail++;
		temp=temp/10;
	}while(rem==0);
	
	
	while(n>0)
	{
		res=(res*10)+(n%10);
		n=n/10;
		
	}
	
	
	
	for(i=0;i<trail;i++)   //printing the trailing zeros in reverse
	{
		printf("0");
	}
	printf("%d",res);
	
	
	
	return 0;
}
