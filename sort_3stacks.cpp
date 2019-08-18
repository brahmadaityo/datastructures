#include<stdio.h>
#include<stdlib.h>
#define max_size 1000
void push(int *arr,int val,int *top )
{
if(*top == max_size-1){
	printf("your array containing the stack is full\n");
	return;
	}
else {
	(*top)++;
	arr[*top]=val;
	return;
	}
}
int pop(int *arr,int *top)
{
int temp;
	temp = arr[*top];
	(*top)--;
	return temp;
	
}
void display(int *arr,int top)
{
int i;
for(i = top ;i >0 ;i--);
{
printf("| %d |\n",arr[i]);
}
}



int top(int *s,int t)
{
return s[t];
}

void sort(int *s1,int *s2,int *s3,int *top1,int *top2,int *top3)
{
while(*top1 > -1)
{
push(s3,pop(s1,top1),top3);
while(top(s2,*top2)>top(s3,*top3) && *top2>-1)
{
push(s1,pop(s2,top2),top1);
}
push(s2,pop(s3,top3),top2);
}
return;
}
int main()
{
//int stack1[max_size],stack2[max_size],stack3[max_size];
int i,j,top1=-1,top2=-1,top3=-1;
int stack1[max_size];
int stack2[max_size];
int stack3[max_size];
int n;
int flag =1;
while(flag)
{
printf("press 1/2/3/4 for stack 1,stack2,stack3 & complete\n");
scanf("%d",&n);
switch(n)
{
 	case 1:printf("enter your input in stack 1\n");
 		   scanf("%d",&i);
 		   push(stack1,i,&top1);
 		   break;
 	case 2:printf("enter your input in stack 2\n");
 		   scanf("%d",&i);
 		   push(stack2,i,&top2);
 		   break;
 	case 3:printf("enter your input in stack 3\n");
 		   scanf("%d",&i);
 		   push(stack3,i,&top3);
 		   break;
 	case 4: flag = 0;break;
}
}
while(top2 > -1 || top3 > -1)
{
push(stack1,pop(stack2,&top2),&top1);
push(stack1,pop(stack3,&top3),&top1);
}
sort(stack1,stack2,stack3,&top1,&top2,&top3);
while(top2>-1)
{
printf("|%d|\n",pop(stack2,&top2));
}

}

