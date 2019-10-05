#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linkedlist{
	int data;
	struct linkedlist *next;
	struct linkedlist *prev;
}LL;

void insertend(LL **list,int k)
{
	LL *last,*temp;
	temp = (LL* )malloc(sizeof(LL));
	temp->data = k;
	temp->next = temp;
	temp->prev = temp;	
	if(*list == NULL){
		*list = temp;
		return;
	}
	else
	{
		last = (*list)->prev;
		last->next = temp;
		temp->prev = last;
		temp->next = *list;
		(*list)->prev = temp;
		return;	
	}
	
}
void insertbegin(LL **list,int k)
{
	LL *temp,*last;
	temp = (LL*)malloc(sizeof(LL));
	temp->data= k;
	temp->next = temp;
	temp->prev = temp;
	if(*list == NULL)
	{
		*list = temp;
	}
	else
	{
	last = (*list)->prev;
	temp->next = *list;
	temp->prev = last;
	(*list)->prev= temp;
	last->next = temp;
	*list = temp;
	}
}
void deletefront(LL **list)
{
if (*list == NULL)
{
	printf("empty list nothing to delete \n");
	return;
}
int k;
LL *last=(*list)->prev;
k = (*list)->data;
last->next = (*list)->next;
((*list)->next)->prev = last;
(*list) = (*list)->next;
printf("deleted element was %d\n",k);
return;	
}
void deleteend(LL **list)
{
	int k;
	LL *last,*prev_1= NULL;
	if (*list = NULL){
		printf("no data to delete\n");
		return;
	}
	else
	{
		last = (*list)->prev;
		prev_1 = last->prev;
		k = last->data;
		(prev_1)->next = (*list);
		(*list)->prev = (prev_1);
		printf("the deleted element is %d",k);
		return;
	}
	
		
}
void display(LL *list)
{
	LL *temp;
	temp = list;
	while(temp->next != list)
	{
		printf("|%d|<--> ",temp->data);
		temp= temp->next;
	}
	printf("|%d|<--> ",temp->data);
	printf("\n\n");
	return;
}
int main()
{
	int flag=1,data,choice;
	LL *head = NULL;
	while(flag)
	{
		printf("insert at front(1)/rear(2)/target(3)\ndelete from front(4)/rear(5)/target(6) or display(7) \nexit(8)\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data \n");
					scanf("%d",&data);
					insertbegin(&head,data);
					break;
			case 2: printf("enter the data \n");
					scanf("%d",&data);
					insertend(&head,data);
					break;
			/*case 3: printf("enter the data \n");
					scanf("%d",&data);
					insertafter(&head,data);
					display(head);
					break;*/
			case 4: deletefront(&head);
					break;
			case 5 : deleteend(&head);
					break;
			case 7 : display(head);break;
			case 8 : flag =0;
		
		}
	}
	return 0;
}







