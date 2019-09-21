#include<stdio.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    char arr[N];
    char a[N];
    char temp;
    scanf("%c",&temp);
    for(int i = 0;i<N;i++)
    {
        scanf("%c",&a[i]);
        scanf("%c",&temp);
    }
    int j= 0;
    for(int i = 0;i<N;i++)
    {
        if(a[i] != 'B' && a[i] != 'M')
        {
            arr[j] = a[i];j++;
        }
    }
    int kacchan[N-2],deku[N-2];
    long long int num = 2<<(N-2);
    for(long long i = 0;i<num;i++)
    {
        long long temp = i;
        int cb = 0,cm = 0,j=0;
        while(j<N-2)
        {
            int t2= temp%2;
            if(t2 == 0)
            {
                kacchan[cb] = j;
                cb++;j++;
            }
            else
            {
                deku[cm] = j;
                cm++;j++;
            }
            temp>>=1;
        }
        if(cb == cm)
        {
            printf("B: ");
        for(int i = 0;i<N/2-1;i++)
        {
            printf("%c ",arr[kacchan[i]]);
        }
        printf("|M: ");
        for(int i = 0;i<N/2-1;i++)
        {
            printf("%c ",arr[deku[i]]);
        }
        printf("\n");
        }
    }
}