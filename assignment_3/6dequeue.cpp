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
int deletefront(LL **list)
{
int k;
if (*list == NULL)
{
	printf("empty list nothing to delete \n");
	return 0;
}
else if((*list)==(*list)->next)
{
k = (*list)->data;
(*list)= NULL;
printf("deleted element was %d\n",k);
return k;	
}
LL *last =(*list)->prev;
k = (*list)->data;
last->next = (*list)->next;
((*list)->next)->prev = last;
(*list) = (*list)->next;
printf("deleted element was %d\n",k);
return k;	
}
int deleteend(LL **list)
{
	int k;
	LL *last,*temp;
	if(*list == NULL)
	{
		printf("nothing to delete\n");
		return NULL;
	}
	else if ((*list) == (*list)->next){
		k = (*list)->data;
		*list = NULL;
		return k;
	}
	else
	{
		last = (*list)->prev;
		temp = (*list)->prev;
		k = last->data;
		//printf("\n%d and %d is the last and bef stage(1)\n",(last->data),temp->data);
		last = last->prev;
		last->next = temp->next;
		last->next->prev = last;
		free(temp);
		temp = NULL;
        return k;
        
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
	printf("|%d| ",temp->data);
	printf("\n\n");
	return;
}
int main()
{
	int flag=1,data,choice;
	LL *head = NULL;
	while(flag)
	{
		printf("insert at front(1)/rear(2)\ndelete from front(3)/rear(4)\n display(5) \nexit(6)\n\n");
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
			case 3: printf("your deleted data is %d\n\n",deletefront(&head));
					break;
			case 4:	printf("your deleted data is %d\n\n",deleteend(&head));
					break;
			case 5 : {
				if (head == NULL)
					{
					printf("no element to display\n");
					}
				else 
					{
					display(head);
					}
				}break;
			case 6 : flag =0;
		
		}
	}
    printf("operation successfull\n");
	return 0;
}
