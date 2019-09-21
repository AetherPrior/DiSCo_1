#include<stdio.h>
#include<string.h>
int main(void)
{
 int n;
 scanf("%d",&n);
 int arr[n], freq[n];
 memset((void*)freq,0,sizeof(freq));
 for(int i = 0;i<n;i++)
 {
	scanf("%d",&arr[i]);
 }
 for(int i = 0;i<n;i++)
	{
	if(freq[i] == 1){continue;}
	for(int j = 0;j<n;j++)
	{
		if(i == j){continue;}
		if(freq[j] == 0 && arr[i]%arr[j] == 0)
		{
			freq[j] = 1;
		}
	}
	}
 int a[n],j=0;
 int count;
 for(int i = 0;i<n;i++)
 {
 	if(freq[i] == 0)
		{count++;a[j] = arr[i];j++;}
 }
 printf("%d\n",count);
 for(int i = 0;i<count;i++)
 {
  printf("%d ",a[i]);
 }
}
