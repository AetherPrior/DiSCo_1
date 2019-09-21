#include<stdio.h>
#include<stdbool.h>
#define NUM_COURSES 10
//#define true 1
//#define false 0
//typedef unsigned char bool;
bool isfilled[10];
struct stack
{
	int arr[NUM_COURSES];
	int front,rear;
}s1;

void init(struct stack *s1)
{
	for(int i =0;i<10;i++)
	{
		s1->arr[i] = -1;
	}
	s1->front = s1->rear = -1;
}
int push(struct stack *s1, int elt, int max)
{
	if(s1->front == -1 && s1->rear == -1)
	{
		s1->front = s1->rear = 0;
	}
	if(s1->rear == max)
		return -1;
	else
	  s1->arr[s1->rear++] = elt;			
}
int pop(struct stack *s1)
{
	if((s1->front  == -1 && s1->rear == -1) || s1->front > s1->rear)
		return -1;
	else{
		int temp = s1->front;
		s1->front++;
		return s1->arr[temp];
		}
}

int courseID[10];

int topsort(int prereq[],int course[], int num, int num2,int elt)
{
		int elt2;
		//hunt the course index
		for(int i = 0; i< num;i++)
		{
			if(courseID[i] == elt)
				{elt2 = i;break;}
			}

		if(isfilled[elt2]) return -1;
		for(int i = 0;i<num2;i++)
		{
			if(course[i] == elt)
			{
				topsort(prereq,course,num,num,prereq[i]);
			}
		}
		//if not available
		if(!isfilled[elt2])
		{
			isfilled[elt2] = true;
			push(&s1,courseID[elt2],num);
		} 	
	
} 

int main(void)
{

	
	int num;
	scanf("%d",&num);

	for(int i = 0;i<num;i++)
	{
		scanf("%d",&courseID[i]);
	}

	int num2;
	scanf("%d",&num2);	
	
	init(&s1);	
	int  prereq[num2], course[num2];
	
	for(int i=0;i<=10;i++)
	{
		isfilled[i] = false;
	}

	
	for(int i = 0;i<num2;i++)
	{
		scanf("%d",&prereq[i]);
		scanf("%d",&course[i]);
	}
	
	for(int  i =0; i<num;i++){
	topsort(prereq,course,num,num,courseID[i]);}
	
	int temp;	
	while(true)
	{
		temp = pop(&s1);
		if(temp == -1)
			break;
		printf("%d ",temp);
		
		}
	//perform a topological sort 
	
	return 0;
}
