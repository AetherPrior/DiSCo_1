#include<stdio.h>
#include<math.h>
#include<string.h>
int main(int argc, char **argv)
{
	int num;
	scanf("%d",&num);
	int arr[num];
	int money; 
	scanf("%d",&money);

	for(int i =0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	//-lm
	int powres = pow(2,num);

	int diff = money, numitems = 0;
	char totbit[num+1];
	for(int i = 0;i<powres;i++)
	{
		long int sum = 0;
		int temp = i;
		char bitstring[num+1];
		for(int j = 0;temp > 0;j++)
		{
			bitstring[j] =temp%2+48;
			if(temp%2)
			{
				sum +=arr[j];
			}
			temp /=2;
		}
		if(sum < money && money - sum < diff)
		{
			diff = money - sum;
			
			strncpy(totbit,bitstring,num);
			}
	}
	//printf("%d",max);
	for(int i =0;i<num;i++)
	{
		if(totbit[i] == 49) numitems++;
		}
	printf("%d\n" ,numitems);
	for(int i= 0;i<num;i++)
	{
		if(totbit[i] == 49)
		{
			printf("%d ",i+1);
 			}
	}
	printf("\b\0");

	return 0;
}
