#include<stdio.h>
#include<stdlib.h>
#define max 100
void push(int *arr,int *top,int val)
{
if(*top == max){
	printf("your array containing the stack is full\n");
	return;
	}
else {
	*top = (*top)+1;
	arr[*top]=val;
	return;
	}
}
int pop(int *arr,int *top)
{
int temp;
if( *top == -1){
printf("your queue is empty\n");
	}
else{
	temp = arr[*top];
	(*top) = (*top)-1;
	return temp;
	}
}
void display(int *arr,int top)
{
int i=top;
while(i >= 0)
{
printf("| %d |  ",arr[i]);
i--;
}
}
void quepop(int *stack1,int *top1,int *stack2,int *top2)
{
int temp;
while(*top1 > -1)
{
push(stack2,top2,pop(stack1,top1));
}
temp = pop(stack2,top2);
while(*top2 > -1)
{
push(stack1,top1,pop(stack2,top2));
}
printf("the popped element from the queue is %d\n",temp);
}
int main()
{
int stack1[max],i,stack2[max];
int top1=-1,top2=-1,flag =1,val;
while(flag)
{
printf("enter 1/2/3 for push pop,display or 4 for exit\n");
scanf("%d",&i);
	switch(i)
		{
		case 1:{
			printf("enter the data\n");
			scanf("%d",&val);
			push(stack1,&top1,val);
			break;
		} 
		case 2: quepop(stack1,&top1,stack2,&top2);break;
		case 3: display(stack1,top1);break;
		case 4: flag =0;break;
		}
}
return 0;

}












