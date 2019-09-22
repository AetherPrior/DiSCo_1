#include<stdio.h>

int main(void)
{ 
    int num;
    scanf("%d",&num);
    char a[num];
    char temp;
    scanf("%c",&temp);
    for(int i = 0;i<num;i++)
    {
        scanf("%c",&a[i]);
        scanf("%c",&temp);
    }
    /*
    for(int i = 0;i<num;i++)
    {
        printf("%c ",a[i]);
    }
	
	*/
    //copy the array
    char arr[num-2];
    int j= 0;
    for(int i = 0;i<num;i++)
    {
        if(a[i] != 'B' && a[i] != 'M')
        {
            arr[j] = a[i];
	    j++;
        }
    }
    /*
      for(int i = 0;i<num-2;i++)
    {
        printf("%c ",arr[i]);
    }
    printf("\n");
	*/
    char kacchan[num-2],deku[num-2];
    long long int N = 1<<(num-2);
    for(long long i = 0;i<N;i++)
    {
        long long temp = i;
        int cb = -1,cm = -1,count=0;
        while(count<num-2)
        {
            
            if(temp%2 == 1)
            {
		cb++;
                kacchan[cb] = arr[count];
                
            }
            else
            {
		cm++;
                deku[cm] = arr[count];
               
            }
		count++;
            temp>>=1;
        }
        if(cb == cm)
        {
            printf("M: ");
        for(int i = 0;i<num/2-1;i++)
        {
            printf("%c ",deku[i]);
        }
        printf("| B: ");
        for(int i = 0;i<num/2-1;i++)
        {
            printf("%c ",kacchan[i]);
        }
	//printf("\b\n");
        printf("\n");
        }
    }
	//printf("\b\0");
}
