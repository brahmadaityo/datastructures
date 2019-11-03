#include <stdio.h>
#include <stdlib.h>

typedef struct ternary
{
	int d1,d2;
	struct ternary *l,*m,*r;
}Ttree;

void insert(Ttree **R,int val);
void inorder(Ttree *R);

int main()
{
	int ch=4,num;
	Ttree *R=NULL;
	while(ch!=3)
	{
		printf("\n");
		printf("1.) Enter elements into the tree\n");
		printf("2.) Display INORDER Traversal\n");
		printf("3.) Exit.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d",&num);
				insert(&R,num);
				break;
			case 2:
				printf("INORDER Traversal : ");
				inorder(R);
				printf("\n");
				break;
			case 3:
				break;
			default:
				printf("Invalid Input. Please Try again.\n");
		}
	}
	return 0;
}

void insert(Ttree **R,int val)
{
	if (*R==NULL)
	{
		(*R)=(Ttree*)malloc(sizeof(Ttree));
		(*R)->d1=val;
		(*R)->d2=-1;
		(*R)->l=NULL;
		(*R)->m=NULL;
		(*R)->r=NULL;
		return;
	}
	if((*R)->d2==-1)
	{
		if(val>((*R)->d1))
		{
			(*R)->d2=val;
			return;
		}
		else
		{
			(*R)->d2=(*R)->d1;
			(*R)->d1=val;
			return;
		}
	}
	else
	{
		if(val<((*R)->d1))
			insert(&((*R)->l),val);
		else if(val>((*R)->d1) && val<((*R)->d2))
			insert(&((*R)->m),val);
		else if(val>((*R)->d2))
			insert(&((*R)->r),val);
		else
			printf("ERROR !! Duplicate input detected.\n");
	}

}

void inorder(Ttree *R)
{
	if(R==NULL)
	{
		printf("The ternary tree is empty.\n");
		return;
	}
	else
	{
		if(R->l!=NULL)
			inorder(R->l);
		if(R->d1!=-1)
			printf("%d\t",R->d1);
		if(R->m!=NULL)
			inorder(R->m);
		if(R->d2!=-1)
			printf("%d\t",R->d2);
		if(R->r!=NULL)
			inorder(R->r);
	}
}
