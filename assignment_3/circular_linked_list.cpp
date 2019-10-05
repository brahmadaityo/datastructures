#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linkedlist{
	int data;
	struct linkedlist *next;
	struct linkedlist *prev;
}LL;
void insertend(LL **list,int k,int *count)
{
	LL *last,*temp;
	temp = (LL* )malloc(sizeof(LL));
	temp->data = k;
	temp->next = temp;
	temp->prev = temp;	
	if(*list == NULL){
		*list = temp;
		(*count)++;
		return;
	}
	else
	{
		last = (*list)->prev;
		last->next = temp;
		temp->prev = last;
		temp->next = *list;
		(*list)->prev = temp;
		(*count)++;
		return;	
	}
	
}

void insertbegin(LL **list,int k,int *count)
{
	LL *temp,*last;
	temp = (LL*)malloc(sizeof(LL));
	temp->data= k;
	temp->next = temp;
	temp->prev = temp;
	if(*list == NULL)
	{
		*list = temp;
		(*count)++;
	}
	else
	{
	last = (*list)->prev;
	temp->next = *list;
	temp->prev = last;
	(*list)->prev= temp;
	last->next = temp;
	*list = temp;
	(*count)++;
	return;
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
void deleteafter(LL **list,int element)
{
	LL *temp = (*list);
	if(temp->next == temp)
	{
		printf("your deleted data is %d",deletefront(list));
	}
	while(temp->next != (*list))
	{
		if(temp->data == element)
		{
		
		if(temp == (*list))
		{
		printf("your deleted element is %d\n",deletefront(list));	
		return;
		}
		else if(temp == (*list)->prev)
		{
		printf("your deleted element is %d\n",deleteend(list));
		return;
		}
		else
		{
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			printf("your deleted data is %d",temp->data);
			return;		
		}
		}
		else		
			temp = temp->next;	
	}
	printf("data not found\n");
	return;
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
	int flag=1,count=0,data,choice;
	LL *head = NULL;
	while(flag)
	{
		printf("insert at front(1)/rear(2)\ndelete(3)\n display(4) \nexit(5)\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data \n");
					scanf("%d",&data);
					insertbegin(&head,data,&count);
					printf("the count of nodes are %d",count);
					break;
			case 2: printf("enter the data \n");
					scanf("%d",&data);
					insertend(&head,data,&count);
					printf("the count of nodes are %d",count);
					break;
					
			case 3: printf("enter the data you wanna delete!!\n");
					scanf("%d",&data);
					deleteafter(&head,data);
					printf("the count of nodes are %d",count--);
					break;
			case 4 : {
				if (head == NULL)
					{
					printf("no element to display\n");
					}
				else 
					{
					display(head);
					}
				}break;
			case 5 : flag =0;
		
		}
	}
    printf("operation successfull\n");
	return 0;
}
