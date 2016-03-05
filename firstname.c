#include <stdio.h>
#include <stdlib.h>
int strlength(char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        
    }
    return i;
}


int strcompare(char* str1,char* str2)
{
    int len1,len2,i,flag=0;
    len1=strlength(str1);
    len2=strlength(str2);
    if(len1!=len2)
    {
        flag=1;
    }
    else
    {
        for(i=0;i<len1;i++)
        {
            if(str1[i]!=str2[i])
            {
                flag=1;
                break;
            }
        }
    }
    return flag;



}
struct details
{
    char *name;
    int id;
}person[10];

struct result
{
    char *first;
    int id[10];
    int count;

}pers[10];

char* getfirstname(char* name)
{
    int i,j;
    char* res =(char* )malloc(sizeof(name));
    for(i=0,j=0;name[i]!='\0';i++)
    {
        if(name[i]!=' '&&name[i]!='.')
        {
            res[j]=name[i];
            j++;
        }
        else
        {
            if(name[i]=='.')
            {
                j=0;
            }
            else
            {
                break;
            }
        }
        
    }
    res[j]='\0';
    printf("%s",res);
    return res;
}

int compare(char* firstname,int limit)
{
    int i,temp=-1;
    for(i=0;i<limit;i++)
    {
        if(strcompare(firstname, pers[i].first)==0)
        {
            temp=i;
            break;
        }
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j,k,temp;
    char *firstname;
    firstname=(char* )malloc(50);
    for(i=0;i<5;i++)
    {
        person[i].id=i+1;
        
    }
    person[0].name="B.Raghav";
    person[1].name="Ashok V";
    person[2].name="Raghav Bala";
    person[3].name="Suresh Ramalingam";
    person[4].name="KM.Suresh";
    
    for(i=0,j=0,k=0;i<5;i++)
    {
        firstname = getfirstname(person[i].name);
        temp = compare(firstname,j);
        pers[j].first =(char* )malloc(50);
        if(temp==-1)
        {
            pers[j].first = firstname;
            pers[j].count=1;
            pers[j].id[pers[j].count-1]=person[i].id;
            j++;
        }
        else
        {
            pers[temp].count++;
            pers[temp].id[pers[temp].count-1]=person[i].id;
        }
    }
    for(i=0;i<j;i++)
    {
        printf("\n%s , %d, ",pers[i].first,pers[i].count);
        printf("[");
        for(k=0;k<pers[i].count;k++)
        {
            printf("%d ",pers[i].id[k]);
        }
        printf("]");
    }
    
    
    return 0;
}
