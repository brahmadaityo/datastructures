#include <stdio.h>

void insert(int *h, int *r, int v);
void delete(int *h, int *r);
void display(int *h,int s);

int main()
{
	int Heap[30];
	int ch=5,rear=0,size=0,val;
	while(ch!=4)
	{
		printf("\n\n");
		printf("1.) Insert elements into the Heap Tree\n");
		printf("2.) Delete element from the Heap Tree\n");
		printf("3.) Display the elements of the Tree\n");
		printf("4.) Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d",&val);
				if(size>30)
				{
					printf("Array Overflow !!\n");
					continue;
				}
				insert(Heap,&rear,val);
				size++;
				break;
			case 2:
				if(rear<1)
				{
					printf("ERROR !! The tree is empty.\n");
					continue;
				}
				delete(Heap,&rear);
				break;
			case 3:
				display(Heap,size);
				break;
			case 4:
				break;
		}
	}
	return 0;
}

void insert(int *h, int *r, int v)
{
	h[++(*r)]=v;
	int p=(*r)/2,c=*r;
	int temp=0;
	while(p>=1)
	{
		if(h[c]>h[p])
		{
			temp=h[c];
			h[c]=h[p];
			h[p]=temp;
		}
		c=p;
		p=(p)/2;
	}
	printf("%d has been inserted.\n",v);
}

void delete(int *h, int *r)
{
	int temp=h[1];
	h[1]=h[*r];
	h[*r]=temp;
	(*r)--;
	int p=1,c=2*p;
	while(p<=(*r)/2)
	{
		if(h[c]>h[p])
		{
			temp=h[c];
			h[c]=h[p];
			h[p]=temp;
			c=2*p;
		}
		if(h[(2*p)+1]>h[p])
		{
			c=2*p+1;
			if(c>*r)
				break;
			temp=h[c];
			h[c]=h[p];
			h[p]=temp;
		}
		p=c;
		c=2*p;
	}
	printf("%d has been deleted.\n",h[(*r)+1]);
}

void display(int *h,int s)
{
	int i;
	printf("Current Array :  ");
	for(i=1;i<=s;i++)
	{
		printf("%d\t",h[i]);
	}
	printf("\n");
}
