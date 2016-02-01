#include <stdio.h>
int isprime(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main(void) {
	int n,res;
	printf("Enter a number : ");
	scanf("%d",&n);
	res=n;
	if(res%2==0)
		res++;
	while(1)
	{
		if(isprime(res))
			break;
		res=res+2;	
	}
	printf("\nThe next prime number : %d",res);
	return 0;
}
