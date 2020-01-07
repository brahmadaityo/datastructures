#include<stdio.h>
#include<time.h>
#define MAX(a,b) (a>b?a:b)
void print(int mat[100][100],int m,int n)
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}
int main()
{
int i,j,k,m,n,min,max;
float mean;
int mat[100][100],rmax[100],rowmin[100],rowmean[100],colmax[100],colmin[100],colmean[100];
srand(time(0));
printf("enter the values of m,n,p\n");
scanf("%d %d",&m,&n);
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		mat1[i][j]= (rand())%100; ///filling up the matrices
	}
	
}
printf("the matrix is \n");
print(mat,m,n);

}

