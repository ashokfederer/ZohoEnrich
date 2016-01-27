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
