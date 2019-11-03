#include <stdio.h>
#include <stdlib.h>

void insert(int *a, int *left, int *right, int *c, int val);
void display(int *a,int *left,int *right, int c);
void inorder(int *a, int *left, int *right);
void push(int *arr, int *t, int val);
void pop(int *arr, int *t);

int main()
{
	int arr[30],count=-1,LC[30],RC[30],i,ch=5,num;
	for(i=0;i<30;i++)
	{
		LC[i]=-1;
		RC[i]=-1;
	}
	while(ch!=4)
	{
		printf("\n");
		printf("1.) Enter elements into the array\n");
		printf("2.) Display the three arrays\n");
		printf("3.) Display INORDER Traversal using stack\n");
		printf("4.) Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d",&num);
				if(count<30)
					insert(arr,LC,RC,&count,num);
				else
					printf("Array Overflow !!");
				break;
			case 2:
				display(arr,LC,RC,count);
				break;
			case 3:
				printf("INORDER traversal : ");
				inorder(arr,LC,RC);
				printf("\n");
				break; 
			case 4:
				break;
		}
	}
	return 0;
}

void insert(int *a, int *left, int *right, int *c, int val)
{
	a[++(*c)]=val;
	left[*c]=right[*c]=-1;
	if(*c==0)
	{
		printf("%d has been inserted.\n",val);
		return;
	}
	int i=0,gr=0,ls=0;
	while(1)
	{
		if(val>a[i])
		{
			if(right[i]==-1)
			{
				right[i]=*c;
				break;
			}
			i=right[i];
		}
		else if(val<a[i])
		{
			if(left[i]==-1)
			{
				left[i]=*c;
				break;
			}
			i=left[i];
		}
		else
		{
			printf("ERROR !! Duplicate element %d detected.\n",val);
			return;
		}		
	}
	printf("%d has been inserted.\n",val);
}

void display(int *a, int *left, int *right, int c)
{
	int i=0;
	printf("Root Array :\t\t");
	for(i=0;i<=c;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nLeft Child Array :\t");
	for(i=0;i<=c;i++)
	{
		printf("%d\t",left[i]);
	}
	printf("\nRight Child Array :\t");
	for(i=0;i<=c;i++)
	{
		printf("%d\t",right[i]);
	}
	printf("\n");
}

void inorder(int *a, int *left, int *right)
{
	int stack[30],top=-1;
	int c=0,i=0,w=0;
	int flag=1;
	if(a[0]!=-1)
	{
		push(stack,&top,0);
		c=left[0];
	}
	while(top!=-1)
	{	
		while(c!=-1)
		{
			if(flag==0)
				c=left[stack[top]];
			push(stack,&top,c);
			c=left[stack[top]];
		}
		printf("%d\t",a[stack[top]]);
		c=right[stack[top]];
		pop(stack,&top);
		flag=1;
		if(c!=-1)
		{
			flag=0;
			push(stack,&top,c);
		}
	}

}
void push(int *arr, int *t, int val)
{
	arr[++(*t)]=val;
}
void pop(int *arr, int *t)
{
	int r=arr[(*t)--];
}

/*void inorders(int a[],int b[],int c[],int s[],int t,int p,int c1)
{
	
	if(b[p]!=-1)
		inorder(a,b,c,s,t,b[p],c1);
	t++;
	s[t]=a[p];
	printf("%d  ",s[t]);
	if(t==c1-1)
	{
	   
	    for(int i=t;i>=0;i--)
	        printf("%d  ",s[i]);
	}
	if(c[p]!=-1)
	{
		inorder(a,b,c,s,t,c[p],c1);
	}
}*/
