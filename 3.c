/*calculate row wise mean,max,min
calculate coloumn wise mean max min
of a random matrix with values 0-100*/
#include<stdio.h>
#include<time.h>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
int main()
{
	int i,j,max,min,amin,total,atotal,amax,m,n,mat[100][100],rmax[100],rmin[100],cmax[100],cmin[100]; 
	float rmean[100],cmean[100],amean;
	seed(time(0));
	printf("enter the values of the M and N\n");
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			mat[i][j] = (rand()%101) ; /*/filling up the random matrix*/
		}
	}
	printf("the matrix is \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",mat[i][j]);
			
		}
		printf("\n");
	}
	/*/////////row wise calculations/////////*/
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		max =-1;	
		total = 0;
		min = 99999;
		amax =-1;	
		atotal = 0;
		amin = 99999;
		total += mat[i][j];
		rmean[i] = total/m; 
		max = MAX(max,mat[i][j]);
		min = MIN(min,mat[i][j]);
		rmax[i]= max;
		rmean[i] = total/m;
		atotal += mat[i][j];
		amax = MAX(amax,mat[i][j]);
		amin = MIN(amin,mat[i][j]);
		}
	}
	amean = atotal/(m*n); 
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			total += mat[i][j];
			cmean[i] = total/n;
			max = MAX(max,mat[i][j]);
			min = MIN(min,mat[i][j]);
			cmax[j] = max;
			cmin[j] = min; 
		}
	}
	
	
	
}
