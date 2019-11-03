#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct tree{
	int data;
	struct tree *left,*right,*parent;
}tree;

tree *search(tree *t,int key)
{
	tree *temp;
	while(t)
	{
		
	}
}
void insert(tree **t,int key,tree *parent)
{
	tree *temp = (tree*)malloc(sizeof(tree));
	temp->data = key;
	temp->left = temp->right = NULL;
	temp->parent = parent;
	if ((*t) == NULL)
	{
	(*t) = temp;
	return;	 
	}
	else if ((*t)->data < key)
	{
	return insert(&((*t)->right),key,*t);
	}
	else
	{
		return insert(&((*t)->left),key,(*t));
	}
}
void deletenode(tree *t,int key)
{
tree *target = search(t,key);

else
{
	
	
	
}


}
void inorder(tree *t)
{
	if(t != NULL)
	{
		inorder(t->left);
		printf(" %d ",t->data);
		inorder(t->right);
	}
	return;
}
void preorder(tree *t)
{
	if(t != NULL)
	{
		printf(" %d ",t->data);
		inorder(t->left);
		inorder(t->right);
	}
	return;
}
void postorder(tree *t)
{
	if(t != NULL)
	{
		inorder(t->left);
		inorder(t->right);
		printf(" %d ",t->data);
	}
	return;	
}






int main()
{
tree *t = NULL,*parent = NULL;
char buff[500];
int x;
int w = 3,flag = 1;
while(flag)
{
	printf("\nenter 1/2/3/4/5/6 for insertion,deletion,inorder,preorder,postorder,exit\n");
	scanf("%d",&w);
	switch(w)
	{
		
	case 1:
		printf("enter  your data\n");
		scanf("%d",&x);
		insert(&t,x,parent);
		break;
	/*case 2:
		printf("enter  your data for deletion\n");
		gets(buff);
		deletetion(&t,buff);
		break;*/
	case 3:
		printf("the inorder traversal is\n");
		inorder(t);
		break;
	case 4:
		printf("the preorder traversal is \n");
		preorder(t);
		break;
	case 5:
		printf("the postorder traversal  is\n");
		postorder(t);
		break;
	case 6:
		printf("exitting successfully\n");
		exit(0);
	}
}
return 0;
}










