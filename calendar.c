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
