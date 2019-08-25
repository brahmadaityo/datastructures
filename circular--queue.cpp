#include<stdio.h>
#include<stdlib.h>
#define max 3
typedef struct que{
int q[max];
int front;
int rear;
int count;
}que;

void push(que *a)
{
int data;
if(a->count == max)
{
printf("queue is full\n");
return;
}
printf("enter your data\n");
scanf("%d",&data);
(a->rear)=((a->rear)+1)%max;
a->q[a->rear]=data;
(a->count)++;
return;
}
/////////////////////
void pop(que *a)
{
int temp;
if(a->count == 0)
{
printf("your queue is empty"); 
return;
}
else{
temp = a->q[a->front];
(a->front)=((a->front)+1)%max;
printf("the popped element is %d\n",temp);
(a->count)--;
return;
}
}
void display(que *a)
{
int i;
int c;
for(i=a->front,c=0;c < a->count;c++,i=(i+1)%max)
{
printf("|%d|",a->q[i]);
}
return;
}
int main()
{
int c;
int flag=1;
que a;
a.front = 0;
a.rear = -1;
a.count=0;
int t=50;

while(flag)
{
printf("\nenter 1/2/3/4 for push,pop,display,exit\n");
scanf("%d",&c);//////////
if(c == 1 )
	push(&a);
if(c==2)
	pop(&a);
if( c==3 )
	display(&a);
if(c==4)
	flag=0;
}
}













