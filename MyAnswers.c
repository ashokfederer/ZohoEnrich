//Bit Manipulations
#include <stdio.h>
#include<math.h>

unsigned int findn(unsigned int num,int n)
{
	unsigned int temp;
	temp=pow(2,n);
	temp=temp&num;
	if(temp!=0)
		return 1;
	else
		return 0;
}

unsigned int setn(unsigned int num,int n)
{
	unsigned int res,temp;
	temp=pow(2,n);
	res=num|temp;
	return res;
}

unsigned int unsetn(unsigned int num,int n)
{
	unsigned int res,temp;
	temp=pow(2,n);
	temp= ~temp;
	res=temp&num;
	return res;
}

unsigned int togglen(unsigned int num,int n)
{
	int res,temp;
	temp=pow(2,n);
	res=temp^num;
	return res;
}

unsigned int toggleothers(unsigned int num,int n)
{
	unsigned int temp,res;
	temp=pow(2,n);
	temp=~temp;
	res=temp^num;
	temp=255;
	res=res&temp;
	return res;
}

unsigned int rightrotate(unsigned int num)
{
	unsigned int temp,res;
	if(num%2==1)
	{
		num=num>>1;
		temp=128;
		res=num|temp;
	}
	else
		res=num>>1;
	res=res&255;
	return res;
}

unsigned int leftrotate(unsigned int num)
{
	int res;
	if(num/128>0)
	{
		num=num<<1;
		res=num+1;
	}
	else
		res=num<<1;
	res=res&255;
	return res;
}

unsigned int swap(unsigned int num)
{
	int res;
	res=(num<<4)|(num>>4);
	res=res&255;
	return res;
	
}

unsigned int binary(unsigned int num)
{
	unsigned int i=1,res=0;
  while(num)
  {
        res=res+(num%2)*i;
        i=i*10;
        num=num/2; 
   }	
	return res;
	
}


int main(void) {
	unsigned int num,temp,rr,lr,sw;
	int n;
	printf("Enter a number and bit position :");
	scanf("%u%d",&num,&n);
	temp=num;
	printf("\nnth bit : %d",findn(num,n));
	
	num=setn(num,n);
	printf("\nSetting nth bit : %u",binary(num));
	printf("\t%u",num);
	
	num=unsetn(num,n);
	printf("\nUnsetting nth bit : %u",binary(num));
	printf("\tDecimal Equivalent : %u",num);
	
	num=togglen(num,n);
	printf("\nToggling nth bit : %u",binary(num));
	printf("\tDecimal Equivalent : %u",num);
	
	num=toggleothers(num,n);
	printf("\nToggling other bits : %u",binary(num));
	printf("\tDecimal Equivalent : %u",num);
	
	rr=rightrotate(temp);
	printf("\nLeft Rotate : %u",binary(rr));
	printf("\tDecimal Equivalent : %u",rr);
	
	lr=leftrotate(temp);
	printf("\nRight Rotate : %u",binary(lr));
	printf("\tDecimal Equivalent : %u",lr);
	
	sw=swap(temp);
	printf("\nSwap nibbles : %u",binary(sw));
	printf("\tDecimal Equivalent : %u",sw);
	
	return 0;
}

------------------------------------
//Bit Count
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

---------------------
// Calendar Problem
#include<stdio.h>
#include<stdlib.h>

