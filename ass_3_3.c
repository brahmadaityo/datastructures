#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linkedlist{
	int data;
	struct linkedlist *prev;
	struct linkedlist *next;
}ll;
void insert(ll **head);
void display(ll *head);
void delete(ll **head);
int main()
{
ll *head;
int flag=1,k;
while(flag)
{
printf("enter 1/2/3/4 for insert delete display exit\n");
scanf("%d",&k);
switch(k)
	{
		case 1: insert(&head);break;
		case 2: delete(&head);break;
		case 3: display(head);break;
		case 4: flag=0;break;
	}
}		
return 0;
}

ll *newnode()
{
ll *temp =(ll*)malloc(sizeof(ll));
temp->prev = NULL;
temp->next = NULL;
return temp;
}

void insert(ll **head)
{
ll *temp,*last,*curr;
int val;
if(*head == NULL)
{
printf("enter your data please\n");
scanf("%d",&val);
temp = newnode(); 
temp->data = val;
*head = temp;
temp->next = (*head);
temp->prev = (*head);

return;
}
else {
	last = (*head)->prev;
	temp = newnode();
	printf("enter you data\n");
	scanf("%d",&val);
	temp->data=val;
	temp->prev = last;
	last->next = temp;
	temp->next = (*head);
	(*head)->prev = temp;
 	}
return;
}
void display(ll *head)
{
	int count=0;
	ll *curr = head;
	while(curr->next != head)
	{
		printf("%d\n",curr->data);
		count++;
		curr = curr->next;
		
	}
	printf("%d",(curr)->data);
	count++;
	printf("the count of nodes are %d\n",count);
	return;
}
void delete(ll **head)
{
	int target;
	ll *curr1,*curr2,*temp;
	if(*head==NULL){printf("no data to delete\n");return;}
	printf("enter your target value\n");
	scanf("%d",&target);
	temp = *head;
	while(temp->data != target)
	{
		temp = temp->next;
	} 
	curr1 = temp->next;
	curr2 = temp->prev;
	curr1->next = curr2;
	curr2->prev = curr1;
	free(temp);
	return;
}
