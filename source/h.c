#include<stdio.h>
#include<string.h>
int palindrome_check(int i0,int i1,char* str)
{
	int len = strlen(str);
	
	char s[1000];
	int i = 0;
	int j = 0;
	for(i = i0; i!=i1;i++)
	{
		s[j] = str[i];
		if(i == len-1){i = -1;} //loop resets it to zero
		j++;
	}
	s[j] = str[i];
	s[j+1] = '\0';
	for( i =0, j=strlen(s)-1;i<strlen(s)/2;i++,j--)
	{
		if(s[i] != s[j])return 0;
		}
	printf("%s ",s);
	return 1;
}
int main(void)
{
	char s[1000][1000];
	char temp[1001];
	int i = 0,j=0,k=0;
	char c = '\0';
	gets(temp);

	while(temp[i] != '\0')
	{
		if(temp[i] == ' ')
		{s[j][k] = '\0';k = 0;j++;i++;continue;}

		s[j][k] = temp[i];k++;i++;

	}
	s[j][k] = '\0';
	/*for(int i = 0;i<=j;i++)
	{
		printf("%s ",s[i]);
	}*/
	for(int i = 0;i<=j;i++)
	{
		int flag= 0;
		int len = strlen(s[i]);
		for(int k = 0;k<len;k++)
		{
			palindrome_check((k ==len-1)?0:k+1,k, s[i]);
		}
		
	}
	   
}
