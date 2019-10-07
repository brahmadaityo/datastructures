#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct linkedlist{
	char data[50];
	struct linkedlist *next;
	struct linkedlist *prev;
}LL;
//doubly linked list using cmd line
void insert(LL **list,char *str)
{
	LL *temp,*prev2 = NULL,*temp2=NULL;
	temp = (LL*)malloc(sizeof(LL));
	strcpy(temp->data,str);
	if(*list == NULL)//crete function
	{
		temp->next = NULL;
		temp->prev = NULL;
		*list = temp ;
		return; 
	}
	else if(strcmp((*list)->data,str) >= 0)// if the data at head poinetr is biggeer insertion before head
	{
		//printf("gfyf\n");
		temp->prev = NULL;
		temp->next = (*list);
		(*list)->prev = temp;
		(*list)= temp;
		//(*list)=(*list)->prev;
		//insertfront(list,str);
		return;
	}
	else
	{
	temp2 = (*list);
	while((temp2 != NULL) && (strcmp(temp2->data,str)<=0))
	{
	prev2 = temp2;
	temp2 = temp2->next;	
	}
	if(temp2 == NULL)//insertion at last
	{
	temp->next = NULL;
	prev2->next = temp;
	temp->prev = prev2;
	return;
	}
	temp->next = temp2;
	temp->prev = prev2;
	prev2->next = temp;
	temp->next->prev = temp; 
	//printf("data in prev next and mid node is %s\t%s\t%s\n",prev2->data,temp2->data,prev2->next->data);
	return;
	}
	
}
void display(LL *list)
{
LL *temp = (list);
while(temp != NULL )
{
	printf("|%s|<-->",temp->data);
	temp = temp->next;
}	
printf("|%s|",temp->data);
printf("\n\n");	
}
int main(int argc, char*argv[])
{
	LL *head = NULL;
	char str[50];
	int i;
	for(i=1;i<argc;i++)
	{
		insert(&head,argv[i]);
		display(head);
	}
	return 0;
}
