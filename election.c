#include <stdio.h>
#include <stdlib.h>
struct contestant
{
    char name[50];
    int votes;
}*cont;

int findmax(int num)
{
    int i,res=0;
    for(i=0;i<num;i++)
    {
        if(cont[i].votes>res)
        {
            res = i;
        }
    }
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int i,num,ch,vote,nota=0,count=0;
    
    printf("\nEnter number of contestants : ");
    scanf("%d",&num);
    cont = (struct contestant*)malloc(sizeof(struct contestant)*num);
    
    printf("\nEnter contestant names : \n");
    for(i=0;i<num;i++)
    {
        scanf("%s",cont[i].name);
    }
    for(i=0;i<num;i++)
    {
        cont[i].votes = 0;
    }
    while(1)
    {
        printf("\nDo you wish to cast your vote?\n1.Yes\n2.No\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nThe contestants participating are : \n");
            for(i=0;i<num;i++)
            {
                printf("%d.",i+1);
                printf("%s\n",cont[i].name);
            }
            printf("Cast your vote : ");
            scanf("%d",&vote);
            if(vote>0&&vote<=num)
            {
                for(i=0;i<num;i++)
                {
                    if(i==vote-1)
                    {
                        cont[i].votes++;
                        break;
                    }
                }
            }
            else
            {
                nota++;
            }
        }
        else if(ch==2)
        {
            break;
        }
        else
        {
            printf("\nEnter a proper choice : 1 or 2!");
        }
    }
    printf("\nResults are : \n");
    for(i=0;i<num;i++)
    {
        printf("\n%s : %d",cont[i].name,cont[i].votes);
    }
    printf("\nNOTA : %d",nota);
    count = findmax(num);
    printf("\nThe winner is : %s",cont[count].name);
    printf("\nThank you for using this service!\n");
    return 0;
}
