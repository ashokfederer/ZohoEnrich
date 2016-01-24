#include <stdio.h>
#include <math.h>

int main ()
{
   int n,res=1;
   scanf("%d",&n);
   if(n!=0)
   		res=log2(n)+1;
   printf("Bitcount : %d",res);
   return 0;
}
