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
