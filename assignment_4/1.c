#include <stdio.h>
#include <stdlib.h>

struct Tree
{
	int data;
	struct Tree *lc,*rc;
};
typedef struct Tree BST;

void insert(BST **r,int val);
void preorder(BST *r);
void inorder(BST *r);
void postorder(BST *r);
int delete(BST **r,int target);

int main()
{
	int num,i=0,ch=0;
	BST *root=NULL;
	while(ch!=6)
	{
		printf("\n\n");
		printf("1. Enter elements into the Binary Search Tree.\n");
		printf("2. Delete elements from the Binary Search Tree.\n");
		printf("3. Inorder Traversal.\n");
		printf("4. Preorder Traversal.\n");
		printf("5. Postorder Traversal.\n");
		printf("6. Exit.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be inserted.\n");
				scanf("%d",&num);
				insert(&root,num);
				break;
			case 2:
				printf("Enter the value to be deleted.\n");
				scanf("%d",&num);
				if(root==NULL)
				{
					printf("Tree is empty.\n");
					continue;
				}
				delete(&root,num);
				break;
			case 3:
				printf("INORDER TRAVERSAL : \n");
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("PREORDER TRAVERSAL : \n");
				preorder(root);
				printf("\n");
				break;
			case 5:
				printf("POSTORDER TRAVERSAL : \n");
				postorder(root);
				printf("\n");				
				break;
			case 6:
				printf("Thank You.\n");
				break;

		}
	}
	return 0;
}

void insert(BST **r,int val)
{
	if((*r)==NULL)
	{
		*r=(BST*)malloc(sizeof(BST));
		(*r)->data=val;
		(*r)->lc=(*r)->rc=NULL;
		return;
	}
	if((*r)->data>val)
	{
		insert(&((*r)->lc),val);
	}
	else if((*r)->data<val)
	{
		insert(&((*r)->rc),val);
	}
	else
		printf("Error. DUPLICATE ELEMENT. Cant insert %d. \n",val);
}
void inorder(BST *r)
{
	if(r==NULL)
	{
		printf("Tree is empty.\n");
		return;
	}
	else
	{
		if(r->lc!=NULL)
			inorder(r->lc);
		printf("%d\t",r->data);
		if(r->rc!=NULL)
			inorder(r->rc);
	}
}
void preorder(BST *r)
{
	if(r==NULL)
	{
		printf("Tree is empty.\n");
		return;
	}
	else
	{
		printf("%d\t",r->data);
		if(r->lc!=NULL)
			preorder(r->lc);
		if(r->rc!=NULL)
			preorder(r->rc);
	}
}
void postorder(BST *r)
{
	if(r==NULL)
	{
		printf("Tree is empty.\n");
		return;
	}
	else
	{
		if(r->lc!=NULL)
			postorder(r->lc);
		if(r->rc!=NULL)
			postorder(r->rc);
		printf("%d\t",r->data);
	}
}
int delete(BST **h,int target)
{
	int del;
	BST *p,*t;
	p=t=*h;
	while(t->data!=target)
	{
		p=t;
		if(target<t->data)
		{	
			if(t->lc==NULL)
				break;
			t=t->lc;
		}
		else if(target>t->data)
		{
			if(t->rc==NULL)
				break;
			t=t->rc;
		}
	}
	if(t->data!=target)
	{
		printf("ERROR. Node not found.\n");
		return -1;
	}
	if(p==t)
	{
		if(p->lc!=NULL)
		{
			del=p->data;
			p->data=p->lc->data;
			p->lc->data=del;
			t=p->lc;
		}
		else if(p->rc!=NULL)
		{
			del=p->data;
			p->data=p->rc->data;
			p->rc->data=del;
			t=p->rc;
		}
		else
		{
			*h=NULL;
			del=p->data;
			printf("%d has been deleted.\n",del);
			free(p);
			return del;
		}
	}
	if(t->lc!=NULL && t->rc!=NULL)
	{
		BST *ip=t->lc;
		p=t;
		while(ip->rc!=NULL)
		{
			p=ip;
			ip=(ip)->rc;
		}
		del=t->data;
		t->data=(ip)->data;
		t=ip;
		t->data=del;
	}
	if(t->lc==NULL&&t->rc==NULL)
	{
		if(p->lc==t)
			p->lc=NULL;
		else
			p->rc=NULL;
		printf("%d has been deleted.\n",t->data);
		free(t);
	}
	if(t->lc!=NULL&&t->rc==NULL)
	{
		if(p->lc==t)
			p->lc=t->lc;
		else
			p->rc=t->lc;
		printf("%d has been deleted.\n",t->data);
		free(t);
	}
	if(t->lc==NULL&&t->rc!=NULL)
	{
		if(p->lc==t)
			p->lc=t->rc;
		else
			p->rc=t->rc;
		printf("%d has been deleted.\n",t->data);
		free(t);
	}
	return t->data;
}
