#include<stdio.h>
int main(){
     int n,i,base,res=0;
     printf("Enter a number to convert : ");
     printf("\nEnter a base : ");
     scanf("%d%d",&n,&base);

     i=1;
    while(n>0){
        res=res+(n%base)*i;
        i=i*10;
        n=n/base; 
    }
    printf("\nResult : %d",res); 
         return 0;
}
