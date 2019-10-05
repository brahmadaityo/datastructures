#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<iostream>
//using namespace std;
#define max 500
typedef struct {
char name[20];
char roll[10];
float cgpa;
char dept[20];
int sem;
}student;

typedef struct que{
student q[max];
int front;
int rear;
int count;
}que;
/////////////
void swap(student *a,student *b)
{
student c;

c.cgpa = a->cgpa;
strcpy(c.dept,a->dept);
strcpy(c.name,a->name);
strcpy(c.roll,a->roll);
c.sem = a->sem;
a->cgpa = b->cgpa;
strcpy(a->dept,b->dept);
strcpy(a->name,b->name);
strcpy(a->roll,b->roll);
a->sem = b->sem;
b->cgpa = c.cgpa;
strcpy(b->dept,c.dept);
strcpy(b->name,c.name);
strcpy(b->roll,c.roll);
b->sem = c.sem;

}

void push(que *a)
{
int i,j;
char temp[20];
if(a->count == max)
{
printf("queue is full\n");
return;
}
(a->rear)=((a->rear)+1)%max;
printf("enter the name of the student\n");
getchar();
fgets(temp,20,stdin);
strcpy(a->q[a->rear].name,temp);
printf("enter the roll of the student\n");
fgets(temp,20,stdin);
strcpy(a->q[a->rear].roll,temp);
printf("enter the department of the student\n");
fgets(temp,20,stdin);
strcpy(a->q[a->rear].dept,temp);
printf("enter the cgpa of the student\n");
scanf("%f",&a->q[a->rear].cgpa);
printf("enter the semester of the student\n");
scanf("%d",&a->q[a->rear].sem);
for(i=0; i< max-1;i++)
{
for (j=i+1;j<max;j++)
{
if(a->q[i].cgpa < a->q[j].cgpa)
	swap( &(a->q[i]), &(a->q[j]));
}
}
/*(a->rear)=((a->rear)+1)%max;
a->q[a->rear]=data;*/
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
printf("the student popped is :\n");
printf("name = %s\n",a->q[a->front].name);
printf("roll = %s\n",a->q[a->front].roll);
printf("dept = %s\n",a->q[a->front].dept);
printf("sem = %d\n",a->q[a->front].sem);
printf("cgpa = %f\n",a->q[a->front].cgpa);
 //a->q[a->front];
(a->front)=((a->front)+1)%max;
//printf("the popped element is %d\n",temp);
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
printf("\n__________________________________\n");
printf("student no. %d\n",c+1);
printf("%d semester \n",a->q[i].sem);
printf("name = %s\n",a->q[i].name);
printf("roll = %s\n",a->q[i].roll);
printf("depertment of %s\n",a->q[i].dept);
printf("cgpa = %1.2f\n",a->q[i].cgpa);
printf("\n__________________________________\n");
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













