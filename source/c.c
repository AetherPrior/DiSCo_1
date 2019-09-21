#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
 char code[100000+1];
 char code2[100000+1];
 scanf("%s",code);
 char repcode[27];
 for(int i = 0;i<26;i++)
 {
	repcode[i] = 0;
	}
 repcode[26] = '\0';
 int num;
 char temp;
 scanf("%d",&num);
 scanf("%c",&temp);
 char c,ch;
 for(int i = 0;i<num;i++)
 {
 	
 	c = getchar_unlocked();
	temp = getchar_unlocked();
 	ch = getchar_unlocked();
	temp = getchar_unlocked();
	//printf("%c %c\n",c,ch); 
	repcode[c-97] = ch;
 }
 //printf("%s\n",repcode);
 int flag = 1;
 strcpy(code2,code);
 while(flag != 0)
 {
	flag = 0;
	for(int i = 0; i<strlen(code2);i++)
	{
		c = code2[i];
		if(repcode[c-97] != 0)
		{ 
		code2[i] = repcode[c-97];
		 flag = 1;}
	} 
 }
 printf("%s",code2);
}
