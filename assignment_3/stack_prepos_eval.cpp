#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct linkedlist{
	char data[50];
	struct linkedlist *next;
	struct linkedlist *prev;
}LL;
void display(LL *list)
{
LL *temp = (list);
//rintf("your inserted data is in now in a doubly linked list\n");
while(temp != NULL )
{
	printf("|%s|<-->",temp->data);
	temp = temp->next;
}	
printf("|%s|",temp->data);
printf("\n\n");	
}
void push(LL **list,char *str,LL **tail)
{
	LL *temp,*temp2=(*list);
	temp = (LL*)malloc(sizeof(LL));
	strcpy(temp->data,str);
	temp->next = NULL;
	temp->prev = NULL;
	if(*list == NULL)
	{
		*list = temp;
		*tail = temp;
		return;
	}
	else
	{
		while(temp2->next != NULL)
		{
			temp2=temp2->next;
		}
		//printf("hey you are at last and last is  %s\n",temp2->data);
		temp->prev=temp2;
		temp->next= NULL;
		temp2->next = temp;
		*tail = temp; 
		//printf("insertion done at last which is %s = %s = %s\n",temp2->next->data,(*tail)->data,temp->data);
		return;		
	}
}

void pop(LL **head,char *buff,LL**tail)
{
	LL *temp = (*tail);
	if(*tail == NULL)
	{
		strcpy(buff,"STACK IS EMPTY");	
		return;
	}
	else if ( (*head) == (*tail) != NULL)
	{
		strcpy(buff,temp->data);
		free(*head);
		free(*tail);
		*head = (*tail) = NULL;
		return;
	}
	strcpy(buff,temp->data);
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	free(temp);
	temp = NULL;
	printf("the stack is now\n");
	display(*head);
	return;
	
}

int main(int argc,char *argv[])
{
	LL *list=NULL,*tail = NULL,*stack=NULL,*top=NULL;
	int x,res,v1,v2;
	char num1[50],buffer[50],dummy[50],num2[50];
	for(int i=2;i<argc;i++)
	{
		push(&list,argv[i],&tail);
	}
	display(list);
	if(strcmp(argv[1],"postfix") == 0)
	{
		while(list != NULL)
		{
			//printf("loop enetry??\n");
			//printf("%s is the data of the first node\n",list->data);
			strcpy(dummy,list->data);
			if(isdigit(dummy[0]))
			{
				push(&stack,dummy,&top);
			}
			else
			{
				pop(&stack,num1,&top);
				pop(&stack,num2,&top);
				v1 = atoi(num1);
				//printf("The first numenr is  %s %d\n",num1,v1);
				v2 = atoi(num2);	
				//printf("The 2nd numenr is %s %d\n",num2,v2);
				switch(list->data[0])
				{
					case '*' : res = v1*v2;break;
					case '+' : res = v1 + v2;break;
					case '/' : res = v1/v2;break;
					case '-' : res = v1-v2;break;
					case '^' : res = (int)pow(v1,v2);break;
					case '%' : res = v1%v2;break;
				}
				//printf("%d is the result \n",res);
				push(&stack,itoa(res,buffer,10),&top);
				display(stack);
			}
			list = list->next;
			display(list);
		}
		pop(&stack,buffer,&top);
	}
	else if(strcmp(argv[1],"prefix") == 0)
	{
		while(tail != NULL)
		{
			if(isdigit(tail->data[0]))
			{
				push(&stack,tail->data,&top);
			}
			else
			{
				pop(&stack,num1,&top);
				pop(&stack,num2,&top);
				v1 = atoi(num1);
				v2 = atoi(num2);
				x = v1;
				v1 = v2;
				v2 = x;	
				switch(tail->data[0])
				{
					case '*' : res = v1*v2;break;
					case '+' : res = v1 + v2;break;
					case '/' : res = v1/v2;break;
					case '-' : res = v1-v2;break;
					case '^' : res = (int)pow(v1,v2);break;
					case '%' : res = v1%v2;break;
				}
				push(&stack,itoa(res,buffer,10),&top);
			}
			tail = tail->prev;
			display(list);
		}
		pop(&stack,buffer,&top);
	}
	
	printf("\n%s is the result\n",buffer);
	}











