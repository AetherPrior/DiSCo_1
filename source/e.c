#include<stdio.h>
//void resetCombindex(int arr, )
void combination(int N,int r,char arr[],int comb_index[],int count,int index)
{
    
    if(count == r)
    {
        int iar[N];
        for(int i = 0;i<N;i++)
        {
            iar[i] = 0;
        }
        for(int i = 0;i<r;i++)
        {
            iar[comb_index[i]] = 1;
        }


        char kacchan[r], deku[r];
        int ck = 0, cm = 0;
       
        for(int i = 0;i<N;i++)
        {
            if(iar[i] == 1)
            {
                kacchan[ck] = arr[i];
                ck++;
            }
            else 
            {
                deku[cm] = arr[i];
                cm++;
            }
        }
        //print
        printf("B: ");
        for(int i = 0;i<r;i++)
        {
            printf("%c ",kacchan[i]);
        }
        printf("|M: ");
        for(int i = 0;i<r;i++)
        {
            printf("%c ",deku[i]);
        }
        printf("\n");
        
        return;
    }
    if(index>=N)
    return;
    comb_index[count] = index;
    combination(N,r,arr,comb_index,count+1,index+1);
    combination(N,r,arr,comb_index,count,index+1);
}
int main(void)
{
    int N;
    scanf("%d",&N);
    char a[N];
    char temp;
    scanf("%c",&temp);
    for(int i = 0;i<N;i++)
    {
        scanf("%c",&a[i]);
        scanf("%c",&temp);
    }
    char arr[N-2];
    int j = 0;
    for(int i = 0;i<N;i++)
    {
        if(a[i]== 'M' || a[i] == 'B')
        {
            continue;
        }
        else
        {
            arr[j]= a[i];
            j++;
        } 
    }
    int comb_index[N-2];
    for(int i = 0;i<N-2;i++)
    { 
        comb_index[i] = 0;
    }
    combination(N-2,N/2-1,arr,comb_index,0,0);
}