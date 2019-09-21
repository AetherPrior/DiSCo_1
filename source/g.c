
#include<stdio.h>
#define ll long long
#define f(i,a,b) for(ll i = a;i<b;i++)
int main(void)
{
    int N;
    scanf("%d",&N);
    ll num = 2<<N;
    f(i,0,num)
    {
       ll temp = i;
       printf("%lld: ",i);
       f(j,0,N)
       {
           ll t2 = temp|1<<j;
           if(t2 != temp)
                printf("%lld ",t2);
       } 
       printf("\n");
    }
}