char months[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char dayname[8][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int nday,nmonth,nyear,tempdays,flag=1;

struct date
{
    int day;
    int month,prevmonth;
    int year,prevyear;
    int dayindex;

}d;

void prevn(int n)
{
    if((nmonth==d.month)&&(nyear==d.year)&&(n<d.day))
    {
        nday = d.day - n;
    }
    else
    {
        if(n<tempdays)
            nday=tempdays-n;
        else
        {
            n=n-tempdays;
            if(nmonth==1)
            {
                nmonth==12;
                nyear--;
            }
            else
            {
                nmonth--;
            }
            
            tempdays=days[nmonth-1];
            
            if(leap(nyear)==1&&nmonth==2)
            {
                tempdays++;
            }
           
            prevn(n);
        }

    }
}

int diff(char* date1, char*date2)
{
    int i,j,n=0,temp,add,swap;
    int day1,month1,year1;
    int day2,month2,year2;
    char day1str[3],day2str[3],month1str[3],month2str[3],year1str[5],year2str[5];

    for(i=0;i<4;i++)
    {
        year1str[i]=date1[i];
        year2str[i]=date2[i];
    }
    year1str[4]='\0';
    year2str[4]='\0';
    i++;

    for(j=0;j<2;j++,i++)
    {
        month1str[j]=date1[i];
        month2str[j]=date2[i];
    }
    month1str[2]='\0';
    month2str[2]='\0';
    i++;

    for(j=0;j<2;j++,i++)
    {
        day1str[j]=date1[i];
        day2str[j]=date2[i];
    }
    day1str[2]='\0';
    day2str[2]='\0';

    day1 = convert(day1str);
    day2 = convert(day2str);

    month1 = convert(month1str);
    month2 = convert(month2str);

    year1 = convert(year1str);
    year2 = convert(year2str);

    if(year1>year2)
    {
        swap=year2;
        year2=year1;
        year1=swap;

        swap=month2;
        month2=month1;
        month1=swap;

        swap=day2;
        day2=day1;
        day1=swap;

        flag=0;
    }

    else
    {
        if(month1>month2)
        {
            swap=month2;
            month2=month1;
            month1=swap;

            swap=day2;
            day2=day1;
            day1=swap;

            flag=0;
        }
        else if(day1>day2)
        {
            swap=day2;
            day2=day1;
            day1=swap;

            flag=0;
        }
    }


    if(year1==year2)
    {
        if(month1==month2)
        {
                n=day2-day1;
                return n;
        }
        else
        {
            n=n+day2;
            
            n=n+days[month1-1]-day1;
            
            if((leap(year1)==1)&&(month1==2))
            {
                    n++;
            }
            
            month2--;
            while(month1<month2)
            {
                n=n+days[month2-1];
                if((leap(year1)==1)&&(month2==2))
                {
                    n++;
                }
                month2--;
            }
            
            return n;
        }
    }
    else
    {
        n=n+days[month1-1]-day1;
        month1++;
        while(month1<=12)
        {
            n=n+days[month1-1];
            if((leap(year1)==1)&&(month1==2))
            {
                n++;
            }
            month1++;
        }
        
        n=n+day2;
        month2--;
        while(month2>=1)
        {
            n=n+days[month2-1];
            if((leap(year2)==1)&&(month2==2))
            {
                n++;
            }
            month2--;
        }
        
        temp=year2-year1-1;
        add=temp*365;
        
        for(i=year1+1;i<year2;i++)
        {
            if(leap(i)==1)
            {
                add++;
            }
        }
        n=n+add;
        
        return n;
    }
}


int dname(char* str)
{
    int n,res;
    n=diff(str,"2016-02-29");
    if(flag==1)
    {
        res=(7-n)%7;
    }
    else
    {
        res=n%7;
    }
    return res;
}


int convert(char* str)
{
    int i,num=0;
    for(i=0;str[i]!='\0';i++)
    {
        num = (num*10) + (str[i] - 48);

    }
    return num;
}

int leap(int year)
{
    if(year%100==0)
    {
        if(year%400==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(year%4==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dayindex()
{
    int i=0,ind=0;

     for(i=0;i<d.month-1;i++)
     {
         ind = ind + days[i];
         if(i == 1)
         {
              if(leap(d.year)==1)
              {
                 ind++;
              }
         }
    }

    ind = ind + d.day;

    return ind;
}

char* tostring(int day,int month,int year)
{
    int i=0;
    char* result=(char* )malloc(11);
    for(i=3;i>=0;i--)
    {
        result[i]= (year%10) + 48;
        year=year/10;
    }
    result[4]='-';
    for(i=6;i>=5;i--)
    {
        result[i]= (month%10) + 48;
        month = month/10;
    }
    result[7]='-';

    for(i=9;i>=8;i--)
    {
        result[i]= (day%10) + 48;
        day = day/10;
    }
    result[10]='\0';

    return result;
}

int main()
{
    char str[11],date1[11],date2[11];
    char* prevdate=(char*)malloc(11);
    char stryear[5],strmonth[3],strday[3];
    int i,j,k,n,difference,daynum;

    printf("Enter date : ");
    scanf("%s",str);

    for(i=0;str[i]!='-';i++)
    {
        stryear[i]=str[i];
    }
    stryear[4]='\0';
    i++;

    for(j=0;str[i]!='-';i++,j++)
    {
        strmonth[j]=str[i];
    }
    i++;
    strmonth[2]='\0';

    for(j=0;j<2;i++,j++)
    {
        strday[j]=str[i];
    }
    strday[2]='\0';

    d.day= convert(strday);
    d.month = convert(strmonth);
    d.year = convert(stryear);

    printf("\nCurrent Year : %d",d.year);

    d.prevyear = d.year-1;
    printf("\nPrevious Year : %d",d.prevyear);

    printf("\nMonth in Number : %d",d.month);

    printf("\nMonth : %s",months+(d.month-1));

    d.prevmonth = d.month - 1;
    if(d.month==1)
    {
        printf("\nPrevious Month Name : %s",months+11);
    }
    else
    {
        printf("\nPrevious Month Name : %s",months+(d.prevmonth-1));
    }

    printf("\nDay in number : %d",d.day);

    daynum=dname(str);
    printf("\nDay : %s",dayname+daynum);

    d.dayindex = dayindex();
    printf("\nDay index of the year : %d",d.dayindex);

    tempdays=d.day;
    nmonth=d.month;
    nyear=d.year;
    printf("\nGive the number of days : ");
    scanf("%d",&n);
    prevn(n);

    prevdate = tostring(nday,nmonth,nyear);
    printf("%s",prevdate);

    printf("\nEnter two dates to find the difference : ");
    scanf("%s%s",date1,date2);
    difference=diff(date1,date2);
    printf("\nDifference between them : %d",difference);


    return 0;
}

-----
// Base Conversion
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


---------
//Election
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

----
//First Name
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

-------
//Json
struct contact_persons
{
    char* contact_id;
    char* first_name;
    char* last_name;
    char* email;
};

struct contacts
{
    char* contact_id;
    char* contact_name;
    char* street;
    char* area;
    char* city;
    struct contact_persons cp[2];
}details[2];

-------
//Knapsack Problem
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

------------
// Left Sum
#include<stdio.h>
#include<stdlib.h>
int leftsum=0;
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
}*root=NULL,*current=NULL;

struct tree* create()
{
    struct tree* temp;
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->left = temp-> right = NULL;
    if(root == NULL)
    {
        root = (struct tree*)malloc(sizeof(struct tree));
        root->left = root->right = NULL;
        current = root;
        return root;

    }
    else
    {
        return temp;
    }
}

void construct(int lvalue,int rvalue)
{
    struct tree *temp1,*temp2;
    temp1 = create();
    temp2 = create();
    temp1->data = lvalue;
    temp2->data = rvalue;
    current->left = temp1;
    current->right = temp2;

}

int isleaf(struct tree* node)
{
    if((node->left == NULL) && (node->right == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void calculate(struct tree* node)
{
    if(isleaf(node->left))
    {
        leftsum = leftsum + node->left->data;
    }
    else
    {
        calculate(node->left);
        calculate(node->right);
    }

}

int main()
{
    struct tree* root;
    current = (struct tree*)malloc(sizeof(struct tree));
    root = create();
    root->data = 10;
    construct(20,30);
    current = root->left;
    construct(40,50);
    current = root->right;
    construct(60,70);
    calculate(root);
    printf("\n Sum of left leaves : %d",leftsum);
    return 0;
}
-------
//Next Prime
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

------
//Reverse of a number 
#include <stdio.h>

int main(void) {
	// your code goes here
	int n,i,temp,res=0,trail=0,rem;
	scanf("%d",&n);
	temp=n;
	
	do						// calculating the number of trailing zeros
	{
		rem=temp%10;
		if(rem==0)
			trail++;
		temp=temp/10;
	}while(rem==0);
	
	
	while(n>0)
	{
		res=(res*10)+(n%10);
		n=n/10;
		
	}
	
	
	
	for(i=0;i<trail;i++)   //printing the trailing zeros in reverse
	{
		printf("0");
	}
	printf("%d",res);
	
	
	
	return 0;
}

-------
//Json Prettify
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len(char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        
    }
    return i;
}


/*void concat(char* str)
{
    int length = len(str);
    int i;
    for(i=0;i<length;i++)
    {
        res[reslen++]=str[i];
    }
}*/

struct contact_persons
{
    char *personid;
    char *firstname;
    char *lastname;
    char *email;
};

struct contact_details
{
    char *id;
    char *name;
    char *street;
    char *area;
    char *city;
    struct contact_persons person[2];
}contact[2];

char* toString(struct contact_details* contact)
{
    char* res;
    res = (char*)malloc(100);
    res[0]='{';
    res[1]='\n';
    strcat(res,"\t\"id\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].id);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"name\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].name);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"street\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].street);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"area\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].area);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"city\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].city);
    strcat(res,"\"");
    strcat(res,"\n");
    
    strcat(res,"\tcontact_persons : [\n");
    strcat(res,"\t\t{");
    strcat(res,"\t\t\tcontact person id : ");
    strcat(res,contact[0].person[0].id);
    
    
    
    strcat(res,"}");
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char* res;
    res = (char*)malloc(100);
    contact[0].id = "123";
    contact[0].name = "RMK";
    contact[0].street = "RSM Street";
    contact[0].area = "RSM Nagar";
    contact[0].city = "Chennai";
    contact[0].person[0].personid = "1";
    contact[0].person[0].firstname = "Ashok";
    contact[0].person[0].lastname = "Kumar";
    contact[0].person[0].email ="ashok@gmail.com";
    res=toString(contact);
    printf("%s\n",res);
    
    return 0;
}

------
//Square Root
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

-----------
//String Sort
#include <stdio.h>
int length(char *str)
{
	int len=0;	
	for(len=0;str[len]!='\0';len++)
	{
		
	}
	return len;
}


int comp(char *str1,char *str2)
{
	int i,j,flag=0;
	if(length(str1)>length(str2))
	{
		flag=1;
	}
	else if(length(str1)<length(str2))
	{
		flag=-1;
	}
	else
	{
		for(i=0,j=0;str1[i]!='\0'||str2[j]=='\0';i++,j++)
		{
			if(str1[i]>str2[j])
			{
				flag=1;
				break;
			}
			else if(str1[i]<str2[j])
			{
				flag=-1;
				break;
			}
			}
	
	}
	
	return flag;

}

int main(void) {
	// your code goes here
	char *str[]={"1", "3", "11", "100", "19", "2", "5"};
	char *temp;
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=i+1;j<7;j++)
		{
			if(comp(str[i],str[j])>0)
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	for(i=0;i<7;i++)
	{
		printf("%s ",str[i]);
	}
	
	return 0;
}

-----
// SubString
#include <stdio.h>

int main(void) {
	char str[50],res[50];
	int i=0,j=0,k=1,temp=0,len=1,start=0,stop=0;
	scanf("%s",str);
	res[0]=str[0];
	for(i=1;str[i]!='\0';i++)
	{
		j=stop;
		while(j<i)
		{

			if(str[i]==str[j])
			{
				if(len>temp)
				{
					temp=len;
					start=stop;
				}
				len=0;
				stop=i;
                		break;
			}
			j++;
		}
		len++;
		if(str[i+1]=='\0')
		{
			if(len>temp)
			{
				temp=len;
				start=stop;
			}
		}
	}
	for(i=start,j=0;j<temp;i++,j++)
	{
		res[j]=str[i];
	}
	res[j]='\0';
	printf("Longest Substring :  %s  Length : %d",res,temp);
    return 0;
}

--------------
//Sum Tree
#include <stdio.h>
#include <stdlib.h>
int flag = 1;
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
}*root=NULL;

struct tree* create()
{
    struct tree* temp;
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->right = NULL;
    temp->left = NULL;
    if(root == NULL)
    {
        root = (struct tree*)malloc(sizeof(struct tree));
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {
        return temp;
    }
}


int isleaf(struct tree* node)
{
    if((node->left == NULL) && (node->right == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int calculate(struct tree* node)
{
    
    int sum = 0;
    if(isleaf(node)==0)
    {
        if(node->right==NULL)
        {
            sum = node->left->data;
            sum = sum + calculate(node->left);
        }
        else if(node->left==NULL)
        {
            sum = node->right->data;
            sum = sum + calculate(node->right);
        }
        else
        {
            sum = sum + node->right->data + node->left->data;
            sum = sum + calculate(node->left);
            sum = sum + calculate(node->right);
        }
    }
    return sum;

}

void check(struct tree* node)
{
    if(isleaf(node)==0)
    {
        if(node->data == calculate(node))
        {
            if(node->left != NULL)
            {
                check(node->left);
            }
            if(node->right != NULL)
            {
                check(node->right);
            }
        }
        else
        {
            flag = 0;
        }
    }
}

void print(struct tree* node)
{
    printf("Printing %d ",node->data);
    if(isleaf(node)==0)
    {
        print(node->left);
        print(node->right);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct tree *current,*temp1,*temp2;
    current = create();
    current->data = 26;
    temp1 = create();
    temp2 = create();
    temp1->data = 10;
    temp2->data = 3;
    current->left = temp1;
    current->right = temp2;
    temp1 = create();
    temp2 = create();
    temp1->data = 4;
    temp2->data = 6;
    current->left->left = temp1;
    current->left->right = temp2;
    temp2=create();
    temp2->data = 3;
    current->right->right=temp2;
    check(current);
    printf("%d",flag);
    //print(current);
    return 0;
}


-----------
// Tree Traversal
#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* create()
{
    struct tree* temp;
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->left=temp->right=NULL;
    return temp;
}

void prorder(struct tree* temp)
{
    printf("%d ",temp->data);
    if(temp->left!=NULL)
    {
        prorder(temp->left);
    }
    if(temp->right!=NULL)
    {
        prorder(temp->right);
    }
}

void inorder(struct tree* temp)
{
    if(temp->left!=NULL)
    {
        inorder(temp->left);
    }
    printf("%d ",temp->data);
    if(temp->right!=NULL)
    {
        inorder(temp->right);
    }
    
}

void posorder(struct tree* temp)
{
    if(temp->left!=NULL)
    {
        posorder(temp->left);
        posorder(temp->right);
    }
    printf("%d ",temp->data);
}

int isleaf(struct tree* node)
{
    
    
}





int main(int argc, const char * argv[]) {
    // insert code here...
    struct tree* current;
    struct tree* root;
    root=create();
    current = create();
    root=current;
    current->data=5;
    
    current = create();
    current->data=2;
    root->left = current;
    
    current=create();
    current->data=12;
    root->right=current;
    
    current=create();
    current->data = -4;
    root->left->left=current;
    
    current=create();
    current->data= 3;
    root->left->right=current;
    
    current=create();
    current->data=9;
    root->right->left=current;
    
    current=create();
    current->data=21;
    root->right->right=current;
    
    current=create();
    current->data=19;
    root->right->right->left=current;
    
    current=create();
    current->data=25;
    root->right->right->right=current;
    
    prorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    posorder(root);
    return 0;
}
