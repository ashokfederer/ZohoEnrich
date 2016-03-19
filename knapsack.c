#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    int temp,*weights,*value,*number;
    float temp2,*costper;
    int *resbars,*rescount,*resbarvalue;
    int i,j,n,count,limit,resval=0,resweight=0,flag=0;
    
    printf("\nEnter the limit : ");
    scanf("%d",&limit);
    
    printf("\nEnter the number of bars : ");
    scanf("%d",&n);
    
    weights = (int*)malloc(4*n);
    value = (int*)malloc(4*n);
    number = (int*)malloc(4*n);
    costper = (float*)malloc(8*n);
    resbars = (int*)malloc(4*n);
    rescount = (int*)malloc(4*n);
    resbarvalue = (int*)malloc(4*n);
    
    
    printf("Enter weights, values and numbers of each bar : ");
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&weights[i],&value[i],&number[i]);
    }
    
    for(i=0;i<n;i++)
    {
        costper[i] = (float)value[i]/(float)weights[i];
    }
    
   
    
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(costper[i]<costper[j])
            {
                temp2=costper[i];
                costper[i]=costper[j];
                costper[j] = temp2;
                
                temp = weights[i];
                weights[i]=weights[j];
                weights[j]=temp;
            
                temp = value[i];
                value[i]=value[j];
                value[j]=temp;
            
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
            
        }
    }
    
    for(i=0;i<n;i++)
    {
        resbars[i]=weights[i];
        resbarvalue[i] = value[i];
        rescount[i]=0;
    }

    
    for(i=0;i<n;i++)
    {
        count=0;
        for(;count<number[i];count++)
        {
            if((resweight+weights[i])<=limit)
            {
                resval = resval + value[i];
                resweight = resweight + weights[i];
                rescount[i]++;
            }
            else if(resweight == limit)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        
    }
    printf("\nMaxiumum Value : %d\nWeight : %d",resval,resweight);
    printf("\n\nWeights\tValues\tCounts");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t %d\t\t %d",resbars[i],resbarvalue[i],rescount[i]);
    }
    printf("\n");
    return 0;
}
