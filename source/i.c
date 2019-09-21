#include<stdio.h>
#include<string.h>
void permutate(char *arr,int start,int end)
{
    if(start == end-1)
    {
        printf("%s\n",arr);
        return;
    }
    for(int i = start;i<end;i++)
    {
        char temp = arr[start];
	arr[start] = arr[i];
	arr[i] = temp;

	permutate(arr,start+1,end);

	temp = arr[start];
	arr[start] = arr[i];
	arr[i] = temp;
    }
}
int main()
{
    char arr[11];
    scanf("%s",arr);
    int len = strlen(arr);
    permutate(arr,0,len);
}
