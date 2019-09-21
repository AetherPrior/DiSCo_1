#include<stdio.h>
#include<stdlib.h>
int** matsq(int** mat,int **mat2,int n)
{
 
 //int sum = 0;
 for(int i = 1;i<=n;i++)
 {
	//sum = 0;
	for(int j = 1;j<=n;j++)
	{
		for(int k = 1;k<=n;k++)
			mat2[i][j] += mat[i][k]*mat[k][j];
			
	}
 }
 return mat2;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int **arr = (int **)malloc((n+1)*sizeof(int*)); 
    for (int i=0; i<n+1; i++) 
         arr[i] = (int *)malloc((n+1) * sizeof(int)); 
    for(int i = 0;i<=n;i++)
	{
		for(int j =0 ;j<n+1;j++)
			{arr[i][j] = 0;}}
	for(int i = 0;i<m;i++)
	{
		int preim,im;
		scanf("%d %d",&preim,&im);
		arr[preim][im] = 1;
	}
	//for(int i = 1;i<=n;i++){
	//	printf("\n");
	//	for(int j = 1;j<=n;j++){
	//		printf("%d",arr[i][j]);}
	//}
	int isreflexive = 1;
	int issymmetric = 1;
	int istransitive = 1;

	for(int  i =1;i<=n;i++)
	{
		if(arr[i][i] != 1)
			{isreflexive = 0;break;}
		}
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
		{
			if(arr[i][j] == 1 && arr[j][i] != 1)
			{ issymmetric = 0;break;}
			}

	int **mats = (int **)malloc(sizeof(int*)*(n+1));
	for(int i =0;i<n+1;i++)
	{
		mats[i] = malloc(sizeof(int)*(n+1));
	}
	matsq(arr,mats,n);
	printf("\n");
	//for(int i = 1;i<=n;i++){
	//	printf("\n");
	//	for(int j = 1;j<=n;j++){
	//		printf("%d",mats[i][j]);}
	//}
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
		{
			if(mats[i][j] != 0 && arr[i][j] == 0)
			{ istransitive = 0;break;}
			}
	if(isreflexive == 1)
	{
		printf("Reflexive\n");
	}
	if(issymmetric == 1)
	{
		printf("Symmetric\n");
	}
	if(istransitive == 1)
	{
		printf("Transitive\n");
	}
	if(istransitive == 1 && issymmetric == 1 && istransitive == 1)
	{
		printf("Equivalence\n");
	}
	if(istransitive == 0 && issymmetric == 0&& istransitive == 0)
	{
		printf("-1\n");
	}
}
