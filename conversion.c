#include<stdio.h>
int main(){
     int n,shift=1,base,res=0;
     printf("Enter the number : ");
     printf("\nEnter the base : ");
     scanf("%d%d",&n,&base);

    while(n>0){
        res=res+(n%base)*shift;
        shift=shift*10;
        n=n/base; 
    }
    printf("\nResult : %d",res); 
         return 0;
}
