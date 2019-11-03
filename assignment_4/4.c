#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct huffman_tree
{
	char ch[30];
	int freq;
	struct huffman_tree *lc,*rc;
};
typedef struct huffman_tree HFT;

struct linked_list
{
	char ch[30];
	int freq;
	struct linked_list *next;
};
typedef struct linked_list list;

void insert_list(list **h, char c[], int f);
void del_list(list *h, char c[]);
void display_list(list *h);
HFT *join_node(list *n1, list *n2);
void huffman(list **h, HFT **r);
void delete_list(list ***h, char c1[]);
void inorder(HFT *r);

int main()
{
	int ch=5,f;
	char c[30];

	list *head=NULL;
	HFT *root=NULL;
	while(ch!=4)
	{
		printf("\n\n");
		printf("1. Enter characters for encoding.\n");
		printf("2. Display the Huffman Tree (Inorder Traversal).\n");
		printf("3. Display the Huffman Code for the characters.\n");
		printf("4. EXIT.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the character to be entered.\n");
				scanf("%s",c);
				printf("Enter its frequency.\n");
				scanf("%d",&f);
				printf("%s is entering.\n",c);
				insert_list(&head,c,f);
				break;
			case 2:
				//display_list(head);
				huffman(&head,&root);
				break;
			case 3:
				printf("Inorder Traversal : ");
				inorder(root);
				printf("\n");
				break;
			case 4:
				break;
		}
	}
	return 0;
}

void insert_list(list **h, char c[], int f)
{
	if(*h==NULL)
	{
		*h=(list *)malloc(sizeof(list));
		strcpy((*h)->ch,c);
		(*h)->freq=f;
		(*h)->next=NULL;
		printf("%s has been entered.\n",c);
		return;
	}
	list *curr=*h;
	list *temp=(list *)malloc(sizeof(list));
	strcpy(temp->ch,c);
	temp->freq=f;
	temp->next=NULL;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=temp;
	printf("%s has been entered2.\n",c);
}

HFT *join_node(list *n1, list *n2)
{
	HFT *l=(HFT *)malloc(sizeof(HFT));
	HFT *r=(HFT *)malloc(sizeof(HFT));
	HFT *node=(HFT *)malloc(sizeof(HFT));
	node->ch[0]='I';
	node->ch[1]='N';

	node->freq=n1->freq+n2->freq;
	node->lc=l;
	node->rc=r;
	strcpy(l->ch,n1->ch);
	l->freq=n1->freq;
	l->lc=NULL;
	l->rc=NULL;
	strcpy(r->ch,n2->ch);
	r->freq=n2->freq;
	r->lc=NULL;
	r->rc=NULL;
	return node;
}

void huffman(list **h, HFT **r)
{


	if(*h==NULL)
	{
		return;
	}
	list *sm1,*sm2;
	list *curr,*temp,curr2;
	HFT *hcurr,*htemp,htemp2;
	if((*h)->next==NULL)
	{
		hcurr=(HFT *)malloc(sizeof(HFT));
		strcpy((*h)->ch,hcurr->ch);
		hcurr->freq=(*h)->freq;
		hcurr->lc=NULL;
		hcurr->rc=NULL;
		htemp=(HFT *)malloc(sizeof(HFT));
		htemp->lc=hcurr;
		htemp->rc=NULL;
		*r=htemp;
		free(*h);
		return;
	}
	if((*h)->next->next==NULL)
		curr=NULL;
	else
		curr=(*h)->next->next;
	sm1=*h;sm2=(*h)->next;
	while(curr!=NULL)
	{
		if(curr->freq>sm1->freq&&curr->freq<=sm2->freq)
			sm2=curr;
		if(curr->freq<=sm1->freq&&curr->freq<sm2->freq)
			sm1=curr;
		if(curr->freq<=sm1->freq&&curr->freq>sm2->freq)
			sm1=curr;
	}
	*r=join_node(sm1,sm2);
	char c1[30],c2[30];
	insert_list(&(*h), strcat(sm1->ch,sm2->ch), (sm1->freq+sm2->freq));
	strcpy(c1,(sm1)->ch);
	strcpy(c2,(sm2)->ch);
	delete_list(&(h),c1);
	delete_list(&(h),c2);
}

void delete_list(list ***h, char c1[])
{
	if(**h==NULL)
	{
		printf("ERROR while deletion of list.\n");
		return;
	}
	list *curr,*prev;
	curr=prev=**h;
	while(curr!=NULL)
	{
		if(strcmp(curr->ch,c1)==0)
			break;
		prev=curr;
		curr=curr->next;
	}
	if(prev==**h&&curr==**h)
	{
		**h=(**h)->next;
		free(curr);
		return;
	}
	if(curr!=NULL)
	{
		if(curr->next==NULL)
		{
			prev->next=NULL;
			free(curr);
			return;
		}
		prev->next=curr->next;
		free(curr);
		return;
	}
	else
		printf("ERROR while deletion. Node not found.\n");
}

void display_list(list *h)
{
	list *curr=h;
    while(curr!=NULL)
    {
    	printf("%s ----> ",curr->ch);
        curr=curr->next;
    }
    printf("||--");

}

void inorder(HFT *r)
{
	int stack[30],top=-1;
	if(r==NULL)
	{
		printf("Tree is empty.\n");
		return;
	}
	else
	{
		if(r->lc!=NULL)
		{
			inorder(r->lc);
		}
		printf("%s(%d)\t",r->ch,r->freq);
		if(r->rc!=NULL)
			inorder(r->rc);
	}
}
