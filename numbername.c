#include <stdio.h>

int main(void) {
	// your code goes here
	int n,n1,n2,n3;
	scanf("%d",&n);
	n1=n/100;
	switch(n1)
	{
		case 1:
			printf("One Hundred and ");
			break;
		case 2:
			printf("Two Hundred and ");	
			break;
		case 3:
			printf("Three Hundred and ");	
			break;
		case 4:
			printf("Four Hundred and ");	
			break;
		case 5:
			printf("Five Hundred and ");	
			break;
		case 6:
			printf("Six Hundred and ");	
			break;
		case 7:
			printf("Seven Hundred and ");	
			break;
		case 8:
			printf("Eight Hundred and ");	
			break;
		case 9:
			printf("Nine Hundred and ");	
			
	}
	n2=(n/10)%10;
	n3=n%10;
	if(n2==1)
	{
		switch(n3)
		{
			case 0:
				printf("Ten");
				break;
			case 1:
				printf("Eleven");
				break;
			case 2:
				printf("Twelve");
				break;
			case 3:
				printf("Thirteen");
				break;
			case 4:
				printf("Fourteen");
				break;
			case 5:
				printf("Fifteen");
				break;
			case 6:
				printf("Sixteen");
				break;
			case 7:
				printf("Seventeen");
				break;
			case 8:
				printf("Eighteen");
				break;
			default :
				printf("Ninteen");
			
		}
	}
	else
	{
		switch(n2)
		{
			case 2:
				printf("Twenty");
				break;
			case 3:
				printf("Thirty");
				break;
			case 4:
				printf("Forty");
				break;
			case 5:
				printf("Fifty");
				break;
			case 6:
				printf("Sixty");
				break;
			case 7:
				printf("Seventy");
				break;
			case 8:
				printf("Eighty");
				break;
			case 9:
				printf("Ninety");
				break;
		}
		switch(n3)
		{
			case 0:
				printf("Zero");
				break;
			case 1:
				printf(" One");
				break;
			case 2:
				printf(" Two");
				break;
			case 3:
				printf(" Three");
				break;
			case 4:
				printf(" Four");
				break;
			case 5:
				printf(" Five");
				break;
			case 6:
				printf(" Six");
				break;
			case 7:
				printf(" Seven");
				break;
			case 8:
				printf(" Eight");
				break;
			case 9:
				printf(" Nine");
				break;
			
		}
		
		
		
		
	}
	return 0;
}
