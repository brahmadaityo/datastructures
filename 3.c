#include<stdio.h>
#include<time.h>
int main()
{
int i,j,k,m,n,;
int mat[100][100],rmax[100],rmin[100],rmean[100],cmax[100],cmin[100],rmean[100];
srand(time(0));
printf("enter the values of m,n,p\n");
scanf("%d %d %d",&m,&n,&p);
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		mat1[i][j][k]= (rand())%100; ///filling up the matrices
		mat2[i][j][k]= (rand())%100;
	}
	
}
printf("the first matrix is \n");
print(mat1,m,n,p);
printf("the second matrix is \n");
print(mat2,m,n,p);
printf("the added matrix is \n");
add(mat1,mat2,mat3,m,n,p);

}

