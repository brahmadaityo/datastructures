#include<stdio.h>
#incluide<stdlib.h>
#include<string.h>
#include<math.h>
void insert(int *tree,int *index,int *left,int *right)
{
	int data,m = (*index),n,t,l,r;
	printf("enter your data\n");
	scanf("%d",&data);
n	tree[m]= data; //inserting the data
	left[m] = -1;
	right[m] = -1;
	/* 1)visit the root
	2)if lchild is null insert there(update the left index of data[0])
	3)if its not null then move to the left child and compare the value
	4)if lchild data is greater than inserted data and left child is NULL,if not null then compare and do it again,push there;
	5)if lchild data is lesser than data ,then insert into right,if right is not not NULL,then carry on and move
	*/
	t = 0;
	if(tree[t] > data )
	{
		if (left[t] == -1)
		{
		left[t] = (*index);
		}
		else
		{
		while( left[t] != -1 || right[t] != -1)
		{
			
		}
		}
		
	}
}
