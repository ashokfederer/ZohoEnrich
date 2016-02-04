#include <stdio.h>

int main(void) {
	int num;
	float res,temp,acc = 0.000001;
	printf("Enter a number :");
	scanf("%d",&num);
	temp=1;
	res=num;
	while((res-temp) > acc)
	{
		res = (res+temp)/2;
		temp=num/res; 
	}
	printf("\nSquare root : %f",res);
	return 0;
}
