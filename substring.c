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
