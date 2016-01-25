#include<stdio.h>
int main(){
     int n,base,res[50],i=0,j,rem;
     printf("Enter the number : ");
     printf("\nEnter the base : ");
     scanf("%d%d",&n,&base);
    while(n>0){
        rem=n%base;
        if(rem<10)
        	res[i]=rem+48;
        else
        	res[i]=rem+55;
        n=n/base; 
    	i++;
    }
    printf("\nResult : ");
    for(j=i-1;j>=0;j--)
    {
    	printf("%c",res[j]);
    }
    	return 0;
}
